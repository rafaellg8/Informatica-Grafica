#include "Perfil.h"
#include <cstdlib>

Perfil::Perfil(){
        grados = nDivisiones = gradosRotacion = 0;
};

Perfil::Perfil(vector<_vertex3f> perfil){
        this->perfil = perfil;
        this->perfilRevo = perfil;
        setVertices(perfil); //SI solo tenemos esos puntos, serán nuestros vertices
}

Perfil::Perfil(vector<_vertex3f>perfil,float grados,int nDivisiones){
        this->perfil = perfil;
        this->perfilRevo = perfil;
        this->grados = grados;
        this->nDivisiones = nDivisiones;
        vertices = perfil;


        calculaRotaciones();
        revolucionar();

        generaCaras();

        generaPuntosTapas();

        generaTapas();
        insertarDatos(vertices,caras); //Aniadimos los vertices y las caras a la clase superior

}

float Perfil::radToGrados(double angulo){
        return (angulo*(M_PI/180));
}

bool Perfil::calculaRotaciones(){
        if (this->perfil.size()>0 && this->grados>0.0 && this->nDivisiones>0) {
                gradosRotacion = (this->grados)/(this->nDivisiones);
                return true;
        }
        else return false;
}

void Perfil::revolucionar(){
        float x,y,z=0;

        //Comprobar las divisiones,grados y el perfil existen
        if (calculaRotaciones()) {
                for (int i=0; i<nDivisiones; i++) {
                        for(int j=0; j<perfilRevo.size(); j++) { //vamos recorriendo el perfil
                                x=(fabs(perfil[j].x)*cos(radToGrados(gradosRotacion*i)));
                                y=static_cast<float>(perfil[j].y);
                                z=(fabs(perfil[j].x)*sin(radToGrados(gradosRotacion*i)));

                                if (z<0.0)
                                        z=z+(2*fabs(z));
                                else if (z>0.0)
                                        z=z-(2*fabs(z));

                                //guardamos el punto
                                vertices.push_back({x,y,z});
                        }
                }
        }
}

void Perfil::revoTotal(float grados,int nDivisiones){
        this->grados = grados;
        this->nDivisiones = nDivisiones;

        if (vertices.size()<=0) {
                vertices = perfil;
                perfilRevo = perfil;
        }

        calculaRotaciones();
        revolucionar();

        generaCaras();

        generaPuntosTapas();

        generaTapas();
        insertarDatos(vertices,caras); //Aniadimos los vertices y las caras a la clase superior
}

void Perfil::generaCaras(){
        int n;
        if (grados==360) {
                n=vertices.size();
        }
        else{ //Si solo queremos revolucionar la mitad de la figuras, 180 grados
                n = nDivisiones*perfilRevo.size(); //Recorremos, numero de divisiones * puntos del perfil
        }

        for (int i=0; i<n; i++) {
                if ((i+1)%perfilRevo.size()!=0) { //Comprobamos que no se salga de las tapas de arriba
                        //Asignar en triangulos las caras
                        caras.push_back({(i),(i+1), static_cast<int>((i+perfilRevo.size())%vertices.size())}); //Cara A del cuadrado AB

                        caras.push_back({(i+1), static_cast<int>((i+1+perfilRevo.size())%vertices.size()), static_cast<int>((i+perfilRevo.size())%vertices.size())});

                }
        }
}

void Perfil::generaPuntosTapas(){
        _vertex3f t; // Punto donde está la tapa abajo
        _vertex3f T; //Punto donde está la tapa de arriba

        t = vertices[0]; //Almacenamos los puntos
        T = vertices[perfilRevo.size()-1];

//Dejamos solo los puntos sobre el eje Y
        t.x = 0.0; t.z=0.0;
        T.x = 0.0; T.z=0.0; T.y=(vertices[perfilRevo.size()-1].y+0.10); //Subimos un poco para redondear la punta


        vertices.push_back(t); //Penúltima posicion del vector, t
        vertices.push_back(T); //Ultima posicion del T
}

