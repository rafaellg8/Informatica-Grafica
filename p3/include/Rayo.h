#ifndef _RAYO_H
#define _RAYO_H

#include "Perfil.h"

class Rayo : public Perfil
{
public:
	Rayo();
	void pintar(int glType, float lado);
};

#endif