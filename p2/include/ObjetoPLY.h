#ifndef _OBJETOPLY_
#define _OBJETOPLY_
#include "file_ply_stl.h"
#include "figura.h"
#include "cstring"

class ObjetoPLY : public Figura{
private:
  _file_ply file;
public:
  ObjetoPLY();
  ObjetoPLY(string fileInput);
};

#endif
