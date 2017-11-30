#ifdef _WIN32
#include <windows.h>
#endif

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#endif

#include <cstdio>
#include <iostream>

#include <vector>
#include "escena.h"
#include "file_ply_stl.h"
#include "ObjetoPLY.h"
#include "Perfil.h"

#include "CazaTie.h"
#include "Luz.h"

int transformacion=0;

Perfil perfil;
CazaTie caza;
Luz luz;
Escena::Escena(){
        Front_plane=200;
        Back_plane=2000;
        Observer_distance = 4*Front_plane;
        Observer_angle_x = Observer_angle_y=0;
        ejes.changeAxisSize(5000);
        gltype = 0; //Inicializacion por defecto

        float lado=25;
        // cout<<"\nIntroduzca el tamaño de la arista de las figuras, se recomienda en torno a 25 para correcta visualizacion"<<endl;
        // cin>>lado;

        if (lado>0) {
                Cubo cubo(lado); //Creamos el cubo
                Tetraedro tetraedro(lado);
                Piramide piramide(lado);
                figuras.push_back(cubo); //Insertamos el cubo en la escena
                figuras.push_back(tetraedro);
                figuras.push_back(piramide);
        }
        else{
                Cubo cubo;
                Tetraedro tetraedro;
                Piramide piramide;
                figuras.push_back(cubo); //Insertamos el cubo en la escena
                figuras.push_back(tetraedro);
                figuras.push_back(piramide);
        }

        string inputFile="ant.ply";
        // cout<<"\nIntroduzca el nombre del fichero ply, sin direccion absoluta. Ej: cow.ply"<<endl;
        // cin>>inputFile;

        ObjetoPLY objPly("ply/"+inputFile);
        figuras.push_back(objPly); //SI tiene tapas no revolucionamos

        objPly = ObjetoPLY("ply/perfil.ply");

        if (objPly.tieneTapas()==false) {
                cout<<"\nNo tiene tapas --> revolucionamos"<<endl;
                perfil=Perfil(objPly.getVertices(),18);
                // perfil = Perfil("ply/perfil.ply");
                figuras.push_back(perfil);
        }

        vector<_vertex3f> trayectoria;
        //Trayectoria para el objeto por barrido
        trayectoria= {{0,-50,0},{25,-25,0},{25,25,0},{0,50,0},{-25,25,0},{-25,-25,0}};

        // Perfil barrido(trayectoria,100.5,true); //Trayectoria, distancia de barrido

        figuraActual = 0; //Por defecto la figura que se pinta será la primera
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

        glClearColor(1,1,1,1); // se indica cual sera el color para limpiar la ventana	(r,v,a,al)

        glEnable(GL_DEPTH_TEST); // se habilita el z-bufer

        this->change_projection();
        Width=UI_window_width/10;
        Height=UI_window_height/10;
        glViewport(0,0,UI_window_width,UI_window_height);
        luces();
}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {
        // Cubo cubo;
        if (figuraActual==5){
            caza.pintar(gltype,4.5);
            if (esferaIlu){
                //pintamos la esfera con su luz
            }
        }
        else{
            figuras[figuraActual].draw(gltype,4.5);
        }
}



void Escena::dibujar() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
        change_observer();
        draw_axis();
        draw_objects();
}

