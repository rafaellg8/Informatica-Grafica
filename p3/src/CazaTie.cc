#include "CazaTie.h"

CazaTie::CazaTie(){}

CazaTie::CazaTie(Cabina cabina, AlasCompletas alas,Canion canion){
	this->cabina = cabina;
	this->AlasCompletas = alas;
	this->canion = canion;
}

void CazaTie::dibujar(){
	cabina.pintar();
	alas.pintar();
	canion.pintar();
}