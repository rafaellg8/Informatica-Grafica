#include "cabina.h"

Cabina::Cabina(){
	std::vector<_vertex3f> v,vSemi;

	v = {{0.0,-5.0,0.0},{1.5,-4.5,0.0},{3.5,-3.5,0.0},{4.5,-1.5,0.0},{5.0,0.0,0.0},
		{5.0,0.0,0.0},{4.5,1.5,0.0},{3.5,3.5,0.0},{1.5,4.5,0.0},{0.0,5.0,0.0}};

	vSemi = {{1.5,-4.5,0.0},{1.5,-3.5,0.0},{1.5,-1.5,0.0}};

	nave = ObjetoPLY("ply/sphere.ply");
	cabina = Perfil(vSemi,8); //Semiesfera
	// nave.quitaTapaA();
	// nave.quitaTapaF();
	v.clear();
	
	/**
	ÑAPA
	*/ 
	// insertarDatos(nave.getVertices(),nave.getCaras());
	/**
	FIN DE ÑAPA
	*/

}

void Cabina::pintar(int gltype, float tamPunto){
	glPushMatrix();
		glScalef(0.37,0.37,0.37);
		nave.draw(gltype,tamPunto);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0,0.0,48.0);
		glScalef(10,10,1.0);
		glRotatef(90,1,0,0);
		glRotatef(180,0,1,0);
		cabina.draw(gltype,tamPunto);
	glPopMatrix();

}