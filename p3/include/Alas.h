#ifndef _ALAS_H
#define _ALAS_H


#include "Perfil.h"
#include "Hexagono.h"

class Alas {
private:
	Perfil brazoIzquierdo;
	Perfil brazoDerecho;
	Hexagono hexagonoDerecho;
	Hexagono hexagonoIzquierdo;
	Perfil baseAlaIzquierda;
	Perfil baseAlaDerecha;

public:
	Alas();
	void pintar(int glType,float tamPunto);
	void pintarBrazos(int glType, float tamPunto);
	void pintarBases(int glType, float tamPunto);
	void pintarHexagonos(int glType, float tamPunto);

	void obtenerExtremos(float ancho, float alto);
};

#endif