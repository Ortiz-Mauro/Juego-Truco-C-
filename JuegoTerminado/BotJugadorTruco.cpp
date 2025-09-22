#include "BotJugadorTruco.h"
#include "EnumsTruco.h"
#include <cstdlib>


using namespace UndavTrucoBotJugadorTruco;
using namespace UndavTrucoCarta;
using namespace UndavTrucoJugadorTruco;
using UndavTrucoEnums::TipoCartaJugador;  
using UndavTrucoEnums::CARTA_1;           
using UndavTrucoEnums::CARTA_2;
using UndavTrucoEnums::CARTA_3;

struct UndavTrucoBotJugadorTruco::BotJugadorTruco {
	JugadorTruco* jugador;
	TipoEstrategiaBot estrategia;
};


TipoEstrategiaBot UndavTrucoBotJugadorTruco::ObtenerEstrategiaBot(BotJugadorTruco* bot) {
    return bot->estrategia;
}


bool UndavTrucoBotJugadorTruco::AceptarTruco(BotJugadorTruco* bot) {
    if (!bot) return false;
    if (bot->estrategia == Ariesgado) {
        return true;    
    } else {
        return (rand() % 2) == 0;
    }
}


static TipoEstrategiaBot ElegirEstrategiaRandom() {
    return (rand() % 2 == 0)
        ? TipoEstrategiaBot::Conservador
        : TipoEstrategiaBot::Ariesgado;
}

BotJugadorTruco* UndavTrucoBotJugadorTruco::CrearBot(
    JugadorTruco* jugador,
    TipoEstrategiaBot ) 
{
    if (!jugador) 
        return nullptr;

    BotJugadorTruco* bot = new BotJugadorTruco;
    bot->jugador = jugador;
    bot->estrategia = ElegirEstrategiaRandom();
    return bot;
}

JugadorTruco* UndavTrucoBotJugadorTruco::ObtenerJugadorTruco(const BotJugadorTruco* bot){
	if(bot != 0)
		return bot->jugador;
	return 0;
}


int ValorCarta(Carta* carta){
	return ObtenerValor(carta);
}

Carta* UndavTrucoBotJugadorTruco::JugarCarta(
    BotJugadorTruco* bot,
    ContextoJuegoTruco*,
    Carta* )
{
    if (!bot || !bot->jugador)
        return nullptr;

    bool primeraCarta = true;
    int mejorValor = 0;
    int peorValor  = 0;
    TipoCartaJugador tipoMejor = CARTA_1;
    TipoCartaJugador tipoPeor  = CARTA_1;

    for (int i = 0; i < 3; ++i) {
        TipoCartaJugador tipo = static_cast<TipoCartaJugador>(i);
        Carta* carta = ObtenerCarta(bot->jugador, tipo);
        if (!carta) continue;

        int valor = ObtenerValor(carta);

        if (primeraCarta) {
            mejorValor    = valor;
            peorValor     = valor;
            tipoMejor     = tipo;
            tipoPeor      = tipo;
            primeraCarta  = false;
        } else {
            if (valor > mejorValor) {
                mejorValor = valor;
                tipoMejor = tipo;
            }
            if (valor < peorValor) {
                peorValor = valor;
                tipoPeor = tipo;
            }
        }
    }

    if (primeraCarta) 
        return nullptr;

    TipoCartaJugador tipoSeleccionado =
        (bot->estrategia == Ariesgado ? tipoMejor : tipoPeor);

    return JugarCarta(bot->jugador, tipoSeleccionado);
}



void UndavTrucoBotJugadorTruco::DestruirBotJugadorTruco(BotJugadorTruco* bot){
	if(bot != 0){
		delete bot;
	}
}
