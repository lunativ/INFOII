import numpy as np

# Parámetros de la señal
frecuencia = 50
amplitud = 127
muestras = 256
ts = 1/500

# Generar el tiempo
tiempo = np.linspace(0, muestras, muestras, endpoint=False)
print(tiempo[0:10])

# Generar la señal senoidal
senal = amplitud * np.sin(2 * np.pi * frecuencia * tiempo * ts)

# Guardar la señal en un archivo de texto
np.savetxt('senal.txt', senal, fmt='%d')
