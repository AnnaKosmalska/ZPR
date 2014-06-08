#!/usr/bin/env python2

#Serwer

import os
import sys
import json
import os
import model


errors = 0
#Test funkcji. Przykladowa rozgrywka
print "Testuje dodanie gracza poza gra."
try:
	if model.addPlayer("Ptest") == -1:
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1


print "Testuje inicjalizacje gry."
try:
	if model.initGame(4,5) == 1:
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1

print "Testuje dodanie gracza 1."
try:
	if model.addPlayer("P1") == 1:
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1

print "Testuje dodanie gracza 2."
try:
	if model.addPlayer("P2") == 2:
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1

print "Testuje poprawnosc kolejnosci."
try:
	if model.getCurrentPlayer() == 1:
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1

print "Testuje zmiane gracza."
try:
	if model.endTurn() == 2:
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1

print "Testuje poprawnosc kolejnosci."
try:
	if model.getCurrentPlayer() == 2:
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1

print "Testuje wybor."
try:
	k = model.choose(2,1,2) 
	if k >= 0:
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1
#model.getFirstX(), model.getFirstY(), model.getFirstPicked()


print "Testuje poprawnosc przesylania danych o wyborze do innych graczy."
try:
	if model.getFirstX() == 1:
		print "	X	OK"
	else:
		print "	X	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR X"
		errors = errors + 1
try:
	if model.getFirstY() == 2:
		print "	Y	OK"
	else:
		print "	Y	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR Y"
		errors = errors + 1
try:
	if model.getFirstPicked() == k:
		print "	WARTOSC OK"
	else:
		print "	WARTOSC	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR WARTOSC"
		errors = errors + 1

try:
	print "Testuje wynik."
	if model.getScore(2) >= 0:
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1


print "Sprawdzam poprawnosc wielkosci planszy. "
try:
	if model.getSizeX() == 4:
		print "	X	OK"
	else:
		print "	X	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1
try:
	if model.getSizeY() == 5:
		print "	Y	OK"
	else:
		print "	Y	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1


print "Sprawdzam poprawnosc nazwy gracza."
try:
	if model.getName(1) == "P1":
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1


print "Sprawdzam reakcje na brak gracza."
try:
	if model.playerDead(2) == 1
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1



print "Koncze rozgrywke."
try:
	model.endGame()
except:
		print "	CRITICAL ERROR"
		errors = errors + 1

print "Testuje poprawnosc kolejnosci."
try:
	if model.getCurrentPlayer() == 1:
		print "	OK"
	else:
		print "	ERROR"
		errors = errors + 1
except:
		print "	CRITICAL ERROR"
		errors = errors + 1

print "Errors:"
print errors