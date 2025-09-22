#ifndef TRUCO_CARTAS
#define TRUCO_CARTAS

#include "Carta.h"

using UndavTrucoCarta::Carta;

namespace UndavTrucoCartas{
	struct Cartas;
	/*struct Cartas {
    Carta* cartas[40];
    int cantidad;
    };*/

	// Precondicion: Ninguna
	// Postcondicion: Devuelve una instancia valida de Cartas 
	// que representa un mazo de cartas vacio
	Cartas* CrearMazoTruco();
	
	// Precondicion: Ninguna
	// Postcondicion: Devuelve una instancia valida de Cartas 
	// que representa el mazo de cartas necesario para jugar al truco
	Cartas* CrearMazoVacio();
	
	// Precondicion: Ninguna
	// Postcondicion: Devuelve una instancia valida de Cartas 
	// que representa un mazo que contine los items de @cartas 
	Cartas* CrearCartas(Carta* cartas[], int cantidad);
	
	// Precondicion: @cartas es una instancia valida
	// Postcondicion: Realiza una mezcla uniformemente random
	void Mezclar(Cartas* cartas);

	// Precondicion: @cartas es una instancia valida
	// Postcondicion: Realiza un orden descendente de las cartas tomando como
	// clave de ordenamiento su valor en el truco (de mayor a menor) 	
	void OrdenarMayorAMenorPorValorEnTruco(Cartas* cartas);
	
	// Precondicion: @cartas es una instancia valida
	// Postcondicion: Agrega en @cartas a @carta en la primera posicion
	void AgregarComoPrimeraCarta(Cartas* cartas, Carta* carta);

	// Precondicion: @cartas es una instancia valida
	// Postcondicion: Agrega en @cartas a @carta en la ultima posicion
	void AgregarComoUltimaCarta(Cartas* cartas, Carta* carta);
	
	// Precondicion: @cartas es una instancia valida
	// Postcondicion: Agrega en @cartas a @carta en la ultima posicion
	Carta* QuitarPrimeraCarta(Cartas* cartas);
	
	// Precondicion: @cartas es una instancia valida
	// Postcondicion: Agrega en @cartas a @carta en la ultima posicion
	Carta* QuitarUltimaCarta(Cartas* cartas);
	
	// Precondicion: @cartas es una instancia valida
	// Postcondicion: Devuelve la carta que que esta en @cartas en la posicion 
	// @posicion. Si @posicion es un valor fuera de rango devuelve NULL
	Carta* ObtenerCartaEnPosicion(const Cartas* cartas, int posicion);
	
	// Precondicion: @cartas es una instancia valida
	// Postcondicion: Libera todos los recursos asociados de @cartas
	void DestruirCartas(Cartas* cartas);

	int ObtenerCantidad(const Cartas* cartas);
}

#endif