void Escena::animar(){
     if (caza.getAnimar())
        caza.animarte();
 }

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {
        std::cout << "Tecla" << Tecla1<< std::endl;
        switch (toupper(Tecla1)) {
        case 'Q':
                return 1;
                break;
        case 'P':
                gltype = 0;
                return 0;
                break;
        case 'L':
                gltype = 1;
                return 0;
                break;
        case 'F':
                gltype = 2;
                return 0;
                break;
        case 'A':
                gltype = 3;
                return 0;
                break;
        case '7':
                gltype = 4;
                return 0;
                break;

        case '1':
                figuraActual = 0;
                change_projection();
                return 0;
                break;

        case '2':
                figuraActual = 1;
                change_projection();
                return 0;
                break;

        case '3':
                figuraActual = 2;
                change_projection();
                return 0;
                break;

        case '4':
                figuraActual = 3;
                change_projection();
                return 0;
                break;

        case '5':
                cout<<"\nPintando revolucion completa"<<endl;
                figuraActual = 4;
                perfil.pinta(true,true,true);
                figuras[4]=perfil; //Perfil actualizado
                change_projection();
                return 0;
                break;

        case '6':
                figuraActual = 5;
                change_projection();
                return 0;
                break;

        case '0':                                 //Pintar todo menos la parte de arriba
                cout<<"\nRevolucion por parametros. Introduzca numero divisiones y pulse enter"<<endl;
                int divi;         //Divisiones
                cin>>divi;
                figuraActual = 4;
                perfil = Perfil(perfil.getPerfil(),divi);
                figuras[4]=perfil;
                change_projection();
                return 0;
                break;

        //Iluminacion
        case 'I':
                luz.setEnable();
                esferaIlu=!esferaIlu; //Cambiamos la iluminacion la esfera
                return 0;
                break;
        //Sombreado plano
        case 'S':
                this->setShading();
                 if (shadingSmooth)
                    glShadeModel(GL_SMOOTH);
                else glShadeModel(GL_FLAT);
                return 0;
                break;
        }

        switch(Tecla1){
        //Grados de libertad
        case 32: //Espacio
                figuraActual=5;
                caza.mueveDisparo();
                return 0;
                break;
                
        case 'C':
                figuraActual=5;
                caza.upRotZ();
                return 0;
                break;

        case 'X':
                figuraActual=5;
                caza.upRotY();
                return 0;
                break;

        case 'Z':
                figuraActual=5;
                caza.upRotX();
                return 0;
                break;

        case 'c':
                figuraActual=5;
                caza.downRotZ();
                return 0;
                break;

        case 'x':
                figuraActual=5;
                caza.downRotY();
                return 0;
                break;
        case 'z':
                figuraActual=5;
                caza.downRotX();
                return 0;
                break;

        case 'B':
                figuraActual=5;
                caza.upVelocidadX();
                return 0;
                break;
        case 'N':
                figuraActual=5;
                caza.upVelocidadY();
                return 0;
                break;
        case 'M':
                figuraActual=5;
                caza.upVelocidadZ();
                return 0;
                break;

        case 'b':
                figuraActual=5;
                caza.downVelocidadX();
                return 0;
                break;
        case 'n':
                figuraActual=5;
                caza.downVelocidadY();
                return 0;
                break;
        case 'm':
                figuraActual=5;
                caza.downVelocidadZ();
                return 0;
                break; 

        case '<':
                figuraActual=5;
                caza.setAnimar();//Pone animar a true o false, en funcion de como estuviese el estado anterior
                //Por defecto esta falso
                return 0;
                break;
        }
        return 0; //Si no es ninguna de esta tecla, siempre devuelva algo
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
        switch (Tecla1) {
        case GLUT_KEY_LEFT: Observer_angle_y--; break;
        case GLUT_KEY_RIGHT: Observer_angle_y++; break;
        case GLUT_KEY_UP: Observer_angle_x--; break;
        case GLUT_KEY_DOWN: Observer_angle_x++; break;
        case GLUT_KEY_PAGE_UP: Observer_distance*=1.2; break;
        case GLUT_KEY_PAGE_DOWN: Observer_distance/=1.2; break;
        case GLUT_KEY_F1: luz.moverAdelante();break;
        case GLUT_KEY_F2: luz.moverAtras();luz.girar();break;
        case GLUT_KEY_F3: luz.upRotate();luz.girar();break;
        case GLUT_KEY_F4: luz.downRotate();break;
        }

        std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformaci�n de proyeccion
//***************************************************************************

void Escena::change_projection()  {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        
        float ancho,alto;
        caza.obtenerExtremos(ancho,alto);

        if (figuraActual==5){//Caza Tie
            glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
        }else{
        glFrustum(-figuras[figuraActual].getAnchoMax(),
                  figuras[figuraActual].getAnchoMax(),
                  -figuras[figuraActual].getAltoMax(),
                  figuras[figuraActual].getAltoMax(),
                  Front_plane,
                  Back_plane);
    }
}


void Escena::redimensionar(int newWidth,int newHeight) {
        change_projection();
        Width=newWidth/10;
        Height=newHeight/10;
        glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0,0,-Observer_distance);
        glRotatef(Observer_angle_x,1,0,0);
        glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
        ejes.draw();
}

void Escena::luces(){
         luz.posicionarLuces();
         luz.inicializarLuces();
}

void Escena::setShading(){ //Cambiamos el estado del shading
    shadingSmooth = !shadingSmooth;
}
