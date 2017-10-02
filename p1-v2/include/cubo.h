/**
Class: Cubo

Author: Rafael Lachica Garrido

Description: Clase cubo que contiene las coordenas de un cubo dentro del constructor, en el espacio 3d

*/
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
