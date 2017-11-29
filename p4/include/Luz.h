#ifndef _Luz_
#define _Luz_

#include <vector>
#include "vertex.h"
#include "figura.h"
#include "ObjetoPLY.h"

class Luz
{
private:
	_vertex4f posicion;
	_vertex4f color;
	bool enable;
	ObjetoPLY esfera;


public:
	Luz();
	_vertex4f getPosicion();
	void setPosicion(_vertex4f posicion);
	_vertex4f getColor();
	void setColor(_vertex4f color);
	void setEnable();

	void inicializarLuces();
	void posicionarLuces();
	void draw();
};

#endif