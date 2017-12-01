#include "Direccional.h"

Direccional::Direccional(){
	color.x =10;
	color.y =0;
	color.z =0; //Por defecto amarillo
	color[4]=0;
	posicion(5,0,0,1.0); //Posicion direccional
	enable = false;
	grados = 0; //Grados de rotacion
}

void Direccional::enableLight(){
	glEnable(GL_LIGHT1);
}

void Direccional::inicializarLuces(){
	glEnable(GL_LIGHTING);
   
   	const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 
    const GLfloat light_diffuse[] = { color.x, color.y, color.z, 1.0f };
    const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient); 
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse); 
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular); 

    glEnable(GL_LIGHT1);
}

void Direccional::posicionarLuces(){
	glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE ); //Si Proyeccion en perspectiva
	const GLfloat posf[4] = { posicion.x,posicion.y,posicion.z,posicion.w} ;  // (x,y,z,w) 
	// glLightfv( GL_LIGHT0, GL_POSITION, posf ); 
    glLightfv(GL_LIGHT1,GL_POSITION,posf);
}

void Direccional::mover(){
	glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE ); //Si Proyeccion en perspectiva
	const GLfloat posf[4] = { posicion.x,posicion.y,posicion.z,posicion.w} ;  // (x,y,z,w) 
	// glLightfv( GL_LIGHT0, GL_POSITION, posf ); 
    glLightfv(GL_LIGHT1,GL_POSITION,posf);
}

void Direccional::lightFV(){
	const GLfloat pos[4]={posicion.x,posicion.y,posicion.z,1.0}; //Luz posicional w=1.0
	glLightfv(GL_LIGHT1,GL_POSITION,pos);
}

void Direccional::girar(){
	glPushMatrix();
		glRotatef(grados,0,1,0);
		this->lightFV();
	glPopMatrix();
}


void Direccional::moverAdelante(){
	posicion.z +=10;
	this->lightFV();
	cout<<posicion.z<<endl;
}

void Direccional::moverAtras(){
	posicion.z -=10;
	this->lightFV();
	cout<<posicion.z<<endl;
}
