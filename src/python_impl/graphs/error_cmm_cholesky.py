import matplotlib
import matplotlib.pyplot as plt
import numpy as np


labels = ['10', '100', '1000']
eg = [5.389574009306841e-09, 2.46762398720346e-06, 6.738284039480048e-05]
cholesky = [5.389574009306841e-09, 2.4676239877041704e-06, 6.738284032510838e-05]


x = np.arange(len(labels))  # the label locations
width = 0.35  # the width of the bars

fig, ax = plt.subplots()
rects1 = ax.bar(x - width/2, eg, width, label='Eliminacion Gaussiana')
rects2 = ax.bar(x + width/2, cholesky, width, label='Cholesky')

# Add some text for labels, title and custom x-axis tick labels, etc.
ax.set_ylabel('Error promedio entre tests e implementación C++')
ax.set_xlabel('Tamaño de la entrada')
ax.set_title('Crecimiento del error numérico en función de la cantiadad de equipos: EG vs Cholesky')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend()


def autolabel(rects):
    """Attach a text label above each bar in *rects*, displaying its height."""
    for rect in rects:
        height = rect.get_height()

        ax.set_yscale('log')


autolabel(rects1)
autolabel(rects2)

fig.tight_layout()

plt.show()