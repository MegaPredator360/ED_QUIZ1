#pragma once
#include "Nodo.h"

class ListaPersona
{
private:
	Nodo* primerValor;
	Nodo* valorActual;

public:
	ListaPersona();
	void agregarPersona(Persona p);
	void agregarLibro(Libro l);
	void agregarPersonaLibro(PersonaLibro pl);
	void mostrarPersonas();
	void mostrarLibros();
	void mostrarPersonaLibros();
	bool verificarLibros();
	bool verificarLibroExiste(string codigo);
	bool verificarPersonas();
	bool verificarPersonaExiste(string cedula);
	bool verificarPersonaLibro();
	bool verificarPersonaLibroExiste(PersonaLibro pl);

	~ListaPersona();
};

