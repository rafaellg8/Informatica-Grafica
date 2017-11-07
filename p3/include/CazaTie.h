#ifndef _CAZATIE_H
#define _CAZATIE_H

#include "figura.h"
#include "cabina.h"
#include "Alas.h"
#include "Canion.h"

class CazaTie
{
private:
	Cabina cabina;
	Alas alas;
	Canion canion;

public:
	CazaTie();
	void pintar(int glType,float lado);
	void plegarAlas();
	void rotacionCompleta(bool ejeX, bool ejeY); //Rota sobre el eje X o Y alas y brazos
	void rotarAlas(bool ejeX, bool ejeY, bool ejeZ,float grados); //Elegimos un eje y los grados
	void rotarCanion();
	void disparar(); //Dispara canion	
};

#endif