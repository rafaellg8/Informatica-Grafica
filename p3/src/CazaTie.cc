#include "CazaTie.h"

CazaTie::CazaTie(){}


void CazaTie::pintar(int glType, float lado){
	glPushMatrix();
		glScalef(0.6,0.6,0.6);
		cabina.pintar(glType,lado);
	glPopMatrix();

	alas.pintar(glType,lado);
	
	glPushMatrix();
		glTranslatef(10,0,0);
		canionI.pintar(glType,lado);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-10,0,0);
		canionD.pintar(glType,lado);
	glPopMatrix();
}

void CazaTie::obtenerExtremos(float ancho, float alto){
	alas.obtenerExtremos(ancho,alto);
}