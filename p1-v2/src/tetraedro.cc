#include "tetraedro.h"

Tetraedro::Tetraedro(){
        //Inicializamos
        std::vector<_vertex3f> vertices = {{-50,0,50},{50,0,50},{0,0,-50},{0,50,0}};
        std::vector<_vertex3i>caras = {{0,1,3},{1,2,3},{0,3,2},{2,1,0}}; //Triangulos

        insertarDatos(vertices,caras);
}

Tetraedro::Tetraedro(float lado){
        //Inicializamos
        std::vector<_vertex3f> vertices = {{-lado,0,lado},{lado,0,lado},{0,0,-lado},{0,lado,0}};
        std::vector<_vertex3i>caras = {{0,1,3},{1,2,3},{0,3,2},{2,1,0}}; //Triangulos

        insertarDatos(vertices,caras);
}

Tetraedro::Tetraedro(std::vector<_vertex3f> v,std::vector<_vertex3i> c){
        insertarDatos(v,c);
}
