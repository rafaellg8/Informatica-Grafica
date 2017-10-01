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

        //Por defecto todos los vertices en amarillo
        for (int i=0; i<(n_vertices)*3; i++) { //vertices x RGB
                colores.push_back(0.0); //R
                colores.push_back(0.9); //G
                colores.push_back(0.5); //B
        }

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

void Figura::draw(int tipo, float tamanioPunto){

        glPointSize(tamanioPunto);


        //Activamos vertices y el color
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3,GL_INT, 0, &colores[0]);
        glVertexPointer(3, GL_FLOAT, 0,  &vertices[0]);

        std::vector<int> pares;
        std::vector<int> impares;
        std::vector<float> coloresImpares; //Vector auxiliar para guardar los colores de las caras impares

        switch (tipo) {
        case 0:
                glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
                glDrawElements(GL_TRIANGLES, tablaCaras.size(), GL_UNSIGNED_INT,&tablaCaras[0]);
                break;

        case 1:
                glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
                glDrawElements(GL_TRIANGLES, tablaCaras.size(), GL_UNSIGNED_INT,&tablaCaras[0]);
                break;

        case 2:
                glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
                glDrawElements(GL_TRIANGLES, tablaCaras.size(), GL_UNSIGNED_INT,&tablaCaras[0]);
                break;

        case 3:
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
                break;
        }
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
}
