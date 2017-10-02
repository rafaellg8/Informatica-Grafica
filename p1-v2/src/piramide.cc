#include "piramide.h"

Piramide::Piramide(){
        //Inicializamos
        std::vector<_vertex3f> vertices = {{0,0,0},{50,0,0},{50,0,50},{0,0,50},{25,50,25}};
        std::vector<_vertex3i>caras = {{0,1,4},{1,2,4},{2,3,4},{3,0,4},{3,2,1},{3,1,0}}; //Triangulos

        insertarDatos(vertices,caras);
}

Piramide::Piramide(std::vector<_vertex3f> v,std::vector<_vertex3i> c){
        insertarDatos(v,c);
}
