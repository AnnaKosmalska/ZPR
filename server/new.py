#!/usr/bin/env python2

#Serwer

import os
import sys
import json
import os
import model
import random

def UpDate(co, auser=0):
	#int getScore(int gracz)
	if co == "GetScore":
		return model.getScore(auser)
	#int getState() stan gry
	if co == "GetState":
		return model.getState()
	#int getCurrentPlayer() kto teraz gra
	if co == "getCurrentPlayer":
		return model.getCurrentPlayer()
	#int getFirst() pierwszy kartonik


def App(environ, start_response):
#sprawdzamy pakiet, pobieramy dlugosc
	try:
		packet_leng = int(environ.get('CONTENT_LENGTH', 0))
	except (ValueError):
		packet_leng = 0

#pobieramy caly pakiet
	packet = environ['wsgi.input'].read(packet_leng)
	orders = json.loads(packet)

#dodac wybieranie z jsona informacji, obsluga modelu
	auser_id = orders["user"]
	function = orders["function"]

#funkcje
	if function == "addPlayer":
		data = "Nowy"
		data = data.encode('utf8')
		x = model.addPlayer(data)
		x = dict(user=1)

	if function == "choose":
		x = model.choose(auser_id, int(orders["row"]), int(orders["column"]))
		x = dict(picture=x)


	if function == "playerReady":
		x = model.playerReady(auser_id, orders["ready"])
		x = dict(status=x)

	if function == "initGame":
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
		x = dict(score = UpDate("GetScore",  auser_id), status=UpDate("GetState"), player=UpDate("getCurrentPlayer"), testfirst=model.getFirstX(), first=[model.getFirstX(), model.getFirstY(), model.getFirstPicked()], second=[model.getSecondX(), model.getSecondY(), model.getSecondPicked()])

#odpowiadanie
	ret_packet = json.dumps(x)
	stat = '200 OK'

	response_headers = [('Content-Type', 'application/json'), ('Content-Length', str(len(ret_packet)))]
	start_response(stat, response_headers)
	return [ret_packet]


#jesli jest to glowny modul, wlaczamy serwer
if __name__ == '__main__':
	from flup.server.fcgi import WSGIServer
	WSGIServer(App).run()