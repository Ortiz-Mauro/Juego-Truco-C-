#ifndef TRUCO_H
#define TRUCO_H

#include "JugadorTruco.h"
#include "BotJugadorTruco.h"
#include "ContextoJuegoTruco.h"

namespace UndavTruco {
    enum EstadoCanto {
        NINGUNO,
        TRUCO,
        RETRUCO,
        VALE_CUATRO
    };

    struct Truco {
        UndavTrucoJugadorTruco::JugadorTruco* humano;
        UndavTrucoBotJugadorTruco::BotJugadorTruco* bot;
        UndavTrucoContextoJuegoTruco::ContextoJuegoTruco* contexto;
        int puntosHumano;
        int puntosBot;
        bool manoHumano;
        EstadoCanto cantoActual;
        bool esperandoRespuesta;
    };

    Truco* CrearTruco(
        UndavTrucoJugadorTruco::JugadorTruco* humano, 
        UndavTrucoBotJugadorTruco::BotJugadorTruco* bot);
    
    void Jugar(Truco* truco);
    void Destruir(Truco* truco);

    bool CantarTruco(Truco* truco);
    bool CantarRetruco(Truco* truco);
    bool CantarValeCuatro(Truco* truco);
    bool ResponderCanto(Truco* truco, bool aceptar);
}

#endif