#pragma once
#include "Libro.h"

class PersonaLibro
{
private:
	string CodigoLibro;
	string CedulaPersona;

public:
	PersonaLibro(void);
	PersonaLibro(
		string plCodigoLibro,
		string plCedulaPersona
	);

	string getCodigoLibro();
	void setCodigoLibro(string plCodigoLibro);
	string getCedulaPersona();
	void setCedulaPersona(string plCedulaPersona);

	void MostrarPersonaLibro();
};

