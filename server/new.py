#!/usr/bin/env python2

#Serwer

import os
import sys
import json
import os
import model
import random

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
	parameters = orders["parameters"]

#funkcje
	if function == "addPlayer":
		x = model.addPlayer(orders["name"])
		x = dict(user=x)
	#boost::python::def("addPlayer", addPlayer);
	#in:	string - name
	#out:	int - id

	if function == "choose":
		x = model.choose(auser_id, orders["row"], orders["column"])
		x = dict(picture=x)
	#boost::python::def("choose", choose);
	#in:	int, int, int - player, x, y
	#out:	int - id_obrazka


	if function == "playerReady":
		x = mode.playerReady(auser_id, orders["ready"])
		x = dict(status=x)
  	#boost::python::def("startGame", startGame);
	#in:	int, int - player_id, readyornot
	#out:	int status

	if function == "initGame":
		x = mode.initGame(auser_id, orders["rows"], orders["columns"])
		x = dict(status=x)
  	#boost::python::def("initGame", initGame);
	#in:	int, int x, int y - player_id, rozmiary planszy
	#out:	int status

	if function == "endGame":
		x = model.endGame()
		x = dict(status=x)
  	#boost::python::def("endGame", endGame);
	#in:	NA
	#out:	NA

	#if function == "checkPair":
	#	x = model.checkPair(auser)
	#	x = dict(user_id=auser_id,parameter=x)
  	#boost::python::def("checkPair", checkPair);
	#in:	
	#out:	

	if function == "wattsUp":
		x = model.getGameData()
		x = dict(x)
  	#boost::python::def("getGameData", getGameData);
	#in:	NA
	#out:	struct GameData

	if function == "funkcja":
		#x = dict(one=[1, 2, 3], two=[2, 3, 3], three=[3, 2, 1])
		#x['atrybut'] = 0
		#x['atrybut'] = [1, 2, 3, 4, 5]
		if (random.random()>0.5):
			x = dict(picture="1.png")
		else:
			x = dict(picture="2.png")
	if (random.random()>0.8):
		x = dict(picture="nie")

	if function == "ping":
		x = dict(Fakt="Strusie pedza. Bimber.")

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
