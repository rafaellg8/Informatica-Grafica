/**
   Class: Figura

   Author: Rafael Lachica Garrido

   Description: Tetraedro

 */


#ifndef _TETRAEDRO_
#define _TETRAEDRO_
#include "figura.h"

using namespace std;

class Tetraedro : public Figura {

public:
  Tetraedro();
  Tetraedro(float lado);
  Tetraedro(vector<_vertex3f> ver, vector<_vertex3i> caras);
  Tetraedro(vector<_vertex3f> ver, vector<_vertex3i> caras,float lado);
};

#endif
