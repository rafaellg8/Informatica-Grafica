#include "ObjetoPLY.h"

ObjetoPLY::ObjetoPLY(){
}

ObjetoPLY::ObjetoPLY(string fileInput){
  //vectores auxiliares
  std::vector<_vertex3f> v;
  std::vector<_vertex3i> c;
  if (file.open(fileInput)){
    file.read(v,c);
    std::cout << "File read correctly" << std::endl;
  }
  else std::cout << "File can't be opened" << std::endl;

  insertarDatos(v,c);
}
