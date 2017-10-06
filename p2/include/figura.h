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
  std::vector<_vertex3f> vertices;
  std::vector<_vertex3i> caras;
  std::vector<float> tablaVertices;//Correspondencia vertices y caras
  std::vector<int> tablaCaras;//Correspondencia vertices y caras
  std::vector<float> colores; //Color para cada vertice
  int n_vertices;
  int n_caras;
  int tamanioTabla;

protected:
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
  Devuelve el vector de caras
  */
  vector<_vertex3i> getCaras();

  int getVerticesSize();

  int getCarasSize();

  void draw(int tipo,float tamanioPunto);

  void ajedrez();

  void puntos();

  void solido();

  void lineas();

  /**
  Tabla de Triangulos, con las caras
  */
  void creaTabla();
};

#endif
