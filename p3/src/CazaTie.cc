#include "CazaTie.h"

CazaTie::CazaTie(){}


void CazaTie::pintar(int glType, float lado){
	glPushMatrix();
		glScalef(0.6,0.6,0.6);
		cabina.pintar(glType,lado);
	glPopMatrix();
	alas.pintar(glType,lado);
	canion.pintar(glType,lado);
}