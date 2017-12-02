#include "figura.h"
#include <cmath>

Figura::Figura(){
        n_vertices = n_caras = 0;
        anchoMax = altoMax = 0;
}

Figura::Figura(vector<_vertex3f> v, vector<_vertex3i> c){
        insertarDatos(v,c);
        calcularNormales(); //Creamos las normales a las caras

}

void Figura::insertarDatos(vector<_vertex3f> v, vector<_vertex3i> c){
        this->vertices = v;
        this->caras = c;
        n_vertices = this->vertices.size();
        n_caras = this->caras.size();

        //Por defecto todos los vertices en gris
        for (int i=0; i<(n_vertices)*3; i++) { //vertices x RGB
                colores.push_back(0.5); //R
                colores.push_back(0.9); //G
                colores.push_back(0.5); //B
        }
        creaTabla();
        extremosFigura();
}

void Figura::setVertices(vector<_vertex3f> v){
        vertices = v;
        creaTabla();
}

vector<_vertex3f>Figura::getVertices(){
        return this->vertices;
}

void Figura::setCaras(vector<_vertex3i> c){
        caras = c;
        creaTabla();
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

void Figura::setColores(float r,float g,float b){
    //Borramos los colores
    this->colores.clear();

        for (int i=0; i<(n_vertices)*3; i++) { //vertices x RGB
                this->colores.push_back(r); //R
                this->colores.push_back(g); //G
                this->colores.push_back(b); //B
        }
}

float Figura::getAltoMax(){
        return altoMax;
}

float Figura::getAnchoMax(){
        return anchoMax;
}

float Figura::getAltoMin(){
        return altoMin;
}

float Figura::getAnchoMin(){
        return anchoMin;
}

void Figura::extremosFigura(){
        anchoMax = anchoMin = vertices[0].x;
        altoMax = anchoMin = vertices[0].y;

        for (int i=0; i<vertices.size(); i++) {
                if (vertices[i].x > anchoMax)
                        anchoMax = vertices[i].x;
                if (vertices[i].y > altoMax)
                        altoMax = vertices[i].y;
                if (vertices[i].x< anchoMin)
                        anchoMin = vertices[i].x;
                if (vertices[i].y<altoMin)
                        altoMin = vertices[i].y;
        }
}

bool Figura::tieneTapas(){
        _vertex3f tapaSuperior = vertices[0];
        _vertex3f tapaInferior = vertices[0];

        for (int i=0; i<vertices.size(); i++) {
                if (vertices[i].y > tapaSuperior.y)
                        tapaSuperior = vertices[i];

                if (vertices[i].y<tapaInferior.y)
                        tapaInferior = vertices[i];
        }

        if (tapaInferior.x==0.0 && tapaInferior.z==0.0)
                return true;
        else return false;
}

vector<_vertex3f> Figura::productoVectorial(vector<_vertex3f>P, vector<_vertex3f> Q){
// Nx = Py*Qz - Pz*Qy
// Ny = Pz*Qx - Px*Qz
// Nz = Px*Qy - Py*Qx
        float x,y,z = 0.0;

        x = (P.back().y*Q.back().z) - (P.back().z*Q.back().y);
        y = (P.back().z*Q.back().x) - (P.back().x*Q.back().z);
        z = (P.back().x*Q.back().y) - (P.back().y*Q.back().x);

        vector<_vertex3f>N;

        N.push_back({x,y,z});

        return N;
}

void Figura::calcularNormales(){
        //P = V2-V1 = (x2,y2,z2)-(x1,y1,z1) = (x2-x1, y2-y1, z2-z1)

        //Q = V3-V1 = (x3,y3,z3)-(x1,y1,z1) = (x3-x1, y3-y1, z3-z1)

        vector<_vertex3f> vectorP,vectorQ;

        if (vertices.size()>0 && caras.size()>0)
        for (int i=0; i<caras.size(); i++) {
                float x = vertices[caras[i][1]].x - vertices[caras[i][0]].x;
                float y = vertices[caras[i][1]].y - vertices[caras[i][0]].y;
                float z = vertices[caras[i][1]].z - vertices[caras[i][0]].z;

                //añadimos las coordenadas de P
                vectorP.push_back({x,y,z});

                x = vertices[caras[i][2]].x - vertices[caras[i][0]].x;
                y = vertices[caras[i][2]].y - vertices[caras[i][0]].y;
                z = vertices[caras[i][2]].z - vertices[caras[i][0]].z;

                vectorQ.push_back({x,y,z});

                vector<_vertex3f> N = productoVectorial(vectorP,vectorQ);

                //Calculamos el módulo
                float modulo = sqrt((N.back().x*N.back().x) + (N.back().y*N.back().y) + (N.back().z*N.back().z));

                //Normalizamos Nx/modulo, Ny/modulo, Nz/modulo
                normales.push_back({N.back().x/modulo,N.back().y/modulo,N.back().z/modulo});

                //Punto central de la cara
                float puntoX = (vertices[caras[i][0]].x + vertices[caras[i][1]].x + vertices[caras[i][2]].x)/3;
                float puntoY = (vertices[caras[i][0]].y + vertices[caras[i][1]].y + vertices[caras[i][2]].y)/3;
                float puntoZ = (vertices[caras[i][0]].z + vertices[caras[i][1]].z + vertices[caras[i][2]].z)/3;

                //Metemos punto central en el vector
                centroCaras.push_back({puntoX,puntoY,puntoZ});
        }
         glEnable(GL_NORMALIZE);
         glEnable(GL_RESCALE_NORMAL);
         for (int i=0;i<normales.size();i++) //Añadimos el vector de normales
            glNormal3f(normales[i].x,normales[i].y,normales[i].z);
}

void Figura::draw(int tipo, float tamanioPunto){

        glPointSize(tamanioPunto);
        //Activamos vertices y el color
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_COLOR_ARRAY);
        glColorPointer(3,GL_INT, 0, &colores[0]); //Establecemos el color
        glVertexPointer(3, GL_FLOAT, 0,  &vertices[0]);
        glEnable(GL_NORMALIZE);

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
        if (normales.size()<=0) //Para evitar recalcular cada vez que se pinta
                calcularNormales();

        glPointSize(5);
        glLineWidth(1.5);
        glColor3f(0,0,1);
        lineas();

        glBegin(GL_LINES);
        for(int i = 0; i<normales.size(); i++) {
                glVertex3f(centroCaras[i].x,centroCaras[i].y,centroCaras[i].z);
                glVertex3f((centroCaras[i].x+normales[i].x), //Sumamos los vertices con las normales
                           (centroCaras[i].y+normales[i].y),
                           (centroCaras[i].z+normales[i].z));
        }
        glEnd();

}

