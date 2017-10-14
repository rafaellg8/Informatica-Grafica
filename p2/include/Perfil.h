/**
Clase Perfil.
Se pasa un perfil y se revoluciona para construir el objeto deseado.

Autor: Rafael Lachica Garrido
*/

#ifndef _PERFIL_
#define _PERFIL_

#include "figura.h"
class Perfil : public Figura{
private:
  vector<_vertex3f> perfil; //Coordenadas del perfil a revolucionar
  float grados;
  int nDivisiones; //Numero de divisiones que queremos hacer, se dividen por el número de grados y obtenemos el número de rotaciones
  int gradosRotacion;

  bool calculaRotaciones();
  float radToGrados(double angulo);
  void revolucionar();
  void generaCaras();
  void generaTapas();
  void generaPuntosTapas();
public:
  Perfil();
  Perfil(vector<_vertex3f> perfil);
  Perfil(vector<_vertex3f>perfil,float grados, int nDivisiones);

  vector<_vertex3f> getPerfil();
  void setPerfil(std::vector<_vertex3f> perfil);
  float getGrados();
  void setGrados(float grados);
  int getDivisiones();
  void setDivisiones(int nDivisiones);
};

#endif
