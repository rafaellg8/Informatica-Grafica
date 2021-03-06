#ifndef _figura_
#define _figura_

#include <cstdlib>
#include <vector>
#include "vertex.h"

class Figura {
private:
  std::vector<_vertex3f> vertices;
  std::vector<_vertex3i> caras;
  int n_vertices;
  int n_caras;

public:
  //Constructor
  Figura();
  /**
  @brief Constructor con parametros de vertices y caras
  */
  Figura(std::vector<_vertex3f> v, std::vector<_vertex3i> c);

  /**
  @brief Devuelve el vector de vertices
  */
  vector<_vertex3f> getVertices();

  /**
  @brief Devuelve el vector de caras
  */
  vector<_vertex3i> getCaras();

  int getVerticesSize();

  int getCarasSize();
};

#endif
