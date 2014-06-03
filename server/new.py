#!/usr/bin/env python2

#Serwer

##@package Python
#Modul Pythona sluzacy do komunikacji miedzy klientem a serwerem.
#
#Modul ten dziala przy serwerze FastCGI. Za pomoca formatu JSON porozumiewa sie on z klientem i przetwarza jego zadania dla modelu gry. Po otrzymaniu odpowiedzi od modelu zwraca ja, odpowiednio sformatowana, do klienta.


import os
import sys
import json
import os
import model
import random

##Funkcja UpDate
#
#Jest uzywana przy przekazywaniu informacji dla wolania o aktualny stan gry.
#@param co nazwa wolanej funkcji
#@param auser przekazuje nazwe uzytkownika
def UpDate(co, auser=0):

	if co == "GetScore":
		return model.getScore(auser)
	if co == "GetState":
		return model.getState()
	if co == "getCurrentPlayer":
		return model.getCurrentPlayer()

##Funkcja App
#
#Glowna funckcja serwera. Przekazuje przychodzace od klienta zadania i wysyla zapytania do modelu. Komunikacja zostala zrealizowana za pomoca formatu JSON.
#@param environ slownik WSGI
#@param start_response callback do przesylania informacji
def App(environ, start_response):
	try:
		packet_leng = int(environ.get('CONTENT_LENGTH', 0))
	except (ValueError):
		packet_leng = 0
	""" Sprawdza pobierany pakiet """

#pobieramy caly pakiet
	packet = environ['wsgi.input'].read(packet_leng)
	##Odczyt pobranego od klienta pakietu do orders
	orders = json.loads(packet)

#dodac wybieranie z jsona informacji, obsluga modelu
	auser_id = orders["user"]
	##Odbiera nazwe zadania od klienta, na podstawie ktorego nastepnie uruchamia odpowiednie metody modelu.
	function = orders["function"]

#funkcje
	if function == "addPlayer":
		data = "Nowy"
		##Niezbedne kodowanie na utf8 przy przekazywaniu do C++.
		data = data.encode('utf8')

		x = model.addPlayer(data)
		x = dict(user=x)

	if function == "choose":
	##Wybor obrazka. Przekazuje id odebrane od klienta, rzutuje otrzymany od klienta string.
		x = model.choose(auser_id, int(orders["row"]), int(orders["column"]))
		##Zwraca id obrazka wybranego przez uzytkownika
		x = dict(picture=x)


	if function == "playerReady":
		x = model.playerReady(auser_id, orders["ready"])
		x = dict(status=x)

	if function == "initGame":
		##Rozpoczecie gry. Rzutuje otrzymany od klienta string
		x = model.initGame(int(orders["rows"]), int(orders["columns"]))

		x = dict(status=x)

	if function == "endGame":
		x = model.endGame()
		x = dict(status=x)

	if function == "endTurn":
		x = model.endTurn()
		x = dict(status=x)

	if function == "checkState":
		x = model.getState()
		x = dict(user_id=auser_id,State=x)

	if function == "wattsUp":
		##Zwraca strukture danych zawierajaca informacje na temat biezacej rozgrywki.
		x = dict(score = UpDate("GetScore",  auser_id), status=UpDate("GetState"), player=UpDate("getCurrentPlayer"), testfirst=model.getFirstX(), first=[model.getFirstX(), model.getFirstY(), model.getFirstPicked()], second=[model.getSecondX(), model.getSecondY(), model.getSecondPicked()])

#odpowiadanie
	ret_packet = json.dumps(x)
	stat = '200 OK'

	response_headers = [('Content-Type', 'application/json'), ('Content-Length', str(len(ret_packet)))]
	start_response(stat, response_headers)
	return [ret_packet]


#jesli jest to glowny modul, dolaczamy pythona do serwera.
if __name__ == '__main__':
	from flup.server.fcgi import WSGIServer
	WSGIServer(App).run()