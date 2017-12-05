#include "Textura.h"

Textura::Textura(){
	m=10;
	n=10;
	inicializarCuadro(10,10);
	cargarTextura("imperial");
	// dibujarTextura();
}

void Textura::inicializarCuadro(float m,float n){
	vector<_vertex3f> ver;
	vector<_vertex3i> car;
	ver = {{-m,n,0},{m,n,0},{-m,-n,0},{m,-n,0}}; //Pasamos los vertices cuadrado
	// cuadro.setVertices(ver);
	car = {{0,3,1},{2,3,0}};
	// cuadro.setCaras(car);
	this->insertarDatos(ver,car);

	//Ahora rellenamos el vector de vertices y caras para la textura,  también en forma de triangulos
	verticesTex = {{1.0,1.0},{0.0,1.0},{1.0,0.0},{0.0,0.0}};
	carasTex = {{0,3,1},{0,2,3}};
}

void Textura::cargarTextura(string file){
	TexBits = LoadDIBitmap("imperial.bmp",&TexInfo);
}

int Textura::getM(){return m;}

int Textura::getN(){return n;}

void Textura::dibujarTextura(){
	

	//Los vertices de la textura van de 1.0 a 0.0 t, igual para s
	//Creamos un vector de vertices y de caras para la textura
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (TexBits!=NULL){
		glTexImage2D(GL_TEXTURE_2D, 0, 3,
		 TexInfo->bmiHeader.biWidth, TexInfo->bmiHeader.biHeight,
		  0, GL_BGR_EXT, GL_UNSIGNED_BYTE, TexBits); //Imagen 2d textura
		//Parametros de la textura
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		//Color a blanco por defecto
		// glColor3f(1.0,1.0,1.0);
		
		//Activar texturas
		glEnable(GL_TEXTURE_2D);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		//Dibujamos el cuadrado
		glBegin(GL_POLYGON);
		//Asignamos a cada vertice la textura correspondiente
		glTexCoord2f(1.0,1.0);
		glVertex2f(vertices[0].x,vertices[0].y);
		glTexCoord2f(1.0,0.0);
		glVertex2f(vertices[2].x,vertices[2].y);
		glTexCoord2f(0.0,0.0);
		glVertex2f(vertices[3].x,vertices[3].y);
		glTexCoord2f(0.0,1.0);
		glVertex2f(vertices[1].x,vertices[1].y);
		glEnd();

		// glBegin(GL_TRIANGLES);
		// for (int i=0;i<static_cast<int>(caras.size());i++){
		// 	glTexCoord2f(verticesTex[carasTex[i].x].x,verticesTex[carasTex[i].y].y);
		// 	glVertex2f(vertices[caras[i].x].x,vertices[caras[i].y].y);
		// }
		// glEnd();


		glDisable(GL_TEXTURE_2D);
			
	}
	else{
		cargarTextura("imperial.bmp");
		dibujarTextura();
	}
}