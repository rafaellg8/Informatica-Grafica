#ifndef _CAZATIE_H
#define _CAZATIE_H

#include "figura.h"
#include "cabina.h"
#include "Alas.h"
#include "Canion.h"

class CazaTie
{
private:
	Cabina cabina;
	Alas alas;
	Canion canionD; //canion derecha
	Canion canionI; //canion izquierda

public:
	CazaTie();
	void pintar(int glType,float lado); //Dibujo

	/**
	Rotaciones y animaciones
	*/
	void plegarAlas();
	void rotacionCompleta(bool ejeX, bool ejeY); //Rota sobre el eje X o Y alas y brazos
	void rotarAlas(bool ejeX, bool ejeY, bool ejeZ,float grados); //Elegimos un eje y los grados
	void rotarCanion();
	void disparar(); //Dispara canion	


	/**
	Obtiene los dos extremos mayores. Como tenemos una figura simétrica, los más pequeños serán negativos.
	No necesitamos obtenerlos
	*/
	void obtenerExtremos(float ancho,float alto);
};

#endif