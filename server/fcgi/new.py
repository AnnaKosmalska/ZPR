#!/usr/bin/env python2

#Aplikacja

#sciezki! Pobieramy sciezke bezwzgledna:
path = os.path.dirname(sys.argv[0])
path = os.path.abspath(path)
sys.path.append(path)

def beg():

    from path import srv_wsgi

    mothership = App()

#hendler requestow

class App(object):

    def __init__(self):
        #TODO
        self.root = None
    
    def __call__(self, environ, start_response):
        path #costam costam
