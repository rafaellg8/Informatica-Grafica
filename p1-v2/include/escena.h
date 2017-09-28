#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "figura.h"
#include "cubo.h"
#include "tetraedro.h"
#include "piramide.h"

#include <vector>

class Escena {
private:
// tama�o de los ejes
#define AXIS_SIZE 5000
Ejes ejes;

//Vector de figuras en la escena
vector<Figura> figuras;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;
int gltype; //0 puntos, 1 lineas, 2 solido, 3 ajedrez
// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Width,Height,Front_plane,Back_plane;

int figuraActual = 0; //figura actual que se va a pintar

private:
	void clear_window();
	void draw_axis();
	void draw_objects();

//Transformaci�n de c�mara
	void change_projection();
	void change_observer();


public:
  Escena();
	void inicializar(int UI_window_width,int UI_window_height);
	void redimensionar(int newWidth,int newHeight) ;

	// Dibujar
	void dibujar() ;

	// Interacci�n con la escena
	int teclaPulsada(unsigned char Tecla1,int x,int y) ;
	void teclaEspecial(int Tecla1,int x,int y);
	void setTipo(int tipo);
};
#endif
