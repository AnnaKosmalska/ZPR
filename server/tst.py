#!/usr/bin/env python2

#Serwer

import os
import sys
import json
import os
import model

#funkcje
function = sys.argv[1]

struct = {'Jeden': 5, 'Dwa': 7}
parameters=[]
parameters.append(5)
parameters.append(3)
user = 0
x=struct
if function == "addPlayer":
	x = model.addPlayer()
#boost::python::def("addPlayer", addPlayer);
if function == "choose":
	x = model.choose(0, parameters[0], parameters[1])	
	#boost::python::def("choose", choose);

if function == "startGame":
	x = model.startGame(4, 4)
  	#boost::python::def("startGame", startGame);

if function == "endGame":
	x = model.endGame()
  	#boost::python::def("endGame", endGame);

if function == "checkPair":
	x = model.checkPair(user)
	x = dict(user=0,parameter=x)
  	#boost::python::def("checkPair", checkPair);

if function == "funkcja":
	x = dict()
	x['atrybut'] = 0

print x
