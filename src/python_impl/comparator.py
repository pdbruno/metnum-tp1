from keener import keener
from wp import wp
from cmm import cmm
import sys
import os
import numpy as np
#from fnmatch import fnmatch
from subprocess import *

def listfiles(folder):
  return [f'../tests/{folder}/test_completos/{filename}' for filename in ['test_completo_10_1.in', 'test_completo_100_4.in', 'test_completo_100_8.in', 'test_completo_1000_2.in', 'test_completo_1000_8.in']]
  #for path, subdirs, files in os.walk(root):
  #  for name in files:
  #    if fnmatch(name, pattern):
  #      print(3)
  #      yield os.path.join(path, name)


METHOD = 1

method = sys.argv[METHOD]

methods = {
  '0': 'cmm',
  '1': 'wp',
  '2': 'keener',
}

methodsFn = {
  '0': cmm,
  '1': wp,
  '2': keener,
}
for fname in listfiles(methods[method]):
    methodFn = methodsFn[method]
    expectedResult = methodFn(fname)
    outPath = fname.replace('.in', '.out')
    r_out = check_output(['../tp', fname, outPath, method], stdin=None, stderr=PIPE).decode().split('\n')[:-1]
    print(np.array([float(num) for num in r_out]))
    print(expectedResult)
    break
    expected_fname = fname.replace(".in", ".expected") 
    np.savetxt(expected_fname, r)