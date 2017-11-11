#ifndef _CAZATIE_H
#define _CAZATIE_H

#include "figura.h"
#include "cabina.h"
#include "Alas.h"
#include "Canion.h"
#include "Rayo.h"

class CazaTie
{
private:
	Cabina cabina;
	Alas alas;
	Canion canionD; //canion derecha
	Canion canionI; //canion izquierda

	Rayo rayoI;
	Rayo rayoD;

	float traslacionZ=10; //Traslacion del disparo sobre el eje z
	//Se ira sumando cada vez que se pulse la tecla z
	float rotacionX; //Rotacion sobre el eje X de alguna parte del caza
	float rotacionY; //Rotacion sobre el eje Y de alguna parte del caza
	float rotacionZ; //Rotacion sobre el eje Z de alguna parte del caza

	bool ejeX,ejeY,ejeZ;
	float grados;
public:
	CazaTie();
	void pintar(int glType,float lado); //Dibujo

	/**
	Rotaciones y animaciones
	*/
	void plegarAlas(int glType,float lado);
	void rotacionCompletaAlas(); //Rota sobre el eje Z las alas y los brazos
	void rotarAlas(bool ejeX, bool ejeY, bool ejeZ,float grados); //Elegimos un eje y los grados
	void rotarCanion();
	void disparar(int glType,float lado); //Dispara rayos laser	
	void mueveDisparo();

	void upRotZ(); //Aumentar rotacion eje Z
	void upRotY(); //Aumentar rotacion eje Y
	void upRotX();
	void downRotZ();
	void downRotY();
	void downRotX();

	/**
	Obtiene los dos extremos mayores. Como tenemos una figura simétrica, los más pequeños serán negativos.
	No necesitamos obtenerlos
	*/
	void obtenerExtremos(float ancho,float alto);
};

#endif