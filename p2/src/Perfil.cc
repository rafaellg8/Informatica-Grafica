#include "Perfil.h"
#include <cstdlib>

Perfil::Perfil(){
        grados = nDivisiones = gradosRotacion = 0;
};

Perfil::Perfil(vector<_vertex3f> perfil){
        this->perfil = perfil;
        setVertices(perfil); //SI solo tenemos esos puntos, serán nuestros vertices
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
                                y=perfil[j].y;
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
  int n;
	if (grados==360){ //Controlamos que pueda pintar solo una parte de la figura ej: 3/4 bien pintados
		n=vertices.size();
	}
	else{
	n = nDivisiones*perfil.size(); //Recorremos, numero de divisiones * puntos del perfil
	}
  cout<<"n "<<n<<endl;
	for (int i=0;i<n;i++){
			if ((i+1)%perfil.size()!=0){ //Comprobamos que no se salga de las tapas de arriba
			//Asignar en triangulos las caras
			caras.push_back({(i),(i+1), static_cast<int>((i+perfil.size())%vertices.size())}); //Cara A del cuadrado AB
      cout<<"\nAniadiendo "<<caras.back().x<<" "<<caras.back().y<<" "<<caras.back().z<<endl;
			caras.push_back({(i+1), static_cast<int>((i+1+perfil.size())%vertices.size()), static_cast<int>((i+perfil.size())%vertices.size())});
      cout<<"\nAniadiendo "<<caras.back().x<<" "<<caras.back().y<<" "<<caras.back().z<<endl;
		}
	}
}

Perfil::Perfil(vector<_vertex3f>perfil,float grados,int nDivisiones){
        this->perfil = perfil;
        this->grados = grados;
        this->nDivisiones = nDivisiones;
        vertices = perfil;
        cout<<"\nPerfil: caras  vertices"<<caras.size()<<" "<<vertices.size()<<endl;
        // setVertices(perfil);
        calculaRotaciones();
        cout<<"\nNum diviones "<<nDivisiones<< " "<<grados<<" "<<gradosRotacion<<endl;
        cout<<"\nPerfil: "<<caras.size()<<" "<<vertices.size()<<" perfil "<<perfil.size()<<endl;
        revolucionar();
        generaCaras();
        cout<<"\nPerfil: "<<caras.size()<<" "<<vertices.size()<<endl;
        creaTabla();
}

vector<_vertex3f> Perfil::getPerfil(){
        return perfil;
}

void Perfil::setPerfil(vector<_vertex3f> perfil){
        this->perfil = perfil;
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
