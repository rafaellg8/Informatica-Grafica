#include "figura.h"
#include <cmath>

Figura::Figura(){
        n_vertices = n_caras = 0;
        anchuraFigura = alturaFigura = 0;
}

Figura::Figura(vector<_vertex3f> v, vector<_vertex3i> c){
        insertarDatos(v,c);

}

void Figura::insertarDatos(vector<_vertex3f> v, vector<_vertex3i> c){
        this->vertices = v;
        this->caras = c;
        n_vertices = this->vertices.size();
        n_caras = this->caras.size();

        //Por defecto todos los vertices en amarillo
        for (int i=0; i<(n_vertices)*3; i++) { //vertices x RGB
                colores.push_back(0.0); //R
                colores.push_back(0.9); //G
                colores.push_back(0.5); //B
        }
        creaTabla();
        extremosFigura();
        calcularNormales(); //Creamos las normales a las caras
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

float Figura::getAltura(){
        return alturaFigura;
}

float Figura::getAnchura(){
        return anchuraFigura;
}

void Figura::extremosFigura(){
        anchuraFigura = vertices[0].x;
        alturaFigura = vertices[0].y;

        for (int i=0; i<vertices.size(); i++) {
                if (vertices[i].x >= anchuraFigura)
                        anchuraFigura = vertices[i].x;
                if (vertices[i].y >= alturaFigura)
                        alturaFigura = vertices[i].y;
        }
}

vector<_vertex3f> Figura::productoVectorial(vector<_vertex3f>P, vector<_vertex3f> Q){
// Nx = Py*Qz - Pz*Qy
// Ny = Pz*Qx - Px*Qz
// Nz = Px*Qy - Py*Qx
  float x,y,z = 0.0;

  x = P.back().y*Q.back().z - P.back().z*Q.back().y;
  y = P.back().z*Q.back().x - P.back().x*Q.back().z;
  z = P.back().x*Q.back().y - P.back().y*Q.back().x;

  vector<_vertex3f>N;
  N.push_back({x,y,z});

  return N;
}

void Figura::calcularNormales(){
  //P = V2-V1 = (x2,y2,z2)-(x1,y1,z1) = (x2-x1, y2-y1, z2-z1)

  //Q = V3-V1 = (x3,y3,z3)-(x1,y1,z1) = (x3-x1, y3-y1, z3-z1)

  vector<_vertex3f> vectorP,vectorQ;

  for (int i=0;i<caras.size();i+=3){
    float x = vertices[i+1].x - vertices[i].x;
    float y = vertices[i+1].y - vertices[i].y;
    float z = vertices[i+1].z - vertices[i].z;

    //añadimos las coordenadas de P
    vectorP.push_back({x,y,z});

    x = vertices[i+2].x - vertices[i].x;
    y = vertices[i+2].y - vertices[i].y;
    z = vertices[i+2].z - vertices[i].z;

    vectorQ.push_back({x,y,z});

    vector<_vertex3f> N = productoVectorial(vectorP,vectorQ);

    //Calculamos el módulo
    float modulo = sqrt(N.back().x*N.back().x + N.back().y*N.back().y + N.back().z*N.back().z);

    //Normalizamos Nx/modulo, Ny/modulo, Nz/modulo
    normales.push_back({N.back().x/modulo,N.back().y/modulo,N.back().z/modulo});
    normales.push_back({(N.back().x/modulo)+10,(N.back().y/modulo)+10,(N.back().z/modulo)+10});
  }
}

void Figura::draw(int tipo, float tamanioPunto){

        glPointSize(tamanioPunto);
        //Activamos vertices y el color
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3,GL_INT, 0, &colores[0]);
        glVertexPointer(3, GL_FLOAT, 0,  &vertices[0]);

        switch (tipo) {
        case 0:
                puntos();
                break;

        case 1:
                lineas();
                break;

        case 2:
                solido();
                break;

        case 3:
                ajedrez();
                break;
        case 4:
                tipoNormales();
                break;
        }
}

void Figura::tipoNormales(){
  puntos();
  glColor3f(1.5,0.0,0.0);
  glBegin(GL_LINES);
  glPointSize(3.5);
  for (int i=0;i<normales.size();i+=2){
    glVertex3f(normales[i].x,normales[i].y,normales[i].z);
    glVertex3f(normales[i+1].x,normales[i+1].y,normales[i+1].z);
    glEnd();
  }
}

void Figura::solido(){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDrawElements(GL_TRIANGLES, tablaCaras.size(), GL_UNSIGNED_INT,&tablaCaras[0]);
}


void Figura::lineas(){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_TRIANGLES, tablaCaras.size(), GL_UNSIGNED_INT,&tablaCaras[0]);
}

void Figura::puntos(){
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
        glDrawElements(GL_TRIANGLES, tablaCaras.size(), GL_UNSIGNED_INT,&tablaCaras[0]);
}

void Figura::ajedrez(){

        std::vector<int> pares;
        std::vector<int> impares;
        std::vector<float> coloresImpares;   //Vector auxiliar para guardar los colores de las caras impares

        //Ajedrez
        //Partimos las caras en 2 partes, las pares e impares
        if (pares.size()<1) { //No se ha inicializado la tabla pares o no tiene contenido, por ejemplo, estamos redibujando
                for (int i=0; i<caras.size(); i+=2) {
                        pares.push_back(caras[i][0]);
                        pares.push_back(caras[i][1]);
                        pares.push_back(caras[i][2]);

                        impares.push_back(caras[i+1][0]);
                        impares.push_back(caras[i+1][1]);
                        impares.push_back(caras[i+1][2]);
                }

                //Simplemente vamos pintar la mitad de las caras de otro color
                //Sobreescribir el color que ya tenemos
                for (int i=0; i<caras.size()/2; i++) {
                        for (int j=0; j<3; j++) {
                                coloresImpares.push_back(0.1);
                                coloresImpares.push_back(0.2);
                                coloresImpares.push_back(0.5);
                        }
                }
        }

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glColorPointer(3,GL_FLOAT, 0, &colores[0]);
        glDrawElements(GL_TRIANGLES, pares.size(), GL_UNSIGNED_INT,&pares[0]);
        glColorPointer(3,GL_FLOAT, 0, &coloresImpares[0]);
        glDrawElements(GL_TRIANGLES, impares.size(), GL_UNSIGNED_INT,&impares[0]);
}


void Figura::creaTabla(){
        for (int i=0; i<n_vertices; i++) {
                tablaVertices.push_back(vertices[i].x);
                tablaVertices.push_back(vertices[i].y);
                tablaVertices.push_back(vertices[i].z);
        }

        for (int i=0; i<n_caras; i++) {
                tablaCaras.push_back(caras[i].x); //Vamos asignando cada 3 caras los 3 caras, tenemos una tabla de caras repetidos con las caras
                tablaCaras.push_back(caras[i].y);
                tablaCaras.push_back(caras[i].z);
        }
        tamanioTabla = tablaCaras.size();

        for (int i=0;i<normales.size();i++){
                tablaNormales.push_back(normales[i].x);
                tablaNormales.push_back(normales[i].y);
                tablaNormales.push_back(normales[i].z);
        }
}
