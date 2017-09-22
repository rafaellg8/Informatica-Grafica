#ifndef _figura_
#define _figura_

#include <cstdlib>
#include <vector>
#include "vertex.h"

class Figura {
private:
  std::vector<_vertex3f> vertices;
  std::vector<_vertex3i> caras;

public:
  //Constructor
  Figura();
  /**
  @brief Constructor con parametros de vertices y caras
  */
  Figura(std::vector<_vertex3f> v, std::vector<_vertex3i> c);

};

#endif
