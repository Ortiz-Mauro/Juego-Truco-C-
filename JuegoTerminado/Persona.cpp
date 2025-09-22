#include "Persona.h"

namespace UndavTrucoPersona {

	struct Persona {
		string nombre;
		string apellido;
		string apodo;
	};

	Persona* CrearPersona(string nombre, string apellido, string apodo) {
		Persona* persona = new Persona;
		persona->nombre = nombre;
		persona->apellido = apellido;
		persona->apodo = apodo;
		return persona;
	}

	string ObtenerNombre(const Persona* persona) {
		return persona->nombre;
	}

	void CambiarNombre(Persona* persona, string nuevoNombre) {
		persona->nombre = nuevoNombre;
	}

	string ObtenerApellido(const Persona* persona) {
		return persona->apellido;
	}

	void CambiarApellido(Persona* persona, string nuevoApellido) {
		persona->apellido = nuevoApellido;
	}

	string ObtenerApodo(const Persona* persona) {
		return persona->apodo;
	}

	void CambiarApodo(Persona* persona, string nuevoApodo) {
		persona->apodo = nuevoApodo;
	}

	void DestruirPersona(Persona* persona) {
		delete persona;
	}
};
