import matplotlib
import matplotlib.pyplot as plt
import numpy as np


data = [5.389574009306841e-09, 2.46762398720346e-06, 6.738284039480048e-05]
labels = ['10', '100', '1000']
plt.xticks(range(len(data)), labels)
plt.xlabel('Tamaño de la entrada')
plt.ylabel('Error promedio entre tests e implementación C++')
plt.title('Crecimiento del error numérico en función de la cantiadad de equipos')
plt.bar(range(len(data)), data)
plt.yscale('log')
plt.show()