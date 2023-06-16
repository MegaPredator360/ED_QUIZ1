#pragma once
#include "PersonaLibro.h"

class Nodo
{
private:
	Persona _persona;		// Campo de datos
	Libro _libro;
	PersonaLibro _personaLibro;

	Nodo* siguiente;		// Puntero al siguiente nodo

public:
	Nodo(Persona, Nodo*);	// Lista de Personas
	Nodo(Libro, Nodo*);		// Lista de Libros
	Nodo(PersonaLibro, Nodo*);	// Tabla Relacional


	~Nodo();
	void setValorPersona(Persona p);
	void setValorLibro(Libro l);
	void setValorPersonaLibro(PersonaLibro pl);


	void setSiguienteNodo(Nodo* s);

	Persona getValorPersona();
	Libro getValorLibro();
	PersonaLibro getValorPersonaLibro();

	Nodo* getSiguiente();
};

