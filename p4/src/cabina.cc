#include "cabina.h"

Cabina::Cabina(){
	std::vector<_vertex3f> v,vSemi;

	v = {{0.0,-5.0,0.0},{1.5,-4.5,0.0},{3.5,-3.5,0.0},{4.5,-1.5,0.0},{5.0,0.0,0.0},
		{5.0,0.0,0.0},{4.5,1.5,0.0},{3.5,3.5,0.0},{1.5,4.5,0.0},{0.0,5.0,0.0}};

	vSemi = {{1.5,-4.5,0.0},{1.5,-3.5,0.0},{1.5,-1.5,0.0}};

	nave = ObjetoPLY("ply/sphere.ply");
	cabina = Perfil(vSemi,8); //Semiesfera

	cabina.setColores(0.0,0.0,0.0);
	//la nave no ponemos color por defecto la pinta gris

}

void Cabina::pintar(int gltype, float tamPunto){
	glPushMatrix();
		nave.setMaterialGris();
		glScalef(0.22,0.22,0.22);
		nave.draw(gltype,tamPunto);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0,0.0,30.0);
		glScalef(8,8,1.0);
		glRotatef(90,1,0,0);
		glRotatef(180,0,1,0);
		cabina.setMaterialNegro();
		cabina.draw(gltype,tamPunto);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(10,-25,10);
		glRotatef(90,1,0,0);
		glScalef(1,5,1);
		canionI.draw(gltype,tamPunto);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-10,-25,10	);
		glRotatef(90,1,0,0);
		glScalef(1,5,1);
		canionD.draw(gltype,tamPunto);
	glPopMatrix();


}

void Cabina::setTraslacionRayo(float t){
	rayoI.setTraslacion(t);
	rayoD.setTraslacion(t);
}

void Cabina::disparar(int gltype,float tamPunto){
	/**
	Pintamos el disparo
	A medidad que se aleja, se alarga el laser
	*/
	float traslacionZ = rayoI.getTraslacion();
	glPushMatrix();
	glScalef(1,1,traslacionZ*0.8);
	glTranslatef(10,-25,traslacionZ);
	glRotatef(90,1,0,0);
	rayoI.draw(gltype,tamPunto);
	glPopMatrix();

	glPushMatrix();
	glScalef(1,1,traslacionZ*0.8);
	glTranslatef(-10,-25,traslacionZ);
	glRotatef(90,1,0,0);
	rayoD.draw(gltype,tamPunto);
	glPopMatrix();
}