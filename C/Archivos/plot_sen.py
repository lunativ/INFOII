import numpy as np
import matplotlib.pyplot as plt

# Cargar los datos del archivo
senal = np.loadtxt('senal.txt')

# Graficar la señal
plt.plot(senal[0:150])
plt.xlabel('Muestras')
plt.ylabel('Amplitud')
plt.title('Señal')
plt.grid(True)
plt.show()
