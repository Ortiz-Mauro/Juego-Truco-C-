#include "Truco.h"
#include "Persona.h"
#include "JugadorTruco.h"
#include "BotJugadorTruco.h"
#include <iostream>
#include <ctime>

int main() {
	std::srand(std::time(0));

	UndavTrucoPersona::Persona* persona = UndavTrucoPersona::CrearPersona("", "", "Humano");
	UndavTrucoJugadorTruco::JugadorTruco* humano = UndavTrucoJugadorTruco::CrearJugadorTruco(persona);

	UndavTrucoJugadorTruco::JugadorTruco* jugadorBot = UndavTrucoJugadorTruco::CrearJugadorTruco("Bot", nullptr);
	UndavTrucoBotJugadorTruco::BotJugadorTruco* bot = UndavTrucoBotJugadorTruco::CrearBot(jugadorBot, UndavTrucoBotJugadorTruco::Conservador);

	UndavTruco::Truco* truco = UndavTruco::CrearTruco(humano, bot);

	UndavTruco::Jugar(truco);
	
	UndavTruco::Destruir(truco);
	UndavTrucoJugadorTruco::DestruirJugadorTruco(humano);
	UndavTrucoBotJugadorTruco::DestruirBotJugadorTruco(bot);

	return 0;
}
