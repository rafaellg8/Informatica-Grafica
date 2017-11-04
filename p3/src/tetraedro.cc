#include "tetraedro.h"

Tetraedro::Tetraedro(){
        //Inicializamos
        std::vector<_vertex3f> vertices = {{0,0,0},{50,0,0},{25,50,25},{25,0,50}};
        std::vector<_vertex3i>caras = {{0,1,2},{1,3,2},{0,3,2},{2,1,0}}; //Triangulos

        insertarDatos(vertices,caras);
}

Tetraedro::Tetraedro(float lado){
        //Inicializamos
        std::vector<_vertex3f> vertices = {{0,0,0},{lado,0,0},{lado/2,lado,lado/2},{lado/2,0,lado}};
        std::vector<_vertex3i>caras = {{0,1,2},{1,3,2},{0,3,2},{2,1,0}}; //Triangulos

        insertarDatos(vertices,caras);
}

Tetraedro::Tetraedro(std::vector<_vertex3f> v,std::vector<_vertex3i> c){
        insertarDatos(v,c);
}
