import numpy as np
import argparse
import matplotlib.pyplot as plt
# Define los argumentos del script
parser = argparse.ArgumentParser(description="Genera una gráfica a partir de un archivo de texto")
parser.add_argument("filename", type=str, help="Nombre del archivo de texto")
args = parser.parse_args()


# Cargar los datos del archivo
senal = np.loadtxt(args.filename)

# Graficar la señal
plt.plot(senal[0:150])
plt.xlabel('Muestras')
plt.ylabel('Amplitud')
plt.title(args.filename)
plt.grid(True)
plt.show()
