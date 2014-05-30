import os
import sys

path = os.path.dirname(__file__)
print path
path = os.path.abspath(path)
print path
print sys.path.append(path)
print "path = " + path
