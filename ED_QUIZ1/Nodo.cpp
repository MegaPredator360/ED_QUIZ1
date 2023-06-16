#include "Nodo.h"

Nodo::Nodo(Persona p, Nodo* sig = NULL)
{
	_persona.setCedula(p.getCedula());
	_persona.setNombre(p.getNombre());
	_persona.setApellido(p.getApellido());
	siguiente = sig;
}

Nodo::Nodo(Libro l, Nodo* sig = NULL)
{
	_libro.setCodigo(l.getCodigo());
	_libro.setNombreLibro(l.getNombreLibro());
	siguiente = sig;
}

Nodo::Nodo(PersonaLibro pl, Nodo* sig = NULL)
{
	_personaLibro.setCedulaPersona(pl.getCedulaPersona());
	_personaLibro.setCodigoLibro(pl.getCodigoLibro());
	siguiente = sig;
}

Nodo::~Nodo() { }

// Persona
void Nodo::setValorPersona(Persona p) { this -> _persona = p; }
Persona Nodo::getValorPersona() { return this -> _persona; }

// Libro
void Nodo::setValorLibro(Libro l) { this -> _libro = l; }
Libro Nodo::getValorLibro() { return this -> _libro; }

// PersonaLibro
void Nodo::setValorPersonaLibro(PersonaLibro pl) { this -> _personaLibro = pl; }
PersonaLibro Nodo::getValorPersonaLibro() { return this -> _personaLibro; }

// Obtendra el valor del siguiente nodo
void Nodo::setSiguienteNodo(Nodo* s)
{
	this->siguiente = s;
}

// Obtendra el valor del siguiente nodo
Nodo* Nodo::getSiguiente()
{
	return this->siguiente;
}
