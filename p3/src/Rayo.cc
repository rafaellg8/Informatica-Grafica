#include "Rayo.h"


Rayo::Rayo(){
	vector<_vertex3f> v;
	v = {{1.0,0.0,0.0},{1.0,1.0,0.0},{1.0,2.0,0.0},{1.0,3.0,0.0}};

	Perfil aux(v,60);
	this->insertarDatos(aux.getVertices(),aux.getCaras());
	setColores(1,0,0);
}

void Rayo::pintar(int glType, float lado){
	glTranslatef(0,-25,4);
	glRotatef(90,1,0,0);
	glScalef(0.5,5,0.5);
	draw(glType,lado);
}

void Rayo::setTraslacion(float t){
	traslacionZ=t;
}

float Rayo::getTraslacion(){
	return traslacionZ;
}