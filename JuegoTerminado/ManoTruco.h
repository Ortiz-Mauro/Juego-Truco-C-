#ifndef MANO_TRUCO
#define MANO_TRUCO

#include "Carta.h"
#include "EnumsTruco.h"

using UndavTrucoCarta::Carta;
using UndavTrucoEnums::TipoResultadoManoTruco;

namespace UndavTrucoManoTruco{
	struct ManoTruco;
	
	// Precondicion: @cartaJugador1 y @cartaJugador2 son instancias validas
	// Postcondicion: Devuelve una intancia valida de ManoTruco que tiene las 
	// cartas de jugador 1 y jugador 2
	ManoTruco* CrearManoTruco(Carta* cartaJugador1, Carta* cartaJugador2);
	
	// Precondicion: @manoTruco es una instancia valida
	// Postcondicion: Devuelve el resultado de jugar una mano de truco para las cartas
	// que tiene @manoTruco
	TipoResultadoManoTruco Jugar(const ManoTruco* manoTruco);
	
	// Precondicion: @manoTruco es una instancia valida
	// Postcondicion: Devuelve la carta que corresponde a jugador 1
	Carta* ObtenerCartaJugador1(const ManoTruco* manoTruco);
	
	// Precondicion: @manoTruco es una instancia valida
	// Postcondicion: Devuelve la carta que corresponde a jugador 1
	Carta* ObtenerCartaJugador2(const ManoTruco* manoTruco);
	
	// Precondicion: @manoTruco es una instancia valida
	// Postcondicion: Libera todos los recursos asociados de @manoTruco
	void DestruirManoTruco(ManoTruco* manoTruco);	
}

#endif
