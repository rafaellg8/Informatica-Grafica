#include "figura.h"

Figura::Figura(){
  n_vertices = n_caras = 0;
}

Figura::Figura(vector<_vertex3f> v, vector<_vertex3i> c){
  this->vertices = v;
  this->caras = c;
  n_vertices = this->vertices.size();
  n_caras = this->caras.size();
}

vector<_vertex3f>Figura::getVertices(){
  return this->vertices;
}


vector<_vertex3i>Figura::getCaras(){
  return this->caras;
}

int Figura::getVerticesSize(){
  return n_vertices;
}

int Figura::getCarasSize(){
  return n_caras;
}
