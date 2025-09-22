#ifndef TRUCO_CARTA
#define TRUCO_CARTA
#include <string>

using std::string;

namespace UndavTrucoCarta{
	struct Carta;
	enum TipoPalo{ORO, COPA, ESPADA, BASTO};
	
	//Precondicion: ninguna
	//Postcondicion: Devuelve una instancia valida de Carta. Si @valor no es un valor 
	//valido para una carta devuelve NULL
	Carta* CrearCarta(TipoPalo palo, int valor);
	
	//Precondicion: @carta es una instancia valida
	//Postcondicion: Devuelve el valor de @carta
	int ObtenerValor(const Carta* carta);
	
	//Precondicion: @carta es una instancia valida
	//Postcondicion: Devuelve el palo de @carta	
	TipoPalo ObtenerPalo(const Carta* carta);
	
	//Precondicion: @carta es una instancia valida
	//Postcondicion: Devuelve el palo de @carta en formato string		
	string ObtenerStringPalo(const Carta* carta);
	
	// Precondicion: @carta fue creada con CrearCarta
	// Postcondicion: Libera todos los recursos asociados de @carta
	void DestruirCarta(Carta* carta);
}

#endif
