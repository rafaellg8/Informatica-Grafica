#ifndef _figura_
#define _figura_

#include <cstdlib>
#include <vector>
#include "vertex.h"
#include "stdlib.h"
#include "stdio.h"
#include <GL/glut.h>

class Figura {
private:

std::vector<_vertex3f> centroCaras; //Centro de cada cara
std::vector<float> tablaVertices;  //Correspondencia vertices y caras
std::vector<int> tablaCaras;  //Correspondencia vertices y caras
std::vector<float> colores;   //Color para cada vertice
std::vector<float> tablaNormales;

int n_vertices;
int n_caras;
int tamanioTabla;
float anchoMax;
float altoMax;
float anchoMin;
float altoMin;

  /**
  Función que recorre la figura y muestra los extremos máximos, altura y anchura de la figura.
  */
  void extremosFigura();

  vector<_vertex3f> productoVectorial(vector<_vertex3f> vectorP, vector<_vertex3f> vectorQ);

protected:
std::vector<_vertex3f> vertices;
std::vector<_vertex3i> caras;

/**
   Funcion para insertar los vertices y caras
 */
void insertarDatos(vector<_vertex3f> v,vector<_vertex3i> c);

public:
//Constructor
Figura();
/**
   Constructor con parametros de vertices y caras
 */
Figura(std::vector<_vertex3f> v, std::vector<_vertex3i> c);

/**
   Devuelve el vector de vertices
 */
vector<_vertex3f> getVertices();

/**
Añadir vertices
*/
void setVertices(vector<_vertex3f> vertices);
/**
   Devuelve el vector de caras
 */
vector<_vertex3i> getCaras();

/**
Añadir caras
*/
void setCaras(vector<_vertex3i> caras);

int getVerticesSize();

int getCarasSize();

void draw(int tipo,float tamanioPunto);

void ajedrez();

void puntos();

void solido();

void lineas();

void tipoNormales();

float getAltoMax();

float getAnchoMax();

float getAltoMin();

float getAnchoMin();

void calcularNormales();

void setColores(float r,float g,float b);

void setColores(vector<float> colores);

bool tieneTapas(); //Comprueba que tenga alguna tapa

/**
Tabla de Triangulos, con las caras. Tabla de normales
*/
void creaTabla();

std::vector<_vertex3f> normales;
};

#endif
