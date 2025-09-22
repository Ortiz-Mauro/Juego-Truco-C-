#ifndef BOT_JUGADOR_TRUCO_H
#define BOT_JUGADOR_TRUCO_H
#include "JugadorTruco.h"
#include "Carta.h"
#include "ContextoJuegoTruco.h"

using UndavTrucoJugadorTruco::JugadorTruco;
using UndavTrucoCarta::Carta;
using UndavTrucoContextoJuegoTruco::ContextoJuegoTruco;

namespace UndavTrucoBotJugadorTruco{
	struct BotJugadorTruco;
	enum TipoEstrategiaBot{Conservador, Ariesgado};
	    TipoEstrategiaBot ObtenerEstrategiaBot(BotJugadorTruco* bot);

	// Precondicion: @jugador de truco es una instancia valida
	// Postcondicion: Si @jugador tiene las 3 cartas para jugar al truco devuelve una
	// instancia valida de BotJugadorTruco que juega al truco segun la @estrategiaBot.
	// Caso contrario devuelve NULL 
	BotJugadorTruco* CrearBot(JugadorTruco* jugador, TipoEstrategiaBot estrategiaBot);
	
	// Precondicion: @bot es una instancia valida
	// Postcondicion: Devuelve el jugador de truco que tiene @bot
	JugadorTruco* ObtenerJugadorTruco(const BotJugadorTruco* bot);
	
	// Precondicion: @bot y @contextoJuego son instancias validas. @cartaJugadaPorOtroJugador representa 
	// la carta que jugo otro jugador en una mano de truco. Si correspone al bot jugar primero en la mano 
	// @cartaJugadaPorOtroJugador es NULL
	// Postcondicion: Si el jugador de truco tiene cartas para jugar, juega la carta de JugadorTruco 
	// segun su estrategia de juego y devuelve la carta jugada. Caso contrario devuelve NULL 
	Carta* JugarCarta(BotJugadorTruco* bot, ContextoJuegoTruco* contextoJuego, Carta* cartaJugadaPorOtroJugador);
	
	// Precondicion: @bot es una instancia valida
	// Postcondicion: libera todos los recusos asociados a @bot
	void DestruirBotJugadorTruco(BotJugadorTruco* bot);

    bool AceptarTruco(BotJugadorTruco* bot);

}
#endif