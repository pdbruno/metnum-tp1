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
file_object = open(methods[method] + '_errores_promedios.txt', 'a')

for fname in listfiles(methods[method]):
    methodFn = methodsFn[method]
    expectedResult = methodFn(fname)
    outPath = fname.replace('.in', '.out')
    r_out = check_output(['../tp', fname, outPath, method], stdin=None, stderr=PIPE).decode().split('\n')[:-1]
    cppResult = np.array([float(num) for num in r_out])
    errorPromedio = np.mean(abs(cppResult - expectedResult))
    # Append 'hello' at the end of file
    file_object.write(f'{fname} {errorPromedio}\n')
    # Close the file
    #np.savetxt(expected_fname, r)
file_object.close()