#ifndef JUGADOR_TRUCO
#define JUGADOR_TRUCO

#include "Carta.h"
#include "Cartas.h"
#include "Persona.h"
#include "EnumsTruco.h"

using UndavTrucoCarta::Carta;
using UndavTrucoPersona::Persona;
using UndavTrucoCartas::Cartas;
using UndavTrucoEnums::TipoCartaJugador;

namespace UndavTrucoJugadorTruco{
	struct JugadorTruco;
	
	// Precondicion: @persona es una instancia valida
	// Postcondicion: Devuelve una instancia valida de JugadorTruco
	// que tiene a @persona y no tiene ninguna carta
	JugadorTruco* CrearJugadorTruco(Persona* persona);
	
	// Precondicion: @persona es una instancia valida
	// Postcondicion: Devuelve una instancia valida de JugadorTruco
	// que tiene una @persona con apodo @apodo con sus @cartas
	JugadorTruco* CrearJugadorTruco(string apodo, Cartas* cartas);
	
	// Precondicion: @jugador es una instancia valida
	// Postcondicion: Devuelve las cartas que tiene @jugador 
	Cartas* ObtenerCartas(const JugadorTruco* jugador);
	
	// Precondicion: @jugador es una instancia valida
	// Postcondicion: Devuelve la persona asociada al @jugador 
	Persona* ObtenerPersona(const JugadorTruco* jugador);
	
	// Precondicion: @jugador es una instancia valida y @cartas tiene 3 instancias validas de Carta 
	// Postcondicion: asocia las 3 cartas de truco al @jugador dadas en @cartas. Las cartas estan listas para jugar 
	void AsignarCartas(JugadorTruco* jugador, Carta* cartas[3]);
	
	// Precondicion: @jugador es una instancia valida
	// Postcondicion: Devuelve la cantidad de cartas que tiene @jugador
	int ObtenerCantidadCartas(const JugadorTruco* jugador);
	
	// Precondicion: @jugador es una instancia valida
	// Postcondicion: Devuelve la cantidad de cartas que tiene @jugador. Si jugador no tiene cartas devuelve NULL
	Carta* ObtenerCarta(const JugadorTruco* jugador, TipoCartaJugador carta);
	
	// Precondicion: @jugador es una instancia valida
	// Postcondicion: Devuelve la carta de @jugador pedida en @carta si la carta aun no fue jugada. 
	// Si la carta ya fue jugada o el @jugador no tiene cartas devuelve NULL 
	Carta* JugarCarta(JugadorTruco* jugador, TipoCartaJugador carta);
	
	//Precondicion: @persona es una instancia valida
	//Postcondicion: Libera todos los recursos asociados de @persona
	void DestruirJugadorTruco(JugadorTruco* jugador);
}

#endif
