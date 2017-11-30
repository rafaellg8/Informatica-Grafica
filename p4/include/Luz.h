#ifndef _Luz_
#define _Luz_

#include <vector>
#include "vertex.h"
#include "figura.h"

class Luz
{
private:
	_vertex4f posicion;
	float grados=0; //Grados de rotacion
	_vertex4f color;
	bool enable;


public:
	Luz();
	_vertex4f getPosicion();
	void setPosicion(_vertex4f posicion);
	_vertex4f getColor();
	void setColor(_vertex4f color);
	void setEnable();

	void inicializarLuces();
	void posicionarLuces();
	void moverAdelante();
	void moverAtras();
	void girar();
	void upRotate();
	void downRotate();
};

#endif