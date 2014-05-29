#!/usr/bin/env python2

import cgi
import string
#zapytac Anie o plik do pobierania uzytkownikow

def wsgisrv(environ, start_response):
	start_response('200 OK,[('Content-Type', 'text/plain')]')
	#tworzymy struktre danych
	form=cgi.FieldStorage(
		fp=environ['wsgi.input'], #nie uzywamy GET
		environ=environ,
		keep_blank_values=True)

#tutaj bedzie pobieranie z pol i dodawanie uzytkownikow
	
	user = form.getvalue('pole_user')
	userlist.add(user)

#TODO: dodac czytanie z htmla i wypelnianie htmla userem


#--------------------------------------------------------------
#wrzucone z tuoriala, niekoniecznie działa:
   # Sorting and stringifying the environment key, value pairs
   response_body = ['%s: %s' % (key, value)
                    for key, value in sorted(environ.items())]
   response_body = '\n'.join(response_body)

   status = '200 OK'
   response_headers = [('Content-Type', 'text/plain'),
                  ('Content-Length', str(len(response_body)))]
   start_response(status, response_headers)

   return [response_body]

# Instantiate the WSGI server.
# It will receive the request, pass it to the application
# and send the application's response to the client
httpd = make_server(
   'localhost', # The host name.
   8051, # A port number where to wait for the request.
   application # Our application object name, in this case a function.
   )

# Wait for a single request, serve it and quit.
httpd.handle_request()
