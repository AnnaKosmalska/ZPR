#!/usr/bin/env python2

#Serwer

import os
import sys
import json
import os
import model

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
	user = orders["user"]
	function = order["function"]
	parameters = order["parameters"]

#funkcje
	if function == "addPlayer":
		x = model.addPlayer(parameters)
	#boost::python::def("addPlayer", addPlayer);

	if function == "choose":
		x = model.choose(user, parameters[0], parameters[1])	
	#boost::python::def("choose", choose);

	if function == "startGame":
		x = mode.startGame()
  	#boost::python::def("startGame", startGame);

	if function == "endGame":
		x = model.endGame()
  	#boost::python::def("endGame", endGame);

	if function == "checkPair":
		x = model.checkPair(user)
  	#boost::python::def("checkPair", checkPair);

	if function == "funkcja"
		x = dict()
		x['atrybut'] = 0


#odpowiadanie
	ret_packet = json.dump(x)
	stat = '200 OK'

	response_headers = [('Content-Type', 'application/json'), ('Content-Length', str(len(ret_packet)))]
	start_response(stat, response_headers)
	return [ret_packet]


#jesli jest to glowny modul, wlaczamy serwer
if __name__ == '__main__':
	from flup.server.fcgi import WSGIServer
	WSGIServer(App).run()
