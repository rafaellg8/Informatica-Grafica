#ifndef _CABINA_
#define _CABINA_

#include "Perfil.h"
#include "figura.h"
#include "ObjetoPLY.h"

class Cabina : public Figura
{
private:
	ObjetoPLY nave; //nave entera
	Perfil cabina; //Semiesfera del piloto
public:
	Cabina();
	void pinta(int gltype,float tamPunto);
};
#endif