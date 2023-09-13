/*
 * Arreglo.h
 *
 *  Created on: 23 sept. 2021
 *      Author: lunat
 */

#ifndef ARREGLO_H_
#define ARREGLO_H_

namespace Ejercicios {

class Arreglo {
	int *ptr;//direccion de inicio del arreglo
	int tam;//tamaño del arreglo actual
	static int nro_instancias;//atributo estatico que lleva la cuenta de la cantidad de instancias de la clase existentes en cada momento
public:
	Arreglo(int t = 10);//constructor ordinario y por defecto
	~Arreglo();//destructor, necesario ya que se utiliza memoria dinamica en el constructor
	Arreglo& operator=(const Arreglo &);
	void Mostrar();
	Arreglo& operator+(const Arreglo &);
	void CargarValores(void);
	void SetElementoN(int n, int v);
	int GetElementoN(int n);
	static int getNroInstancias(void);//un metodo estatico se puede llamar incluso cuando no existe ninguna instancia de la clase
};

} /* namespace Ejercicios */

#endif /* ARREGLO_H_ */
