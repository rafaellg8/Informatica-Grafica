#ifndef _CABINA_H
#define _CABINA_H

#include "Perfil.h"
#include "ObjetoPLY.h"

class Cabina
{
private:
	ObjetoPLY nave; //nave entera
	Perfil cabina; //Semiesfera del piloto
public:
	Cabina();
	void pintar(int gltype,float tamPunto);
};
#endif