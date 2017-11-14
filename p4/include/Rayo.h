#ifndef _RAYO_H
#define _RAYO_H

#include "Perfil.h"

class Rayo : public Perfil
{
private:
	float traslacionZ;
	float velocidad;
public:
	Rayo();
	void pintar(int glType, float lado);
	void setTraslacion(float t);
	float getTraslacion();
};

#endif