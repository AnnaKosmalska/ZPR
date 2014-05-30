#!/usr/bin/env python2

import cgi
import string
import Board
#zapytac Anie o plik do pobierania uzytkownikow

def wsgisrv(environ, start_response):
	start_response('200 OK,[('Content-Type', 'text/plain')]')
	#tworzymy struktre danych
	form=cgi.FieldStorage(
		fp=environ['wsgi.input'], #nie uzywamy GET
		environ=environ,
		keep_blank_values=True)

#tutaj bedzie pobieranie z pol struktury i dodawanie uzytkownikow
	
	user = form.getvalue('pole_user')

#odwoluje sie do board.cpp
	Board.addPlayer(user)

#czytanie z htmla i wypelnianie htmla userem
	f = open(mainpage.html)
	hpage = string.Template( f.read() )
	f.close()

	result = hpage.safe_substitute(username=user)

	return result

