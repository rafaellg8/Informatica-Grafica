#ifndef _PIRAMIDE_
#define _PIRAMIDE_
#include "figura.h"

using namespace std;

class Piramide : public Figura{

public:
  Piramide();
  Piramide(vector<_vertex3f> ver, vector<_vertex3i> caras);
};

#endif
