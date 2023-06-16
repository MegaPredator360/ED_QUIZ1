#include "Persona.h"

Persona::Persona(void){}
Persona::Persona(
	string perCedula,
	string perNombre, 
	string perApellido
) {
	Cedula = perCedula;
	Nombre = perNombre;
	Apellido = perApellido;
}

// Getters and Setters
string Persona::getCedula() { return Cedula; }
void Persona::setCedula(string perCedula) { Cedula = perCedula; }
string Persona::getNombre() { return Nombre; }
void Persona::setNombre(string perNombre) { Nombre = perNombre; }
string Persona::getApellido() { return Apellido; }
void Persona::setApellido(string perApellido) { Apellido = perApellido; }

void Persona::MostrarPersona()
{
	cout << "--------------------------------------" << endl;
	cout << "--  Cedula: " << Cedula << endl;
	cout << "--  Nombre: " << Nombre << endl;
	cout << "--  Apellido: " << Apellido << endl;
}

Persona::~Persona() { }
