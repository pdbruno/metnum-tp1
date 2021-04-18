from keener import keener
from wp import wp
# from cmm import cmm
import sys
import os
import numpy as np
from subprocess import *
from fnmatch import fnmatch

def listfiles(root, pattern):
  for path, subdirs, files in os.walk(root):
    for name in files:
      if fnmatch(name, pattern):
        yield os.path.join(path, name)


methods = ['keener', 'wp']
methodsFn = {
    'keener': keener,
    'wp': wp,
}

for method in methods:
    for fname in listfiles(f'../tests/{method}/', '*.in'):
        methodFn = methodsFn[method]
        expectedResult = methodFn(fname)
        file_object = open(fname.replace(".in", ".expected"), 'a')
        for num in expectedResult:
            file_object.write(f'{num}\n')
        file_object.close()
