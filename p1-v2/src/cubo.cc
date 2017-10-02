#include "cubo.h"

Cubo::Cubo(){
        //Inicializamos
        std::vector<_vertex3f> vertices = {{0,0,0},{50,0,0},{50,50,0},{0,50,0},{0,0,50},{50,0,50},{50,50,50},{0,50,50}};
        std::vector<_vertex3i>caras = {{0,1,2},{0,2,3},{1,5,6},{1,6,2},{5,4,7},{5,7,6},{4,0,3},{4,3,7},{3,2,6},{3,6,7},{4,5,1},{4,1,0}}; //Triangulos

        insertarDatos(vertices,caras);
}

Cubo::Cubo(std::vector<_vertex3f> v,std::vector<_vertex3i> c){
        insertarDatos(v,c);
}
