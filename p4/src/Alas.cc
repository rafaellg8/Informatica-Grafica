#include "Alas.h"

Alas::Alas(){
	vector<_vertex3f> v;
	
	//MOntamos los 2 brazos
	v = {{5.0,0.0,0.0},{5.0,5.0,0.0},{5.0,10.0,0.0},{5.0,15.0,0.0},{5.0,20.0,0.0}};
	brazoIzquierdo = Perfil(v,20);
	brazoDerecho = Perfil(v,20);

	//Base une el cuerpo con los brazos
	v = {{8.0,0.0,0.0},{7.0,2.0,0.0},{6.0,4.0,0.0},{5.0,6.0,0.0}};
	baseAlaIzquierda = Perfil(v,4);
	baseAlaDerecha = Perfil(v,4);

}

void Alas::obtenerExtremos(float ancho, float alto){
	ancho = hexagonoDerecho.getAnchoMax();
	alto = hexagonoDerecho.getAltoMax();
}

void Alas::pintar(int glType,float tamPunto){
	pintarBrazos(glType,tamPunto);

	pintarBases(glType,tamPunto);

	pintarHexagonos(glType,tamPunto);
}

void Alas::pintarBrazos(int glType,float tamPunto){
	glPushMatrix();
		glScalef(2,0.9,1);
			glPushMatrix();
				glTranslatef(35,0,0);
				glRotatef(90,0,0,1);
				brazoIzquierdo.draw(glType,tamPunto);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-35,0,0);
				glRotatef(270,0,0,1);
				brazoDerecho.draw(glType,tamPunto);
			glPopMatrix();
	glPopMatrix();
}

void Alas::pintarBases(int glType,float tamPunto){
	glPushMatrix();
		glScalef(2,1,2);
			glPushMatrix();
				glTranslatef(11.5,0,0);
				glRotatef(270,0,0,1);
				baseAlaIzquierda.draw(glType,tamPunto);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-11.5,0,0);
				glRotatef(90,0,0,1);
				baseAlaDerecha.draw(glType,tamPunto);
			glPopMatrix();
	glPopMatrix();
}

void Alas::pintarHexagonos(int glType,float tamPunto){
	glPushMatrix();
		glScalef(8,8,8);
			glPushMatrix();
				glTranslatef(8.8,0,0);
				glRotatef(90,0,1,0);
				hexagonoIzquierdo.draw(glType,tamPunto);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-8.8,0,0);
				glRotatef(270,0,1,0);
				hexagonoDerecho.draw(glType,tamPunto);
			glPopMatrix();
			
	glPopMatrix();
}