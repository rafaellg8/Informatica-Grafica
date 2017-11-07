#include "Hexagono.h"

Hexagono::Hexagono(){
	this->vertices = {{-2.5,-7.0,0.0},{2.5,-7.0,0.0},{5.0,0.0,0.0},{2.5,7.0,0.0},{-2.5,7.0,0.0},{-5.0,0.0,0.0},
					 //Hexagono interior pequeño
					 {-1.0,-2.0,0.0},{1.0,-2.0,0.0},{2.0,0.0,0.0},{1.0,2.0,0.0},{-1.0,2.0,0.0},{-2.0,0.0,0.0},
					 {0.0,0.0,0.0}
					 };
	int size = static_cast<int>(vertices.size());

	//Hexagono exterior
	for (int i=0;i<6;i++)
		this->caras.push_back({i,(i+1)%6,size-1});

	//Hexagono interior
	for (int i=6;i<size-2;i++){
		this->caras.push_back({i,(i+1),size-1});
		cout<<i<<" "<<i+1<<" "<<size-1<<endl;
	}
	this->caras.push_back({11,6,12});
	insertarDatos(vertices,caras);
}

void Hexagono::pintar(int glType,float lado){
	draw(glType,lado);
}