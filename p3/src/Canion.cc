#include "Canion.h"

Canion::Canion(){
	vector<_vertex3f> v;
	v = {{1.0,0.0,0.0},{1.0,1.0,0.0},{1.0,2.0,0.0},{1.0,3.0,0.0}};

	Perfil aux(v,60);
	this->insertarDatos(aux.getVertices(),aux.getCaras());
	this->setColores(0.0,0.0,0.0);
}

void Canion::pintar(int glType, float lado){
	glTranslatef(0,0,4);
	draw(glType,lado);

}
