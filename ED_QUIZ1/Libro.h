#pragma once
#include "Persona.h"

class Libro
{
private:
	string Codigo;
	string NombreLibro;

public:
	Libro(void);
	Libro(
		string libCodigo,
		string libNombreLibro
	);

	// Getters and Setters
	string getCodigo();
	void setCodigo(string libCodigo);

	string getNombreLibro();
	void setNombreLibro(string libNombreLibro);

	void MostrarLibros();

	// Destructor
	~Libro();
};

