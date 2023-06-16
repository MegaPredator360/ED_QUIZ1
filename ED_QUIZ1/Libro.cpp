#include "Libro.h"

Libro::Libro(void) {}

Libro::Libro(
	string libCodigo,
	string libNombreLibro
) {
	Codigo = libCodigo;
	NombreLibro = libNombreLibro;
}

string Libro::getCodigo() { return Codigo; }
void Libro::setCodigo(string libCodigo) { Codigo = libCodigo; }

string Libro::getNombreLibro() { return NombreLibro; }
void Libro::setNombreLibro(string libNombreLibro) { NombreLibro = libNombreLibro; }

void Libro::MostrarLibros()
{
	cout << "--  Codigo: " << Codigo << endl;
	cout << "--  Nombre de Libro: " << NombreLibro << endl;
}

Libro::~Libro() {}
