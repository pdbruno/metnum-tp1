import unittest
import scripts.settings as settings

from subprocess import *
from glob import glob
from scripts.utils import listfiles
import numpy as np


class ErrorCompare():

  def runTp(self, input, output):
    """Invoca al tp con input y output como parametros"""
    check_call([settings.executable, input, output] + settings.extraParams, stdin=None, stdout=PIPE, stderr=PIPE)

  def getError(self, inputPath, expectedPath, outputPath):
    """Ejecuta tp.exe, pasando como parametros inputPath y outputPath, y verifica que la salida generada coincida con el contenido del archivo en expectedPath"""
    expected, actual = dict(), dict()

    self.runTp(inputPath, outputPath)

    with open(expectedPath, 'r') as fexpected:
      expected = [float(x.strip()) for x in fexpected.readlines() if len(x.strip()) > 0]

    with open(outputPath, 'r') as factual:
      actual = [float(x.strip()) for x in factual.readlines() if len(x.strip()) > 0]

    values = []
    for index, (a, e) in enumerate(zip(actual, expected)):
      values.append(abs(a - e))
    return np.mean(values)

  def addComparison(self, inputPath, expectedPath, outputPath):
    """Registra un test nuevo dinamicamente"""
    tname = inputPath.replace("\\", "_").replace("/", "_").replace(".in", "")
    return self.getError(inputPath, expectedPath, outputPath)

# Para cada archivo .in en la carpeta tests o cualquier subcarpeta, registra un nuevo test dinamicamente, verificando que la salida tenga el mismo contenido que el archivo con igual nombre pero extension .expected
methods = {
  '0': 'cmm',
  '1': 'wp',
  '2': 'keener',
  '3': 'cmm',
}

def error():
    nombre_metodo = methods[settings.extraParams[0]] if settings.extraParams[0] != '3' else 'cmm con cholesky'
    for fname in listfiles(f'tests/{methods[settings.extraParams[0]]}', '*.in'):
        error = ErrorCompare().addComparison(fname, fname.replace(".in", ".expected"), fname.replace(".in", ".out"))
        print(f'{fname}: El promedio de error calculado entre el expected y la implemetacion de C++ para el metodo {nombre_metodo} es {error}')
