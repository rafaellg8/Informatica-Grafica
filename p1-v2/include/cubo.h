#ifndef _CUBO_
#define _CUBO_
#include "figura.h"

using namespace std;

class Cubo : public Figura{

public:
  Cubo();
  Cubo(vector<_vertex3f> ver, vector<_vertex3i> caras);
};

#endif
