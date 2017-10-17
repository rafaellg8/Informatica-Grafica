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
  vector<_vertex3f> perfil; //Coordenadas del perfil. SOlo se modifica en el Constructor
  vector<_vertex3f> perfilRevo; //Coordenadas del perfil a revolucionar. Como un perfil auxiliar, borrador

  //El perfil es una copia de seguridad, nunca se toca, solo se cambia al crear el objeto. El perfilRevo se usa para cada revolcion

  float grados;
  int nDivisiones; //Numero de divisiones que queremos hacer, se dividen por el número de grados y obtenemos el número de rotaciones
  int gradosRotacion;

  bool calculaRotaciones();
  float radToGrados(double angulo);
  void revolucionar();
  void generaCaras();
  void generaTapas();
  void generaPuntosTapas();
  void generaTapaA(); //Tapa de arriba/ Caras
  void generaTapaF(); //Genera la tapa de abajo /Caras
public:
  Perfil();
  Perfil(vector<_vertex3f> perfil);
  Perfil(vector<_vertex3f>perfil,float grados, int nDivisiones);

  vector<_vertex3f> getPerfil();
  void setPerfilRevo(std::vector<_vertex3f> perfil);
  float getGrados();
  void setGrados(float grados);
  int getDivisiones();
  void setDivisiones(int nDivisiones);

  void revoTapaA(float grados, int nDivisiones); //revolucionar solo la tapa de arriba
  void revoTapaF(float grados, int nDivisiones); //revolucionar solo la tapa de abajo
  void revoCuerpo(float grados,int nDivisiones); //revolucionar solo el cuerpo
  void revoTotal(float grados,int nDivisiones); //revolucionar todo el objeto

};

#endif
