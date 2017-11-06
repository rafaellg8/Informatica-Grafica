#ifndef _CAZATIE_
#define _CAZATIE_

#include "figura.h"
#include "cabina.h"
#include "alasCompletas.h"
#include "canion.h"

class CazaTie
{
private:
	Cabina cabina;
	AlasCompletas alasCompletas;
	Canion canion;

public:
	CazaTie();
	CazaTie(Cabina cabina,AlasCompletas alas,Canion canion);
	void dibujar();
	void plegarAlas();
	void rotacionCompleta(bool ejeX, bool ejeY); //Rota sobre el eje X o Y alas y brazos
	void rotarAlas(bool ejeX, bool ejeY, bool ejeZ,float grados); //Elegimos un eje y los grados
	void rotarCanion();
	void disparar(); //Dispara canion	
};

#endif