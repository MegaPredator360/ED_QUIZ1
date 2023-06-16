#include "ListaPersona.h"

ListaPersona::ListaPersona()
{
	primerValor = valorActual = NULL;
}

// Personas

void ListaPersona::agregarPersona(Persona p)
{
	valorActual = primerValor;

	if (primerValor == NULL || primerValor -> getValorPersona().getCedula() > p.getCedula())
	{
		primerValor = new Nodo(p, primerValor);
	}
	else
	{
		while ((valorActual -> getSiguiente() != NULL) && (valorActual -> getSiguiente() -> getValorPersona().getCedula() <= p.getCedula()))
		{
			valorActual = valorActual->getSiguiente();
		}
		Nodo* nuevo = new Nodo(p, valorActual->getSiguiente());
		valorActual->setSiguienteNodo(nuevo);
	}
}

void ListaPersona::mostrarPersonas()
{
	try
	{
		valorActual = primerValor;
		
		while (valorActual != NULL) // Se ira por cada nodo buscando los datos para mostrarlos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
		{
			if (valorActual -> getValorPersona().getCedula() != "")
			{
				valorActual -> getValorPersona().MostrarPersona();
			}
			valorActual = valorActual -> getSiguiente();
		}
		cout << "--------------------------------------" << endl << endl;
		
	}
	catch (exception& e)
	{
		throw e;
	}
}

// Libros

void ListaPersona::agregarLibro(Libro l)
{
	valorActual = primerValor;

	if (primerValor == NULL || primerValor -> getValorLibro().getCodigo() > l.getCodigo())
	{
		primerValor = new Nodo(l, primerValor);
	}
	else
	{
		while ((valorActual -> getSiguiente() != NULL) && (valorActual -> getSiguiente() -> getValorLibro().getCodigo() <= l.getCodigo()))
		{
			valorActual = valorActual -> getSiguiente();
		}

		Nodo* nuevo = new Nodo(l, valorActual -> getSiguiente());
		valorActual -> setSiguienteNodo(nuevo);
	}
}

void ListaPersona::mostrarLibros()
{
	try
	{
		valorActual = primerValor;

		while (valorActual != NULL) // Se ira por cada nodo buscando los datos para mostrarlos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
		{
			if (valorActual -> getValorLibro().getCodigo() != "")
			{
				cout << "--------------------------------------" << endl;
				valorActual->getValorLibro().MostrarLibros();
			}
			valorActual = valorActual -> getSiguiente();
		}
		cout << "--------------------------------------" << endl << endl;
	}
	catch (exception& e)
	{
		throw e;
	}
}

// Persona Libro

void ListaPersona::agregarPersonaLibro(PersonaLibro pl)
{
	valorActual = primerValor;

	if (primerValor == NULL || primerValor -> getValorPersonaLibro().getCedulaPersona() > pl.getCedulaPersona())
	{
		primerValor = new Nodo(pl, primerValor);
	}
	else
	{
		while ((valorActual -> getSiguiente() != NULL) && (valorActual -> getSiguiente() -> getValorPersonaLibro().getCedulaPersona() <= pl.getCedulaPersona()))
		{
			valorActual = valorActual -> getSiguiente();
		}

		Nodo* nuevo = new Nodo(pl, valorActual -> getSiguiente());
		valorActual -> setSiguienteNodo(nuevo);
	}
}

void ListaPersona::mostrarPersonaLibros()
{
	try
	{
		valorActual = primerValor;
		while (valorActual != NULL) // Se ira por cada nodo buscando los datos para mostrarlos, se detendrá cuando un valor sea nulo o no existan más valores en la lista
		{
			if (valorActual -> getValorPersonaLibro().getCedulaPersona() != "")
			{
				Nodo* valorPersona = primerValor;
				Nodo* valorLibro = primerValor;

				while (valorPersona -> getValorPersona().getCedula() != valorActual -> getValorPersonaLibro().getCedulaPersona())
				{
					valorPersona = valorPersona -> getSiguiente();
				}
				valorPersona -> getValorPersona().MostrarPersona();

				while (valorLibro -> getValorLibro().getCodigo() != valorActual -> getValorPersonaLibro().getCodigoLibro())
				{
					valorLibro = valorLibro -> getSiguiente();
				}
				valorLibro -> getValorLibro().MostrarLibros();
			}
			valorActual = valorActual -> getSiguiente();
		}
		cout << "--------------------------------------" << endl;
	}
	catch (exception& e)
	{
		throw e;
	}
}

bool ListaPersona::verificarLibros()
{
	valorActual = primerValor;

	if (primerValor != NULL && primerValor -> getValorLibro().getCodigo() != "")
	{
		return true;
	}

	while (valorActual != NULL && valorActual -> getValorLibro().getCodigo() == "")
	{
		valorActual = valorActual -> getSiguiente();
	}

	if (valorActual == NULL || valorActual->getValorLibro().getCodigo() == "")
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ListaPersona::verificarLibroExiste(string codigo)
{
	valorActual = primerValor;

	if (primerValor != NULL && primerValor -> getValorLibro().getCodigo() == codigo)
	{
		return true;
	}

	while (valorActual != NULL && valorActual->getValorLibro().getCodigo() != codigo)
	{
		valorActual = valorActual -> getSiguiente();
	}

	if (valorActual == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ListaPersona::verificarPersonas()
{
	valorActual = primerValor;

	if (primerValor != NULL && primerValor -> getValorPersona().getCedula() != "")
	{
		return true;
	}

	while (valorActual != NULL && valorActual -> getValorPersona().getCedula() == "")
	{
		valorActual = valorActual -> getSiguiente();
	}

	if (valorActual == NULL	|| valorActual -> getValorPersona().getCedula() == "")
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ListaPersona::verificarPersonaExiste(string cedula)
{
	valorActual = primerValor;

	if (primerValor != NULL && primerValor -> getValorPersona().getCedula() == cedula)
	{
		return true;
	}

	while (valorActual != NULL && valorActual -> getValorPersona().getCedula() != cedula)
	{
		valorActual = valorActual->getSiguiente();
	}

	if (valorActual == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ListaPersona::verificarPersonaLibro()
{
	valorActual = primerValor;

	if (primerValor != NULL && primerValor -> getValorPersonaLibro().getCedulaPersona() != "")
	{
		return true;
	}

	while (valorActual != NULL && valorActual -> getValorPersonaLibro().getCedulaPersona() == "")
	{
		valorActual = valorActual -> getSiguiente();
	}

	if (valorActual == NULL || valorActual -> getValorPersonaLibro().getCedulaPersona() == "")
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ListaPersona::verificarPersonaLibroExiste(PersonaLibro pl)
{
	valorActual = primerValor;

	if (primerValor != NULL && primerValor -> getValorPersonaLibro().getCedulaPersona() == pl.getCedulaPersona() && primerValor -> getValorPersonaLibro().getCodigoLibro() == pl.getCodigoLibro())
	{
		return true;
	}

	while (valorActual != NULL)
	{
		if (valorActual -> getValorPersonaLibro().getCedulaPersona() == pl.getCedulaPersona() && valorActual -> getValorPersonaLibro().getCodigoLibro() == pl.getCodigoLibro())
		{
			return true;
		}
		valorActual = valorActual -> getSiguiente();
	}

	if (valorActual == NULL)
	{
		return false;
	}
}

ListaPersona::~ListaPersona()
{
	valorActual = primerValor;
	while (primerValor != NULL)
	{
		valorActual = primerValor;
		primerValor = primerValor->getSiguiente();
		delete valorActual;
	}
	valorActual = NULL;
	primerValor = NULL;
}