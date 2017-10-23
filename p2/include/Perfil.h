/**
Clase Perfil.
Se pasa un perfil y se revoluciona para construir el objeto deseado.

Autor: Rafael Lachica Garrido
*/

#ifndef _PERFIL_
#define _PERFIL_

#include "figura.h"
#include <cstring>
#include "file_ply_stl.h"

class Perfil : public Figura{
private:
  vector<_vertex3f> perfil; //Coordenadas del perfil. SOlo se modifica en el Constructor

  /**
  Vectores auxiliares con las caras del cuerpo y las caras de las tapas
  */
  vector<_vertex3i> carasCuerpo;
  vector<_vertex3i> carasTapaA;
  vector<_vertex3i> carasTapaF;

  float grados;
  int nDivisiones; //Numero de divisiones que queremos hacer, se dividen por el número de grados y obtenemos el número de rotaciones
  int gradosRotacion;
  bool pintaA, pintaF, cuerpo = true; //Pintar las tapas y el cuerpo, por defecto a true

  bool calculaRotaciones();
  float radToGrados(double angulo);
  void revolucionar();
  void creaObjRevo(); //Funcion que crea el objeto completo. Revoluciona,generaCaras,tapas
  void generaCaras();
  void generaTapas();
  void generaPuntosTapas();
  void generaTapaA(); //Tapa de arriba/ Caras
  void generaTapaF(); //Genera la tapa de abajo /Caras
  void generaCarasBarrido(); //Funcion especial para generar las caras de los vertices por barrido
public:
  Perfil();
  Perfil(vector<_vertex3f> perfil);
  Perfil(vector<_vertex3f>perfil,float grados, int nDivisiones);
  Perfil(string plyfile);
  Perfil(vector<_vertex3f>trayectoria,float distancia); //Solido por barrido

  vector<_vertex3f> getPerfil();
  float getGrados();
  void setGrados(float grados);
  int getDivisiones();
  void setDivisiones(int nDivisiones);
  void pinta(bool tapaA, bool tapaF, bool cuerpo); //Taba arriba tapa abajo y cuerpo

  //Generar solido por barrido
  void barrido(float distancia);

  void tapasBarrido(float distancia);

  //Quitar formas de pintar
  void quitaTapaA();
  void quitaTapaF();
  void quitaCuerpo();
};

#endif
