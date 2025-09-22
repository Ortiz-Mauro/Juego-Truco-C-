#ifndef PERSONA
#define PERSONA

#include <string>

using std::string;

namespace UndavTrucoPersona{
	struct Persona;
	
	//Precondicion: ninguna
	//Postcondicion: Devuelve una instancia valida de Persona con nombre @nombre
	// apellido @apellido y con apodo @apodo
	Persona* CrearPersona(string nombre, string apellido, string apodo);
	
	//Precondicion: @persona es una instancia valida
	//Postcondicion: Devuelve el nombre de @persona
	string ObtenerNombre(const Persona* persona);
	
	//Precondicion: @persona es una instancia valida
	//Postcondicion: Cambia el nombre de @persona por @nuevoNombre
	void CambiarNombre(Persona* persona, string nuevoNombre);
	
	//Precondicion: @persona es una instancia valida
	//Postcondicion: Devuelve el apellido de @persona	
	string ObtenerApellido(const Persona* persona);
	
	//Precondicion: @persona es una instancia valida
	//Postcondicion: Cambia el apellido de @persona	
	void CambiarApellido(Persona* persona, string nuevoApellido);
	
	//Precondicion: @persona es una instancia valida
	//Postcondicion: Devuelve el apodo de @persona
	string ObtenerApodo(const Persona* persona);
	
	//Precondicion: @persona es una instancia valida
	//Postcondicion: Cambia el apodo de @persona	
	void CambiarApodo(Persona* persona, string nuevoApodo);
	
	//Precondicion: @persona es una instancia valida
	// Postcondicion: Libera todos los recursos asociados de @persona
	void DestruirPersona(Persona* persona);
}

#endif
