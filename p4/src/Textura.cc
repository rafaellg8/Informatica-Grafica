#include "Textura.h"

Textura::Textura(){
	m=10000;
	n=10000;
	inicializarCuadro(10,10);
	cargarTextura("lavaredo.bmp");
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
	carasTex = {{0,3,1},{2,3,0}};
}

void Textura::cargarTextura(string file){
	TexBits = LoadDIBitmap(file.c_str(),&TexInfo);
}

int Textura::getM(){return m;}

int Textura::getN(){return n;}

void Textura::dibujarTextura(){
	
	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,GL_SINGLE_COLOR);
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

		   glBegin(GL_TRIANGLES);

		   for(int i=0; i<caras.size(); ++i) {
		     
		       glTexCoord2f(verticesTex[carasTex[i]._0].x,verticesTex[carasTex[i]._0].y);
		     glVertex3fv((GLfloat *) &vertices[caras[i]._0]);

		     
		       glTexCoord2f(verticesTex[caras[i]._1].x,verticesTex[caras[i]._1].y);
		     glVertex3fv((GLfloat *) &vertices[caras[i]._1]);

		     
		       glTexCoord2f(verticesTex[caras[i]._2].x,verticesTex[caras[i]._2].y);
		     glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		   }

		   glEnd();


		glDisable(GL_TEXTURE_2D);
			
	}
	else{
		cargarTextura("imperial.bmp");
		dibujarTextura();
	}
}