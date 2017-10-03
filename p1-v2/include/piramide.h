/**
Class: Figura

Author: Rafael Lachica Garrido

Description: Piramide

*/

#ifndef _PIRAMIDE_
#define _PIRAMIDE_
#include "figura.h"

using namespace std;

class Piramide : public Figura{

public:
  Piramide();
  Piramide(float lado);
  Piramide(vector<_vertex3f> ver, vector<_vertex3i> caras);
  Piramide(vector<_vertex3f> ver, vector<_vertex3i> caras,float lado);
};

#endif
