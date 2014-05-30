#!/usr/bin/env python2

#Aplikacja

import os
import sys

#sciezki! Pobieramy sciezke i dodajemy ja do poszukiwan:
path = os.path.dirname(__file__)
path = os.path.abspath(path)
sys.path.append(path)

def beg():

    from path import srv_wsgi

    motherapp = App()

#hendler requestow

class App(object):


	#__init__(self, fp=None, headers=None, outerboundary='', environ={'LESS': '-X -i -Psline %l/%L$ -Pmline %l/%L (%p)$', 'DPKG_ARC..., keep_blank_values=0, strict_parsing=0)
#Konstuktor
    def __init__(self):
        self.root = None
    

#Wywolanie
    def __call__(self, environ, start_response):

        start_response('404 NOT FOUND', [('Content-Type', 'text/plain')])
        return ['Not Found']


motherapp = init()

