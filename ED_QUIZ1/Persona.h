#pragma once
#include "Validaciones.h"

class Persona
{
private:
	string Cedula;
	string Nombre;
	string Apellido;

public:
	Persona(void);
	Persona(
		string perCedula,
		string perNombre,
		string perApellido
	);

	// Getters
	string getCedula();
	string getNombre();
	string getApellido();

	// Setters
	void setCedula(string perCedula);
	void setNombre(string perNombre);
	void setApellido(string perApellido);

	void MostrarPersona();
	
	// Destructor
	~Persona();
};