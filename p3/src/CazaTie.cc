#include "CazaTie.h"

CazaTie::CazaTie(){
	rayoI.setColores(1.0,0.0,0.0);
	rayoD.setColores(1.0,0.0,0.0);
}


void CazaTie::pintar(int glType, float lado){

	glPushMatrix();
		glScalef(0.6,0.6,0.6);
		cabina.pintar(glType,lado);
	glPopMatrix();

	glPushMatrix();
		// rotacionCompletaAlas();
		rotarAlas(ejeX,ejeY,ejeZ,grados);
		alas.pintar(glType,lado);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(10,0,0);
		canionI.pintar(glType,lado);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-10,0,0);
		canionD.pintar(glType,lado);
	glPopMatrix();

	disparar(glType,lado); //pinta el disparo
}

void CazaTie::obtenerExtremos(float ancho, float alto){
	alas.obtenerExtremos(ancho,alto);
}

void CazaTie::mueveDisparo(){
	traslacionZ+=3;
	traslacionZ = static_cast<int>((traslacionZ))%100; //Para simular un disparo, cuando desaparece, empieza desde la posicion inicial
	if (traslacionZ==0)
		traslacionZ=10;
}

void CazaTie::disparar(int glType,float lado){
	/**
	Pintamos el disparo
	A medidad que se aleja, se alarga el laser
	*/
	glPushMatrix();
		glScalef(1,1,traslacionZ*0.1);
		glTranslatef(10,0,traslacionZ);
		rayoI.pintar(glType,lado);
	glPopMatrix();

	glPushMatrix();
		glScalef(1,1,traslacionZ*0.1);
		glTranslatef(-10,0,traslacionZ);
		rayoD.pintar(glType,lado);
	glPopMatrix();
}

void CazaTie::rotacionCompletaAlas(){
	glRotatef(grados,0.0,0.0,1);
}

void CazaTie::upRotZ(){
	rotacionZ+=1;
	ejeZ=true;
	ejeX=ejeY=false;
	grados=rotacionZ;
}

void CazaTie::upRotY(){
	ejeY=true;
	ejeX=ejeZ=false;
	if (rotacionY<=30) //Solo se permite giran 30 grados
		rotacionY+=1;
	grados=rotacionY;
}

void CazaTie::downRotY(){
	ejeY=true;
	ejeX=ejeZ=false;
	if (rotacionY>=-30) //Solo se permite giran 30 grados
		rotacionY-=1;
	grados=rotacionY;
}

void CazaTie::downRotZ(){
	rotacionZ-=1;
	ejeZ=true;
	ejeX=ejeY=false;
	grados=rotacionZ;
}

void CazaTie::rotarAlas(bool ejeX, bool ejeY, bool ejeZ, float grados){
	glRotatef(grados,ejeX,ejeY,ejeZ);
}