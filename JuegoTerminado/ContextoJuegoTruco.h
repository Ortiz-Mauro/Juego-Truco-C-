#include "JugadorTruco.h"
#include "ManoTruco.h"
#include "EnumsTruco.h"

using UndavTrucoJugadorTruco::JugadorTruco;

namespace UndavTrucoContextoJuegoTruco{
	struct ContextoJuegoTruco;
	
	// Precondicion: @jugador1 y @jugador2 son instancias validas
	// Postcondicion: Si @jugador1 y @jugador2 pueden jugar al truco devuelve un contexto nuevo de juego que
	// donde ninguna mano fue jugada. Caso contrario devuelve NULL 
	ContextoJuegoTruco* CrearContextoJuegoTruco(JugadorTruco* jugador1, JugadorTruco* jugador2);
	
	// Precondicion: @contexto es una instancia valida
	// Postcondicion: Devuelve true si un jugador ya gano dos manos de truco. 
	// caso contrario devuelve false	
	bool JuegoTerminado(const ContextoJuegoTruco* contexto);
	
	// Precondicion: @contexto es una instancia valida
	// Postcondicion: Si el juego no termino, actualiza la informacion de contexto 
	// segun el resultado de la nueva mano de truco jugada. Caso contrario no realiza 
	// ninguna accion
	void AgregarResultadoManoTruco(ContextoJuegoTruco* contexto, TipoResultadoManoTruco resultado);
	
	// Precondicion: @contexto es una instancia valida
	// Postcondicion: Devuelve la cantidad de manos que gano el Jugador 1 
	int ObtenerCantidadManosGandasJugador1(const ContextoJuegoTruco* contexto);
	
	// Precondicion: @contexto es una instancia valida
	// Postcondicion: Devuelve la cantidad de manos que gano el Jugador 2
	int ObtenerCantidadManosGandasJugador2(const ContextoJuegoTruco* contexto);
	
	// Precondicion: @contexto es una instancia valida
	// Postcondicion: Devuelve la cantidad de manos se jugaron
	int ObtenerCantidadManosJugadas(const ContextoJuegoTruco* contexto);
	
	// Precondicion: @contexto es una instancia valida
	// Postcondicion: Libera todos los recursos asociados a @contexto
	void DestruirContextoJuegoTruco(ContextoJuegoTruco* contexto);
}