void Perfil::generaTapas(){
        // /************************
        // Tapa Abajo
        // *************************/
        //
        // for (int i=0;i<nDivisiones;i++){
        //   caras.push_back({static_cast<int>(i*perfilRevo.size()),static_cast<int>(vertices.size()-2),static_cast<int>((i+1)*perfilRevo.size())}); //vertices final -2 posiciones, punto t
        // }
        //
        // //Ultima cara
        // caras.push_back({static_cast<int>(nDivisiones*perfilRevo.size()),static_cast<int>(vertices.size()-2),static_cast<int>(0)});
        //
        //  /***********************
        //  Tapa Arriba
        //  ************************/
        //
        // for (int i=1;i<=nDivisiones;i++){
        //   caras.push_back({static_cast<int>(i*perfilRevo.size()-1),static_cast<int>((i+1)*perfilRevo.size()-1),static_cast<int>(vertices.size()-1)}); //vertices final -2 posiciones, punto t
        // }
        // // Ultima cara
        // caras.push_back({static_cast<int>(vertices.size()-3),static_cast<int>(perfilRevo.size()-1),static_cast<int>(vertices.size()-1)});
        generaTapaF(); //Tapa abajo
        generaTapaA(); //tapa arriba
}

void Perfil::generaTapaA(){
        /***********************
           Tapa Arriba
         ************************/

        for (int i=1; i<=nDivisiones; i++) {
                caras.push_back({static_cast<int>(i*perfilRevo.size()-1),static_cast<int>((i+1)*perfilRevo.size()-1),static_cast<int>(vertices.size()-1)}); //vertices final -2 posiciones, punto t
        }
        // Ultima cara
        caras.push_back({static_cast<int>(vertices.size()-3),static_cast<int>(perfilRevo.size()-1),static_cast<int>(vertices.size()-1)});
}

void Perfil::generaTapaF(){
        /************************
           Tapa Abajo
         *************************/

        for (int i=0; i<nDivisiones; i++) {
                caras.push_back({static_cast<int>(i*perfilRevo.size()),static_cast<int>(vertices.size()-2),static_cast<int>((i+1)*perfilRevo.size())}); //vertices final -2 posiciones, punto t
        }

        //Ultima cara
        caras.push_back({static_cast<int>(nDivisiones*perfilRevo.size()),static_cast<int>(vertices.size()-2),static_cast<int>(0)});

}

vector<_vertex3f> Perfil::getPerfil(){
        return perfil;
}

void Perfil::setPerfilRevo(vector<_vertex3f> perfil){
        perfilRevo = perfil;
}

float Perfil::getGrados(){
        return grados;
}

void Perfil::setGrados(float grados){
        this->grados = grados;

        calculaRotaciones();
}

int Perfil::getDivisiones(){
        return nDivisiones;
}

void Perfil::setDivisiones(int nDivisiones){
        this->nDivisiones = nDivisiones;
        calculaRotaciones();
}

void Perfil::revoTapaA(float grados, int nDivisiones){
        this->grados = grados;
        this->nDivisiones = nDivisiones;

        vertices.clear();
        caras.clear();

        perfilRevo.clear();
        perfilRevo.push_back(perfil[perfil.size()-1]); //unico elemento la tapa de arriba

        calculaRotaciones();

        revolucionar(); //revoluciona solo la cara de arriba

        generaPuntosTapas();

        generaTapaA();

        insertarDatos(vertices,caras); //Aniadimos los vertices y las caras a la clase superior
}

void Perfil::revoTapaF(float grados, int nDivisiones){
        this->grados = grados;
        this->nDivisiones = nDivisiones;

        vertices.clear();
        caras.clear();

        perfilRevo.clear();
        perfilRevo.push_back(perfil[0]); //unico elemento la tapa de abajo

        calculaRotaciones();

        revolucionar(); //revoluciona solo la cara de arriba

        generaPuntosTapas();

        generaTapaF();

        insertarDatos(vertices,caras); //Aniadimos los vertices y las caras a la clase superior
}

void Perfil::revoCuerpo(float grados, int nDivisiones){
        this->grados = grados;
        this->nDivisiones = nDivisiones;

        vertices.clear();
        caras.clear();

        perfilRevo = perfil;

        calculaRotaciones();
        revolucionar();

        generaCaras();

}
