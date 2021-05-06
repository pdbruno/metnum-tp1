import matplotlib
import matplotlib.pyplot as plt
import numpy as np

diff = [2,2,1,0,3,0,1,1,3,0,2,3,1,1,9,5,3,0,0,1,1,2,0,0,1,2,0,1,8,1]
diff_cmm_wp = [0,1,1,0,1,0,1,1,1,0,0,0,0,0,1,0,1,0,0,1,0,1,0,1,1,0,0,0,0,0] 
plt.hist(diff, bins=[0,1,2,3,4,5,6,7,8,9,10], ec='black')
plt.xlabel('Diferencia en puestos')
plt.ylabel('Cantidad de equipos')
plt.title("Diferencia de puestos entre CMM y Keener") 
plt.show()