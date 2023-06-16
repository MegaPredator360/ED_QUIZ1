#include "ListaPersona.h"

int main()
{
    setlocale(LC_ALL, "");

    ListaPersona _listapersona;
    Persona _persona;
    Libro _libro;
    PersonaLibro _personalibro;
    Validaciones _validaciones;

    int opcion = 0;
    string cedula = "";
    string nombre = "";
    string apellido = "";
    string confirmar = "";
    string codigo = "";

    while (opcion == 0) {

        system("cls");
        cout << "                   ¡Menu Principal!" << endl << endl;
        cout << "       ///////////////////////////////////////////////" << endl;
        cout << "       //" << endl;
        cout << "       //   1) Agregar una persona." << endl;
        cout << "       //   2) Agregar un libro." << endl;
        cout << "       //   3) Asignar un libro a una persona." << endl;
        cout << "       //   4) Mostrar las personas registradas." << endl;
        cout << "       //   5) Mostrar los libros registrados." << endl;
        cout << "       //   6) Mostrar los libros asociados a una persona." << endl;
        cout << "       //   7) Salir." << endl;
        cout << "       //" << endl;
        cout << "       ///////////////////////////////////////////////" << endl << endl;
        cout << "Selecciona una opcion" << endl;
        opcion = stoi(_validaciones.aceptarNumeros());


        switch (opcion) {
        case 1:
            // Agregar Personas
            system("cls");

            cout << "       Agregar Personas" << endl << endl;
            cout << "Ingrese la cedula de la persona: " << endl;
            cedula = _validaciones.aceptarNumeros();
            _persona.setCedula(cedula);

            cout << "Ingrese el nombre de la persona: " << endl;
            getline(cin, nombre);
            while (nombre == "")
            {
                cout << "El espacio no puede estar vacio, debes de escribir el nombre de la persona: " << endl;
                getline(cin, nombre);
            }
            _persona.setNombre(nombre);

            cout << "Ingrese el apellido de la persona: " << endl;
            getline(cin, apellido);
            while (apellido == "")
            {
                cout << "El espacio no puede estar vacio, debes de escribir el apellido de la persona: " << endl;
                getline(cin, apellido);
            }
            _persona.setApellido(apellido);

            cout << "¿Desea asignar un libro a la persona? [S/n]" << endl;
            confirmar = _validaciones.confirmacionDefS();

            if (confirmar == "S" && _listapersona.verificarLibros() == true)
            {
                cout << "--------------------------------------" << endl;
                cout << "-------- Libros Registrados ----------" << endl;
                _listapersona.mostrarLibros();

                while (1)
                {
                    cout << "Ingresa el codigo del libro: " << endl;
                    codigo = _validaciones.aceptarNumeros();

                    while (_listapersona.verificarLibroExiste(codigo) == false)
                    {
                        cout << "No hay ningun libro registrado con ese codigo, vuelve a ingresar el codigo de libro: " << endl;
                        codigo = _validaciones.aceptarNumeros();
                    }

                    _personalibro.setCedulaPersona(cedula);
                    _personalibro.setCodigoLibro(codigo);

                    if (_listapersona.verificarPersonaLibroExiste(_personalibro) == false)
                    {
                        _listapersona.agregarPersonaLibro(_personalibro);
                        cout << "¡La asignacion se ha realizado con exito!" << endl;
                        system("pause");
                    }
                    else
                    {
                        cout << "¡Ya existe una asignacion entre el usuario y el libro en el sistema!" << endl;
                        system("pause");

                    }

                    cout << "¿Desea asignar otro libro al usuario? [S/n]" << endl;
                    confirmar = _validaciones.confirmacionDefS();

                    if (confirmar == "N")
                    {
                        break;
                    }
                }
            }
            else if (confirmar == "S" && _listapersona.verificarLibros() == false)
            {
                cout << "¡No hay libros registrados!" << endl;
                system("pause");
            }

            _listapersona.agregarPersona(_persona);
            cout << "-----------------------------------------" << endl;
            cout << "¡La persona ha sido agregada con exito!" << endl;
            system("pause");
            opcion = 0;
            confirmar = "";
            break;

        case 2:
            // Agregar Libros
            system("cls");

            cout << "       Agregar Libros" << endl << endl;
            cout << "Ingrese el codigo del libro" << endl;
            codigo = _validaciones.aceptarNumeros();
            _libro.setCodigo(codigo);

            cout << "Ingrese el nombre del libro" << endl;
            getline(cin, nombre);
            while (nombre == "")
            {
                cout << "El espacio no puede estar vacio, debes de escribir el nombre del libro: " << endl;
                getline(cin, nombre);
            }
            _libro.setNombreLibro(nombre);

            _listapersona.agregarLibro(_libro);
            cout << "-----------------------------------------" << endl;
            cout << "¡El libro ha sido agregado con exito!" << endl;
            system("pause");
            opcion = 0;
            break;

        case 3:
            // Asociar personas con libros
            if (_listapersona.verificarPersonas() == true && _listapersona.verificarLibros() == true)
            {
                while (1)
                {
                    system("cls");

                    cout << "--------------------------------------" << endl;
                    cout << "------- Personas Registradas ---------" << endl;
                    _listapersona.mostrarPersonas();

                    cout << "--------------------------------------" << endl;
                    cout << "-------- Libros Registrados ----------" << endl;
                    _listapersona.mostrarLibros();

                    cout << "Ingresa el número de cedula de la persona: " << endl;
                    cedula = _validaciones.aceptarNumeros();

                    while (_listapersona.verificarPersonaExiste(cedula) == false)
                    {
                        cout << "No hay ninguna persona registrada con ese numero, vuelve a ingresar la cedula: " << endl;
                        cedula = _validaciones.aceptarNumeros();
                    }
                    _personalibro.setCedulaPersona(cedula);

                    cout << "Ingresa el codigo del libro: " << endl;
                    codigo = _validaciones.aceptarNumeros();

                    while (_listapersona.verificarLibroExiste(codigo) == false)
                    {
                        cout << "No hay ningun libro registrado con ese codigo, vuelve a ingresar el codigo de libro: " << endl;
                        codigo = _validaciones.aceptarNumeros();
                    }
                    _personalibro.setCodigoLibro(codigo);

                    if (_listapersona.verificarPersonaLibroExiste(_personalibro) == false)
                    {
                        _listapersona.agregarPersonaLibro(_personalibro);
                        cout << "¡La asignacion se ha realizado con exito!" << endl;
                        system("pause");
                    }
                    else
                    {
                        cout << "¡Ya existe una asignacion entre el usuario y el libro en el sistema!" << endl;
                        system("pause");

                    }
                    
                    cout << "¿Deseas asígnar otro libro a otra persona? [S/n]" << endl;
                    confirmar = _validaciones.confirmacionDefS();

                    if (confirmar == "N")
                    {
                        break;
                    }
                }
            }
            else if (_listapersona.verificarPersonas() == false && _listapersona.verificarLibros() == true)
            {
                system("cls");

                cout << "¡No hay personas registradas en el sistema!" << endl;
                system("pause");
            }
            else if (_listapersona.verificarPersonas() == true && _listapersona.verificarLibros() == false)
            {
                system("cls");

                cout << "¡No hay libros registrados en el sistema!" << endl;
                system("pause");
            }
            else if (_listapersona.verificarPersonas() == false && _listapersona.verificarLibros() == false)
            {
                system("cls");

                cout << "¡No hay libros ni personas registradas en el sistema!" << endl;
                system("pause");
            }

            confirmar = "";
            opcion = 0;
            break;

        case 4:
            // Personas Registradas
            system("cls");

            if (_listapersona.verificarPersonas() == true)
            {
                cout << "--------------------------------------" << endl;
                cout << "------- Personas Registradas ---------" << endl;
                _listapersona.mostrarPersonas();
                cout << "¡Se han cargado todas las personas registradas!" << endl;
                system("pause");
            }
            else
            {
                cout << "¡No hay personas registradas en el sistema!" << endl;
                system("pause");
            }

            opcion = 0;
            break;

        case 5:
            system("cls");

            if (_listapersona.verificarLibros() == true)
            {
                cout << "--------------------------------------" << endl;
                cout << "-------- Libros Registrados ----------" << endl;
                _listapersona.mostrarLibros();
                cout << "¡Se han cargado todos los libros registrados!" << endl;
                system("pause");
            }
            else
            {
                cout << "¡No hay libros registrados en el sistema!" << endl;
                system("pause");
            }


            opcion = 0;
            break;

        case 6:
            system("cls");

            if (_listapersona.verificarPersonaLibro() == true)
            {
                cout << "--------------------------------------" << endl;
                cout << "---- Libros Asociados a Personas -----" << endl;
                _listapersona.mostrarPersonaLibros();
                system("pause");
            }
            else
            {
                cout << "¡No hay libros asociados a personas en el sistema!" << endl;
                system("pause");
            }

            opcion = 0;
            break;

        case 7:
            exit(0);
            break;

        default:
            cout << "Por favor seleccione una opcion valida." << endl;
            system("pause");
            opcion = 0;
            break;
        }
    }
    
	return 0;
}