void Figura::solido(){
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glDrawElements(GL_TRIANGLES, tablaCaras.size(), GL_UNSIGNED_INT,&tablaCaras[0]);
}


void Figura::lineas(){
        if (tablaCaras.size()>0 && tablaVertices.size()>0) {
                glPolygonMode(GL_FRONT, GL_LINE);
                glDrawElements(GL_TRIANGLES, tablaCaras.size(), GL_UNSIGNED_INT,&tablaCaras[0]);
        }
}

void Figura::puntos(){

        if (tablaCaras.size()>0 && tablaVertices.size()>0) {
                glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
                glDrawElements(GL_TRIANGLES, tablaCaras.size(), GL_UNSIGNED_INT,&tablaCaras[0]);
        }
}

void Figura::ajedrez(){
        if (tablaCaras.size()>0 && tablaVertices.size()>0) {
                std::vector<int> pares;
                std::vector<int> impares;
                std::vector<float> coloresImpares; //Vector auxiliar para guardar los colores de las caras impares

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
}


void Figura::creaTabla(){
        tablaVertices.clear(); //Si se vuelve a llamar, la tabla se destruye y se vuelve a construir
        tablaCaras.clear();
        tablaNormales.clear();

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

        for (int i=0; i<normales.size(); i++) {
                tablaNormales.push_back(normales[i].x);
                tablaNormales.push_back(normales[i].y);
                tablaNormales.push_back(normales[i].z);
        }
}

/**
Materiales
*/
void Figura::setMaterialNegro(){
    glMaterialf(GL_FRONT_AND_BACK,GL_EMISSION,1.0f);

    GLfloat colorAmbiente[]={0.0,0.0,0.0,1.0};
    GLfloat colorDifuso[]={0.0,0.0,0.0,1.0}; //Negro
    GLfloat colorEspecular[]={1.0,1.0,1.0,1.0};
    const GLfloat high_shininess[] = { 10.0f };

    glMaterialfv(GL_FRONT,GL_AMBIENT,colorAmbiente);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,colorDifuso);
    glMaterialfv(GL_FRONT,GL_SPECULAR,colorEspecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void Figura::setMaterialGris(){
    glMaterialf(GL_FRONT_AND_BACK,GL_EMISSION,1.0f);

    GLfloat colorAmbiente[]={0.0,0.0,0.0,1.0};
    GLfloat colorDifuso[]={0.5,0.5,0.5,1.0}; //Negro
    GLfloat colorEspecular[]={0.5,0.5,0.5,1.0};
    const GLfloat high_shininess[] = { 1.0f };

    glMaterialfv(GL_FRONT,GL_AMBIENT,colorAmbiente);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,colorDifuso);
    glMaterialfv(GL_FRONT,GL_SPECULAR,colorEspecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void Figura::setMaterialReflejos(){
    glMaterialf(GL_FRONT,GL_EMISSION,1.0f);

   GLfloat colorAmbiente[] = {0.0, 0.0, 0.0, 1.0};
  GLfloat colorDifuso[] = {0.9, 0.9, 0.9, 1.0}; //Reflejos blancos
  GLfloat colorEspecular[]={1,1,1,1};
    const GLfloat high_shininess[] = { 100.0f };

    glMaterialfv(GL_FRONT,GL_AMBIENT,colorAmbiente);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,colorDifuso);
    glMaterialfv(GL_FRONT,GL_SPECULAR,colorEspecular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}