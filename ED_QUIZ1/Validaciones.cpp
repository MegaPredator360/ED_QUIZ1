#include "Validaciones.h"

string Validaciones::aceptarNumeros()
{
	int asciiChar = 0;
	string num = "";
	do
	{
		asciiChar = _getch();						// Obtendra las teclas de formato ASCII 
		if (asciiChar >= 48 && asciiChar <= 57)		// Validaremos solo los valores que sean equivalentes a numeros
		{
			asciiChar = (asciiChar - 48);			// Los valores de ASCII para numeros 0-9 es igual a 48 hasta 57, por lo que se le resta a 48 por ser equivalente a 0
			cout << asciiChar;						// Se imprime el valor
			num = num + to_string(asciiChar);		// Convertir de Int a String para poder concatenar
		}
		else if (asciiChar == 13 && num != "")		// Har� la funcion del enter
		{
			cout << endl;							// Har� un salto de linea
			break;									// Terminar� el while
		}
		else if (asciiChar == 8 && num == "")
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);	// Reproducir� el sonido de alerta en caso de que el espacio est� vacio
		}
		else if (asciiChar == 8)					// Har� la funcion del Backspace
		{
			cout << '\b';							// Mover� el cursor un caracter atr�s
			cout << " ";							// Remplazar� el valor por un espacio
			cout << '\b';
			num = num.substr(0, num.size() - 1);	// Borrar� el ultimo valor del string
		}
	} while (1);

	return (num);
}

string Validaciones::confirmacionDefS()			// Utiliza la misma estructura que el de solo aceptarNumeros()
{
	int asciiChar = 0;
	string letra = "";
	do
	{
		asciiChar = _getch();
		if (asciiChar == 13 && letra == "")
		{
			letra = "S";
			cout << endl;
			break;
		}
		else if (asciiChar == 13 && letra != "")
		{
			cout << endl;
			break;
		}
		else if (asciiChar == 8 && letra == "")
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
		}
		else if (asciiChar == 8)
		{
			cout << '\b';
			cout << " ";
			cout << '\b';
			letra = letra.substr(0, letra.size() - 1);
		}
		else if (letra.length() >= 1)
		{
			PlaySound(TEXT("SystemStart"), NULL, SND_ALIAS | SND_ASYNC);
		}
		else if (asciiChar == 83)
		{
			cout << "S";
			letra = "S";
		}
		else if (asciiChar == 115)
		{
			cout << "s";
			letra = "S";
		}
		else if (asciiChar == 78)
		{
			cout << "N";
			letra = "N";
		}
		else if (asciiChar == 110)
		{
			cout << "n";
			letra = "N";
		}
	} while (1);

	return (letra);
}