#include "Perfil.h"
#include <cstdlib>

Perfil::Perfil(){
        grados = nDivisiones = gradosRotacion = 0;
};

Perfil::Perfil(vector<_vertex3f> perfil){
        this->perfil = perfil;
        setVertices(perfil); //SI solo tenemos esos puntos, serán nuestros vertices
}

Perfil::Perfil(vector<_vertex3f>perfil,float grados,int nDivisiones){
        this->perfil = perfil;
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


vector<_vertex3f> Perfil::getPerfil(){
        return perfil;
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
                        for(int j=0; j<perfil.size(); j++) { //vamos recorriendo el perfil
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


void Perfil::generaCaras(){
        // int n;
        // if (grados==360) {
        //         n=vertices.size();
        // }
        // else{ //Si solo queremos revolucionar la mitad de la figuras, 180 grados
        //         n = nDivisiones*perfil.size(); //Recorremos, numero de divisiones * puntos del perfil
        // }
        carasCuerpo.clear();

        for (int i=0; i<vertices.size(); i++) {
                if ((i+1)%perfil.size()!=0) { //Comprobamos que no se salga de las tapas de arriba
                        //Asignar en triangulos las caras
                        caras.push_back({(i),(i+1), static_cast<int>((i+perfil.size())%vertices.size())}); //Cara A del cuadrado AB

                        carasCuerpo.push_back(caras.back());

                        caras.push_back({(i+1), static_cast<int>((i+1+perfil.size())%vertices.size()),
                          static_cast<int>((i+perfil.size())%vertices.size())});

                        carasCuerpo.push_back(caras.back());

                }
        }
}

void Perfil::generaPuntosTapas(){
        _vertex3f t; // Punto donde está la tapa abajo
        _vertex3f T; //Punto donde está la tapa de arriba

        t = vertices[0]; //Almacenamos los puntos
        T = vertices[perfil.size()-1];

//Dejamos solo los puntos sobre el eje Y
        t.x = 0.0; t.z=0.0;
        T.x = 0.0; T.z=0.0; T.y=(vertices[perfil.size()-1].y+0.10); //Subimos un poco para redondear la punta


        vertices.push_back(t); //Penúltima posicion del vector, t
        vertices.push_back(T); //Ultima posicion del T
}

void Perfil::generaTapas(){
        // /************************
        // Tapa Abajo
        // *************************/
        //
        // for (int i=0;i<nDivisiones;i++){
        //   caras.push_back({static_cast<int>(i*perfil.size()),static_cast<int>(vertices.size()-2),static_cast<int>((i+1)*perfil.size())}); //vertices final -2 posiciones, punto t
        // }
        //
        // //Ultima cara
        // caras.push_back({static_cast<int>(nDivisiones*perfil.size()),static_cast<int>(vertices.size()-2),static_cast<int>(0)});
        //
        //  /***********************
        //  Tapa Arriba
        //  ************************/
        //
        // for (int i=1;i<=nDivisiones;i++){
        //   caras.push_back({static_cast<int>(i*perfil.size()-1),static_cast<int>((i+1)*perfil.size()-1),static_cast<int>(vertices.size()-1)}); //vertices final -2 posiciones, punto t
        // }
        // // Ultima cara
        // caras.push_back({static_cast<int>(vertices.size()-3),static_cast<int>(perfil.size()-1),static_cast<int>(vertices.size()-1)});
        generaTapaF(); //Tapa abajo
        generaTapaA(); //tapa arriba
}

void Perfil::generaTapaA(){
        /***********************
           Tapa Arriba
         ************************/
        carasTapaA.clear();
        for (int i=1; i<=nDivisiones; i++) {
                caras.push_back({static_cast<int>(i*perfil.size()-1),static_cast<int>((i+1)*perfil.size()-1),static_cast<int>(vertices.size()-1)}); //vertices final -2 posiciones, punto t
                carasTapaA.push_back(caras.back());
        }
        // Ultima cara
        caras.push_back({static_cast<int>(vertices.size()-3),static_cast<int>(perfil.size()-1),static_cast<int>(vertices.size()-1)});
        carasTapaA.push_back(caras.back());
}

void Perfil::generaTapaF(){
        /************************
           Tapa Abajo
         *************************/
         carasTapaF.clear();
        for (int i=0; i<nDivisiones; i++) {
                caras.push_back({static_cast<int>(i*perfil.size()),static_cast<int>(vertices.size()-2),static_cast<int>((i+1)*perfil.size())}); //vertices final -2 posiciones, punto t
                carasTapaF.push_back(caras.back());
        }

        //Ultima cara
        caras.push_back({static_cast<int>(nDivisiones*perfil.size()),static_cast<int>(vertices.size()-2),static_cast<int>(0)});
        carasTapaF.push_back(caras.back());
}


void Perfil::pinta(bool tapaArriba, bool tapaFondo, bool cuerpo){
        caras.clear();
        if (cuerpo)
          caras.insert(caras.end(),carasCuerpo.begin(),carasCuerpo.end());

        if (tapaFondo)
          caras.insert(caras.end(),carasTapaF.begin(),carasTapaF.end());

        if (tapaArriba)
          caras.insert(caras.end(),carasTapaA.begin(),carasTapaA.end());

        insertarDatos(vertices,caras);

}
