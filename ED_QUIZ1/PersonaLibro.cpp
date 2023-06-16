#include "PersonaLibro.h"

PersonaLibro::PersonaLibro(void) {}

PersonaLibro::PersonaLibro(
	string plCodigoLibro,
	string plCedulaPersona
) {
	CodigoLibro = plCodigoLibro;
	CedulaPersona = plCedulaPersona;
}

string PersonaLibro::getCodigoLibro() { return CodigoLibro; }
void PersonaLibro::setCodigoLibro(string plCodigoLibro) { CodigoLibro = plCodigoLibro; }
string PersonaLibro::getCedulaPersona() { return CedulaPersona; }
void PersonaLibro::setCedulaPersona(string plCedulaPersona) { CedulaPersona = plCedulaPersona; }

void PersonaLibro::MostrarPersonaLibro() 
{
	cout << CedulaPersona << endl;
	cout << CodigoLibro << endl;
}
