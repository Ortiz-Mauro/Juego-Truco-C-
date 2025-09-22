#include "JugadorTruco.h"
#include "Persona.h"
#include "Cartas.h"
#include "EnumsTruco.h"
#include <cstddef>
#include <string>

using namespace UndavTrucoCarta;
using namespace UndavTrucoPersona;
using namespace UndavTrucoCartas;
using UndavTrucoEnums::TipoCartaJugador;

namespace UndavTrucoJugadorTruco {

    struct JugadorTruco {
        Persona* persona;
        Carta* cartas[3];
        bool cartaJugada[3];
    };

    void InicializarCartas(JugadorTruco* jugador, Carta* cartas_iniciales[3]) {
        for (int i = 0; i < 3; ++i) {
            jugador->cartas[i] = (cartas_iniciales ? cartas_iniciales[i] : nullptr);
            jugador->cartaJugada[i] = false;
        }
    }

    bool EsIndiceCartaValido(int indice) {
        return (indice >= 0 && indice < 3);
    }

    JugadorTruco* CrearJugadorTruco(Persona* persona) {
        JugadorTruco* jugador = new JugadorTruco;
        jugador->persona = persona;
        InicializarCartas(jugador, nullptr);
        return jugador;
    }

    JugadorTruco* CrearJugadorTruco(std::string apodo, Cartas* cartas) {
        Persona* p = UndavTrucoPersona::CrearPersona("", "", apodo);
        JugadorTruco* jugador = CrearJugadorTruco(p);

        if (cartas != nullptr) {
            Carta* arr[3];
            int cnt = 0;
            for (int i = 0; i < 3 && i < ObtenerCantidad(cartas); ++i) {
                arr[cnt++] = UndavTrucoCartas::ObtenerCartaEnPosicion(cartas, i);
            }
            for (; cnt < 3; ++cnt) {
                arr[cnt] = nullptr;
            }
            AsignarCartas(jugador, arr);
        }

        return jugador;
    }

    Cartas* ObtenerCartas(const JugadorTruco* jugador) {
        Carta* temp[3];
        int cnt = 0;
        for (int i = 0; i < 3; ++i) {
            if (jugador->cartas[i] != nullptr && !jugador->cartaJugada[i]) {
                temp[cnt++] = jugador->cartas[i];
            }
        }
        return UndavTrucoCartas::CrearCartas(temp, cnt);
    }

    Persona* ObtenerPersona(const JugadorTruco* jugador) {
        return jugador->persona;
    }

    void AsignarCartas(JugadorTruco* jugador, Carta* cartas[3]) {
        InicializarCartas(jugador, cartas);
    }

    int ObtenerCantidadCartas(const JugadorTruco* jugador) {
        int cantidad = 0;
        for (int i = 0; i < 3; ++i) {
            if (jugador->cartas[i] != nullptr && !jugador->cartaJugada[i]) {
                cantidad++;
            }
        }
        return cantidad;
    }

    Carta* ObtenerCarta(const JugadorTruco* jugador, TipoCartaJugador carta) {
        if (EsIndiceCartaValido(carta)) {
            return jugador->cartas[carta];
        }
        return nullptr;
    }

    Carta* JugarCarta(JugadorTruco* jugador, TipoCartaJugador carta) {
        if (!EsIndiceCartaValido(carta))
            return nullptr;

        for (int i = carta; i < 3; ++i) {
            if (jugador->cartas[i] != nullptr && !jugador->cartaJugada[i]) {
                jugador->cartaJugada[i] = true;
                Carta* seleccionada = jugador->cartas[i];
                jugador->cartas[i] = nullptr;
                return seleccionada;
            }
        }

        for (int i = 0; i < carta; ++i) {
            if (jugador->cartas[i] != nullptr && !jugador->cartaJugada[i]) {
                jugador->cartaJugada[i] = true;
                Carta* seleccionada = jugador->cartas[i];
                jugador->cartas[i] = nullptr;
                return seleccionada;
            }
        }

        return nullptr;
    }

    void DestruirJugadorTruco(JugadorTruco* jugador) {
        if (jugador != nullptr) {
            UndavTrucoPersona::DestruirPersona(jugador->persona);
            delete jugador;
        }
    }
}
