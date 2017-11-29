#include "Luz.h"


#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#endif

Luz::Luz(){
	color.x =1;
	color.y =1;
	color.z =0; //Por defecto amarillo
	color[4]=0;
	posicion(0,0,0,1.0); //Posicion por defecto

	

	enable = false;
	creaEsfera();
	
	// inicializarLuces();
	// posicionarLuces();
	//Posicionamos la esfera justo donde está la luz

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
    const float
         caf[4] = { 1.0, 0.0, 0.0, 1.0 }, 
         // color ambiental de la fuente 
         cdf[4] = { 0.2, 0.2, 0.2, 1.0 }, //
         //color difuso de la fuente 
         csf[4] = { 0, 0.0, 1.0, 1.0 }; 
         //color especular de la fuente 
         glLightfv( GL_LIGHT0, GL_AMBIENT, caf ) ; //
         //hace SiA := (ra, ga, ba) 
         glLightfv( GL_LIGHT1, GL_DIFFUSE, cdf ) ; //
         //hace SiD := (rd, gd, bd) 
         glLightfv( GL_LIGHT2, GL_SPECULAR, csf ) ; //
         // hace SiS := (rs, gs, bs) 
         glEnable(GL_LIGHT0);
}

void Luz::posicionarLuces(){
	glLightModeli( GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE ); //Si Proyeccion en perspectiva
	const GLfloat posf[4] = { 0, 0, 0, 1.0 } ;  // (x,y,z,w) 
	// glLightfv( GL_LIGHT0, GL_POSITION, posf ); 
	const GLfloat dirf[4] = { 0, 0, 0, 0.0 } ; // (x,y,z,w) 
    glLightfv(GL_LIGHT0,GL_POSITION,dirf);
    posicion(0,0,0);
}

void Luz::pintar(int glType, float lado){
	if (esfera.getVertices().size()>0 && esfera.getCaras().size()>0){
		glPushMatrix();
		glScalef(100,100,100);
		glTranslatef(0,0,0);
			esfera.draw(glType,lado);
		glPopMatrix();
	}
}

vector<_vertex3f> Luz::getEsferaVertices(){
	return esfera.getVertices();
}

void Luz::creaEsfera(){
	cout<<"\nCreando la esfera "<<endl;
	esfera = ObjetoPLY("ply/sphere.ply");
	//Invertimos las normales de la esfera
	for (int i=0;i<esfera.normales.size();i++){
		esfera.normales[i].x*=-1;
		esfera.normales[i].y*=-1;
		esfera.normales[i].z*=-1;
		glNormal3f(esfera.normales[i].x,esfera.normales[i].y,esfera.normales[i].z);
	}
	esfera.setColores(0,0,0);
}

void Luz::moverAdelante(){
	posicion.z +=10;
	const GLfloat pos[4]={posicion.x,posicion.y,posicion.z,1.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	cout<<posicion.z<<endl;
}

void Luz::moverAtras(){
	posicion.z -=10;
	const GLfloat pos[4]={posicion.x,posicion.y,posicion.z,1.0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	cout<<posicion.z<<endl;

}