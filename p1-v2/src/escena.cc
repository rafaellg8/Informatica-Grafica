#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
// #include "figura.h"
#include "vertex.h"
#include "cubo.h"

GLenum gltipo;

Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);
    gltype = GL_POINTS; //Inicializacion por defecto

    Cubo cubo; //Creamos el cubo
    figuras.push_back(cubo); //Insertamos el cubo en la escena

}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
  std::vector<_vertex3f> v_cubo {{0,0,0},{50,0,0},{50,50,0},{0,50,0},{0,0,50},{50,0,50},{50,50,50},{0,50,50}}; //Vertices cubo
  //Caras del cubo
  std::vector<_vertex3i> c_cubo {{0,1,2},{0,2,3},{1,5,6},{1,6,2},{5,4,7},{5,7,6},{4,0,3},{4,3,7},{3,2,6},{3,6,7},{4,5,1},{4,1,0}};


  // Cubo cubo;
  figuras[0].draw(gltype,4.5);
  // Figura figura(v_cubo,c_cubo);
  // figura.draw(gltype,4.5);
}



void Escena::dibujar() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {
  std::cout << "Tecla" << Tecla1<< std::endl;
	if (toupper(Tecla1)=='Q') return 1;
  else if (toupper(Tecla1)=='P'){
    gltype = GL_POINTS;
    return 0;
  }
  else if (toupper(Tecla1)=='L'){
    gltype = GL_LINES;
    return 0;
  }
  else if (toupper(Tecla1)=='T'){
    gltype = GL_TRIANGLES;
    return 0;
  }
  else if (toupper(Tecla1)=='A'){
    gltype = GL_TRIANGLE_STRIP;
    return 0;
  }
  else return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformaci�n de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformaci�n de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}
