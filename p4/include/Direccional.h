#ifndef _DIRECCIONAL_H
#define _DIRECCIONAL_H
#include "Luz.h"
/**
En este caso la luz direccion será la numero 1
*/
class Direccional : public Luz
{
public:
	Direccional();
	void enableLight();

	void inicializarLuces();
	void posicionarLuces();
	void mover();
	void girar();
	void moverAdelante();
	void moverAtras();

private:
	void lightFV();
};
#endif