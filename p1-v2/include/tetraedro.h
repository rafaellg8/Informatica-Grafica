#ifndef _TETRAEDRO_
#define _TETRAEDRO_
#include "figura.h"

using namespace std;

class Tetraedro : public Figura{

public:
  Tetraedro();
  Tetraedro(vector<_vertex3f> ver, vector<_vertex3i> caras);
};

#endif
