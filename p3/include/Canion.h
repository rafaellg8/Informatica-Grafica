#ifndef _CANION_H
#define _CANION_H

#include "Perfil.h"

class Canion : public Perfil
{
public:
	Canion();
	void pintar(int glType, float lado);
};

#endif