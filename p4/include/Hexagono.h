#ifndef _HEXAGONO_H
#define _HEXAGONO_H

#include "figura.h"

class Hexagono : public Figura
{
public:
	Hexagono();
	Hexagono(float anchoCara, float altoCara); //Dimensiones de cada triangulo que queremos pintar	

	void pintar(int glType, float lado);
};
#endif