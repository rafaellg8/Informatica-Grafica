#include "CazaTie.h"

/*Variables globales auxiliares*/
float l; //Lado
int tipo; //Tipo

CazaTie::CazaTie(){
	// rayoI.setColores(1.0,0.0,0.0);
	// rayoD.setColores(1.0,0.0,0.0);
	rotacionX=rotacionY=rotacionZ=0;
}


void CazaTie::pintar(int glType, float lado){
	tipo=glType;
	l = lado;

	/**
	Caniones y cabina
	*/
	glPushMatrix();
	cabina.pintar(glType,lado);
	glPopMatrix();
	

	glPushMatrix();
		// rotacionCompletaAlas();
	rotarAlas(ejeX,ejeY,ejeZ,grados);
	alas.pintar(glType,lado);
	glPopMatrix();


	disparar(glType,lado); //pinta el disparo
}

void CazaTie::obtenerExtremos(float ancho, float alto){
	alas.obtenerExtremos(ancho,alto);
}

void CazaTie::mueveDisparo(){
	traslacionZ++;
	traslacionZ = static_cast<int>((traslacionZ))%100; //Para simular un disparo, cuando desaparece, empieza desde la posicion inicial
	if (traslacionZ==0)
		traslacionZ=10;
	cabina.setTraslacionRayo(traslacionZ);
}

void CazaTie::disparar(int glType,float lado){
	cabina.disparar(glType,lado);
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

void CazaTie::upRotX(){
	if (rotacionX<=90)
		rotacionX+=1;
	ejeX=true;
	ejeY=ejeZ=false;
	grados=rotacionX;
}

void CazaTie::downRotX(){
	if (rotacionX>=-90)
		rotacionX-=1;
	ejeX=true;
	ejeY=ejeZ=false;
	grados=rotacionX;
}

void CazaTie::upVelocidadX(){
	ejeX=true;
	ejeY=ejeZ=false;
	if (velocidadX<45)
		velocidadX+=0.5;
}

void CazaTie::upVelocidadY(){
	ejeY=true;
	ejeX=ejeZ=false;
	if (velocidadY<30)
		velocidadY+=0.5;	
}

void CazaTie::upVelocidadZ(){
	ejeZ=true;
	ejeX=ejeY=false;
	if (velocidadZ<45)
		velocidadZ+=0.5;
}

void CazaTie::downVelocidadX(){
	ejeX=true;
	ejeY=ejeZ=false;
	if (velocidadX>0)
		velocidadX-=0.5;
}

void CazaTie::downVelocidadY(){
	ejeY=true;
	ejeX=ejeZ=false;
	if (velocidadY>0)
		velocidadY-=0.5;
}

void CazaTie::downVelocidadZ(){
	ejeZ=true;
	ejeX=ejeY=false;
	if (velocidadZ>0)
		velocidadZ-=0.5;
}

void CazaTie::upTraslacionZ(){
	if (traslacionZ<30)
		traslacionZ+=0.5;
}

void CazaTie::downTraslacionZ(){
	if (traslacionZ>0)
		traslacionZ-=0.5;
}

void CazaTie::rotarAlas(bool ejeX, bool ejeY, bool ejeZ, float grados){
	if (ejeX)
		plegarAlas(tipo,l);
	else{
		glRotatef(grados,ejeX,ejeY,ejeZ);
	}
}

void CazaTie::plegarAlas(int tipo,float l){
	alas.pintarBrazos(tipo,l);
	alas.pintarBases(tipo,l);
	glRotatef(grados,1,0,0);
	alas.pintarHexagonos(tipo,l);
}

void CazaTie::animarte(){
	if (ejeX){
		grados+=velocidadX;

	}
	if (ejeY){
		grados+=velocidadY;
	}
	if (ejeZ){
		grados+=velocidadZ;
	}
	if (traslacionZ<100)
		traslacionZ++;
		else traslacionZ=10; //Cuando llega a 100 vuelve a empezar

	mueveDisparo();
}

	void CazaTie::setAnimar(){
	this->animar = !animar; //Cambiamos el estado
}

bool CazaTie::getAnimar(){
	return this->animar;
}