#include "Luz.h"


#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#endif

Luz::Luz(){
	color.x =0.5;
	color.y =0.5;
	color.z =0.5; //Por defecto amarillo
	color[4]=0;
	posicion(0,100,0,1.0); //Posicion por defecto
	enable = false;
	grados = 0; //Grados de rotacion
}

void Luz::setPosicion(_vertex4f posicion){
	this->posicion=posicion;
}

_vertex4f Luz::getPosicion(){
	return this->posicion;
}

void Luz::setColor(_vertex4f color){
	this->color=color;
}

_vertex4f Luz::getColor(){
	return this->color;
}

void Luz::setEnable(){
	if (!enable){
		glEnable(GL_LIGHTING);
		cout<<"\nActivando iluminacion"<<endl;
		enable=true;
	}
	else{
		glDisable(GL_LIGHTING);
		enable=false;
		cout<<"\nDesactivando iluminacion"<<endl;
	}
}

void Luz::inicializarLuces(){
	glEnable(GL_LIGHTING);
    const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 
    const GLfloat light_diffuse[] = { color.x, color.y, color.z, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); 

	
	glEnable(GL_LIGHT0);
}

void Luz::posicionarLuces(){
	glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE ); //Si Proyeccion en perspectiva
	const GLfloat posf[4] = { posicion.x, posicion.y, posicion.z, 1.0 } ;  // (x,y,z,w) 
	// glLightfv( GL_LIGHT0, GL_POSITION, posf ); 
    glLightfv(GL_LIGHT0,GL_POSITION,posf);
}


void Luz::moverAdelante(){
	posicion.z +=10;
	lightFV();
	cout<<posicion.z<<endl;
}

void Luz::moverAtras(){
	posicion.z -=10;
	lightFV();
	cout<<posicion.z<<endl;
}

void Luz::upRotate(){
	grados+=5;
}

void Luz::downRotate(){
	grados-=5;
}

void Luz::girar(){
	glPushMatrix();
		glRotatef(grados,0,1,0);
		this->lightFV();
	glPopMatrix();
}

void Luz::lightFV(){
	const GLfloat pos[4]={posicion.x,posicion.y,posicion.z,1.0}; //Luz posicional w=1.0
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
}