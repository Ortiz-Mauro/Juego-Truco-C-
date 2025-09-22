#include "ContextoJuegoTruco.h"
#include "JugadorTruco.h"
#include "EnumsTruco.h"

using namespace UndavTrucoJugadorTruco;
using UndavTrucoEnums::TipoResultadoManoTruco; 

namespace UndavTrucoContextoJuegoTruco {
    struct ContextoJuegoTruco {
        JugadorTruco* jugador1;
        JugadorTruco* jugador2;
        int manosGanadasJugador1;
        int manosGanadasJugador2;
        int manosJugadas;
    };

    ContextoJuegoTruco* CrearContextoJuegoTruco(JugadorTruco* jugador1, JugadorTruco* jugador2) {
        if (jugador1 == nullptr || jugador2 == nullptr) {
            return nullptr;
        }

        ContextoJuegoTruco* contexto = new ContextoJuegoTruco;
        contexto->jugador1 = jugador1;
        contexto->jugador2 = jugador2;
        contexto->manosGanadasJugador1 = 0;
        contexto->manosGanadasJugador2 = 0;
        contexto->manosJugadas = 0;

        return contexto;
    }

    bool JuegoTerminado(const ContextoJuegoTruco* contexto) {
        return contexto->manosGanadasJugador1 >= 2 || contexto->manosGanadasJugador2 >= 2;
    }

    void AgregarResultadoManoTruco(ContextoJuegoTruco* contexto, TipoResultadoManoTruco resultado) {
        if (!JuegoTerminado(contexto)) {
            if (resultado == UndavTrucoEnums::GANO_JUGADOR1) { 
                contexto->manosGanadasJugador1++;
            } else if (resultado == UndavTrucoEnums::GANO_JUGADOR2) {  
                contexto->manosGanadasJugador2++;
            }
            contexto->manosJugadas++;
        }
    }

    int ObtenerCantidadManosGandasJugador1(const ContextoJuegoTruco* contexto) {
        return contexto->manosGanadasJugador1;
    }

    int ObtenerCantidadManosGandasJugador2(const ContextoJuegoTruco* contexto) {
        return contexto->manosGanadasJugador2;
    }

    int ObtenerCantidadManosJugadas(const ContextoJuegoTruco* contexto) {
        return contexto->manosJugadas;
    }

    void DestruirContextoJuegoTruco(ContextoJuegoTruco* contexto) {
        delete contexto;
    }
}
