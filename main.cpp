/**********************************************************************************************************************
 // FileName:        main.c
 // Program version: Dev-C++ 5.11
 // Company:         TECNM - ITCH
 // Description:     CLASES 2_6 EN C++
 // Authors:         ALFREDO CHACON
 // Updated:         04/2021
 //Nota:  			EL SIGUIENTE CODIGO MUESTRA EL USO DE CLASES
 //           SE USAN ARREGLOS DE CARACTERES
************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
using namespace std;

class Mascota{
	private:				//Encapsulamiento (como caja negra)
		char _name[20];				//DAtos o caracteristicas Abstraidas
		char _especie[20];
		char _sexo[20];
		int _edad;
		int _num;
		static int n_mascotas;			//ATRIBUTO DE LA CLASE
		
	public:
		Mascota( char name[],char especie[], char *sexo,int edad); //Constructor de la Clase (inicializa atributos del objeto)
		Mascota();				//Constructor 2
		void comer();
		void correr();
		void jugar();
		void muestraDatos();
				
		// 				Getters & Setters	 Metodos constructores y modificadores
				
		void setMascota(char name[],char especie[], char sexo[],int edad );		//Setter Establecer valores a atributos cuando se requiera y no al inicio con el constructor
		void setName(char name[]);
		void captura();
		char * getName();									//Getter para obtener valores de atributos
		int getEdad();
	
};
/************************************************
    DECLARACION DEL CONSTRUCTOR (INICIALIZA ATRIBUTOS DEL OBJETO)
************************************************/
Mascota::Mascota( char name[],char especie[], char *sexo,int edad){
	for(int i=0;i<20;i++){
		this->_name[i]= name[i];
		this->_especie[i]= especie[i];
		this->_sexo[i]= sexo[i];	
	}

	_edad= edad;
	
	n_mascotas++;
	_num=n_mascotas;
	std::cout<<std::endl<<"Se ha creado un objeto Mascota numero: "<<_num<<std::endl;
}

Mascota::Mascota(){
	
	for(int i=0;i<20;i++){
		this->_name[i]= ' ';
		this->_especie[i]= ' ';
		this->_sexo[i]= ' ';	
	}
	//_name[]=" ";
	_edad=0;
	n_mascotas++;
	_num=n_mascotas;
	std::cout<<std::endl<<"Se ha creado un objeto Mascota numero:"<<_num;	
}

/************************************************
    METODOS
************************************************/

void Mascota::comer(){
	cout<<"La mascota "<<_name<<"de la especie"<<_especie<<"esta comiendo"<<endl;
}
void Mascota::correr(){
	cout<<"La mascota "<<_name<<"de la especie"<<_especie<<"esta corriendo"<<endl;
}
void Mascota::jugar(){
	cout<<"La mascota "<<_name<<" de la especie "<<_especie<<" esta jugnado"<<endl;
}


void Mascota::muestraDatos(){
	cout<<endl<<"** Imprimiendo Datos **"<<endl;
	cout<<"Numero de objeto: "<<_num<<endl;
	cout<<"Nombre: "<<_name<<endl;
	cout<<"Especie: "<<_especie<<endl;
	cout<<"Sexo: "<<_sexo<<endl;
	cout<<"Edad: "<<_edad<<endl;
}

/************************************************
    SETTER
************************************************/
void Mascota::setName(char name[]){
	for(int i=0;i<20;i++){
		_name[i]= name[i];
	}
}

void Mascota::setMascota(char name[],char especie[], char sexo[],int edad){
	for(int i=0;i<20;i++){
		_name[i]= name[i];
		_especie[i]= especie[i];
		_sexo[i]= sexo[i];	
	}
	_edad =  edad;
}
void Mascota::captura(){
	cout<<endl<<"** Introduce Datos **"<<endl;
	cout<<"Dame el Nombre: ";
	cin>> _name;
	cout<<"Dame la Edad: ";
	cin>> _edad;
	cout<<"Que especie es: ";
	cin>> _especie;
	cout<<"Dime su sexo: ";
	cin>> _sexo;
}
/************************************************
    GETTER
************************************************/
char* Mascota::getName(){
	return _name;
}
int Mascota::getEdad(){
	return _edad;
}
/************************************************
    Inicializacion de cuenta
************************************************/
int Mascota::n_mascotas=0;
/************************************************
   MAIN
************************************************/

int main(int argc, char** argv) {
	string na="xolotl";
  string nes="Perro";
  string nse="Macho";
  char nastr[na.size() + 1];
  strcpy(nastr, na.c_str()); 
  char esstr[nes.size() + 1];
  strcpy(esstr, nes.c_str()); 
   char sesstr[nse.size() + 1];
  strcpy(sesstr, nse.c_str());

	Mascota m1=Mascota(nastr,esstr,sesstr,2);
	//m1.name="Siegfried";		//incorrecto
	cout<<"De nombre: "<<m1.getName()<<endl;
	Mascota m2("Zeus","gato","Macho",5);
	cout<<"El nombre es: "<<m2.getName()<<endl;
	
	m2.setName("Odin");
	cout<<"Ahora su nombre es: "<<m2.getName()<<endl;
	m2.muestraDatos();
		
	char n[20],es[20],sex[20];
	int ed;
	Mascota m3;
	m3.muestraDatos();
	cout<<endl<<"** Introduce Datos **"<<endl;
	cout<<"Dame el Nombre: ";
	cin>> n;
	cout<<"Dame la Edad: ";
	cin>> ed;
	cout<<"Que especie es: ";
	cin>> es;
	cout<<"Dime su sexo: ";
	cin>>sex;
	m3.setMascota(n,es,sex,ed);
	m3.muestraDatos();
	Mascota m4;
	m4.captura();
	m4.muestraDatos();
	
	system("pause");
	return 0;
}