#include "figura.h"

Figura::Figura(){

};

Figura::Figura(vector<_vertex3f> v, vector<_vertex3i> c){
  this->vertices = v;
  this->caras = c;
}
