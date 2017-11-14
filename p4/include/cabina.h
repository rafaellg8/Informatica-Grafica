#ifndef _CABINA_H
#define _CABINA_H

#include "Perfil.h"
#include "ObjetoPLY.h"
#include "Canion.h"
#include "Rayo.h"

class Cabina
{
private:
	ObjetoPLY nave; //nave entera
	Perfil cabina; //Semiesfera del piloto
	Canion canionI;//Canion izquierda
	Canion canionD;//Canion derecha
	Rayo rayoI;
	Rayo rayoD;

public:
	Cabina();
	void pintar(int gltype,float tamPunto);
	void setTraslacionRayo(float t);
	void disparar(int gltype,float tamPunto);
};
#endif