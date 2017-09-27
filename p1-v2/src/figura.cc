#include "figura.h"

Figura::Figura(){
  n_vertices = n_caras = 0;
}

Figura::Figura(vector<_vertex3f> v, vector<_vertex3i> c){
  insertarDatos(v,c);
}

void Figura::insertarDatos(vector<_vertex3f> v, vector<_vertex3i> c){
  this->vertices = v;
  this->caras = c;
  n_vertices = this->vertices.size();
  n_caras = this->caras.size();
  creaTabla();
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

void Figura::draw(GLenum tipo, float tamanioPunto){

  glPointSize(tamanioPunto);

  if (tipo==GL_POINTS){
    glBegin(tipo);
  for (int i=0;i<n_vertices;i++){
  	// glVertex3fv((GLfloat *) &v_cubo[i]);
  		 glVertex3fv((GLfloat *) &this->vertices[i]);
  	}
    glEnd();
  }
    else{
      // glEnableClientState( GL_VERTEX_ARRAY ); //habilitar vertex array
      // // especificar puntero a tabla de coords. de vértices
      // glVertexPointer( 3, GL_FLOAT, 0,&vertices[0]);
      // // dibujar usando vértices indexados
      // glDrawElements( GL_TRIANGLES, tamanioTabla+1,GL_UNSIGNED_INT, &tablaVertices[0][0]);
      for (int i=0;i<n_caras;i++){

          if (tipo == GL_LINES){
            glBegin(GL_LINE_LOOP);
            glVertex3fv((GLfloat *) &vertices[caras[i][0]]);
            glVertex3fv((GLfloat *) &vertices[caras[i][1]]);
            glVertex3fv((GLfloat *) &vertices[caras[i][2]]);
          }
          else if (tipo == GL_TRIANGLES) //Triangulos
          {
            glBegin(tipo);
            glVertex3fv((GLfloat *) &vertices[caras[i][0]]);
            glVertex3fv((GLfloat *) &vertices[caras[i][1]]);
            glVertex3fv((GLfloat *) &vertices[caras[i][2]]);
          }else {//ajedrez
            glBegin(tipo);
            if (i%2 == 0)
              glColor3f(255.0,0.0,0.0);
            else
              glColor3f(0,255.0,0);

            glVertex3fv((GLfloat *) &vertices[caras[i][0]]);
            glVertex3fv((GLfloat *) &vertices[caras[i][1]]);
            glVertex3fv((GLfloat *) &vertices[caras[i][2]]);
          }
        glEnd();
      }
    }
}

void Figura::creaTabla(){
  for (int i=0;i<n_caras;i++){
    tablaVertices.push_back(vertices[i].x); //Vamos asignando cada 3 caras los 3 vertices, tenemos una tabla de vertices repetidos con las caras
    tablaVertices.push_back(vertices[i].y);
    tablaVertices.push_back(vertices[i].z);
  }
  tamanioTabla = tablaVertices.size();
}
