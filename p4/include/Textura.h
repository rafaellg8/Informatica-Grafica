#ifndef _TEXTURA_H
#define _TEXTURA_H

#include "figura.h"
#include "Bitmap.h"


class Textura : public Figura
{
private:
	float m;
	float n; //Tamaño mxn
	BITMAPINFO *TexInfo; /* Texture bitmap information */ 
	GLubyte *TexBits; /* Texture bitmap pixel bits */
	void inicializarCuadro(float m,float n);

	//Valor de t y s para la textura
	std::vector<_vertex2f> verticesTex;
	std::vector<_vertex3i> carasTex; //Triangulo 3 componentes

public:
	Textura();
	int getM();
	int getN();
	void dibujarTextura();
	void cargarTextura(string file);
	
};
#endif