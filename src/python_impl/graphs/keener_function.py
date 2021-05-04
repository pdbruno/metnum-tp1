import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import math

def h(x):
    return (0.5+ 0.5 * np.sign(x-0.5) * np.sqrt(abs(2*x-1)))

dom = np.arange(0,100,1)
im = pd.Series([h(x) for x in dom])
plt.plot(im)
plt.ylabel('h(x)')
plt.xlabel('x')
plt.ylim(0, 15)
plt.show()