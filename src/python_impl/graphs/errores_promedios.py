import matplotlib
import matplotlib.pyplot as plt
import numpy as np


labels = ['10', '100', '1000']
cmm_means = []
wp_means = []
keener_means = []

x = np.arange(len(labels))  # the label locations
width = 0.35  # the width of the bars

fig, ax = plt.subplots()
rects1 = ax.bar(x - width/2, cmm_means, width, label='CMM')
rects2 = ax.bar(x + width/2, wp_means, width, label='WP')
rects3 = ax.bar(x + width/2, keener_means, width, label='Keener')

# Add some text for labels, title and custom x-axis tick labels, etc.
ax.set_ylabel('Scores')
ax.set_title('Error promedio por tamaño de instancia y metodo de ranking')
ax.set_xticks(x)
ax.set_xticklabels(labels)
ax.legend()


def autolabel(rects):
    """Attach a text label above each bar in *rects*, displaying its height."""
    for rect in rects:
        height = rect.get_height()
        ax.annotate('{}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3),  # 3 points vertical offset
                    textcoords="offset points",
                    ha='center', va='bottom')


autolabel(rects1)
autolabel(rects2)

fig.tight_layout()

plt.show()
