#include "Truco.h"
#include "ManoTruco.h"
#include "Cartas.h"
#include "EnumsTruco.h"
#include "JugadorTruco.h"
#include "BotJugadorTruco.h"
#include "ContextoJuegoTruco.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

static void MostrarCarta(UndavTrucoCarta::Carta* carta) {
    if (carta) {
        cout << UndavTrucoCarta::ObtenerValor(carta)
             << " de " << UndavTrucoCarta::ObtenerStringPalo(carta);
    } else {
        cout << "Carta no valida";
    }
}

UndavTruco::Truco* UndavTruco::CrearTruco(
    UndavTrucoJugadorTruco::JugadorTruco* humano,
    UndavTrucoBotJugadorTruco::BotJugadorTruco* bot)
{
    Truco* truco = new Truco;
    truco->humano = humano;
    truco->bot = bot;
    truco->contexto = UndavTrucoContextoJuegoTruco::CrearContextoJuegoTruco(
        humano, UndavTrucoBotJugadorTruco::ObtenerJugadorTruco(bot));
    truco->puntosHumano = 0;
    truco->puntosBot = 0;
    truco->manoHumano = true;
    return truco;
}

void UndavTruco::Jugar(Truco* truco) {
    if (!truco) return;

    cout << "\n===== NUEVA MANO =====\n";
    cout << (truco->manoHumano ? "Vos sos mano." : "El bot es mano.") << "\n";

    auto mazo = UndavTrucoCartas::CrearMazoTruco();
    UndavTrucoCartas::Mezclar(mazo);

    UndavTrucoCarta::Carta* cartasHumanoArr[3];
    UndavTrucoCarta::Carta* cartasBotArr[3];
    for (int i = 0; i < 3; ++i) {
        cartasHumanoArr[i] = UndavTrucoCartas::QuitarPrimeraCarta(mazo);
        cartasBotArr[i] = UndavTrucoCartas::QuitarPrimeraCarta(mazo);
    }
    UndavTrucoJugadorTruco::AsignarCartas(truco->humano, cartasHumanoArr);
    UndavTrucoJugadorTruco::AsignarCartas(
        UndavTrucoBotJugadorTruco::ObtenerJugadorTruco(truco->bot),
        cartasBotArr);

    UndavTrucoCarta::Carta* cartasJugadasHumano[3] = {nullptr, nullptr, nullptr};
    UndavTrucoCarta::Carta* cartasJugadasBot[3] = {nullptr, nullptr, nullptr};
    UndavTrucoEnums::TipoResultadoManoTruco resultados[3];

    int victoriasHumano = 0, victoriasBot = 0;
    bool trucoCantado = false;
    bool cantoRechazado = false;
    int puntosEnJuego = 1;

    for (int ronda = 0; ronda < 3; ++ronda) {
        cout << "\n=== RONDA " << ronda + 1 << " ===\n";

        UndavTrucoCarta::Carta* cartaHumano = nullptr;
        UndavTrucoCarta::Carta* cartaBot = nullptr;

        if (!truco->manoHumano) {
            cartaBot = UndavTrucoBotJugadorTruco::JugarCarta(truco->bot, truco->contexto, nullptr);
            cartasJugadasBot[ronda] = cartaBot;
            cout << "El bot jugo: ";
            MostrarCarta(cartaBot);
            cout << "\n";
        }

        if (!trucoCantado) {
            auto cartasObj = UndavTrucoJugadorTruco::ObtenerCartas(truco->humano);
            int total = UndavTrucoJugadorTruco::ObtenerCantidadCartas(truco->humano);
            vector<int> disponibles;
            for (int i = 0; i < total; ++i) {
                if (UndavTrucoCartas::ObtenerCartaEnPosicion(cartasObj, i))
                    disponibles.push_back(i);
            }

            cout << "\nTus cartas:\n";
            for (int k = 0; k < (int)disponibles.size(); ++k) {
                cout << (k+1) << ": ";
                MostrarCarta(UndavTrucoCartas::ObtenerCartaEnPosicion(cartasObj, disponibles[k]));
                cout << "\n";
            }

            char opcion;
            cout << "Queres cantar Truco? (s/n): ";
            cin >> opcion;
if (opcion == 's' || opcion == 'S') {
    // Delegamos la decisión al bot
    bool acepta = UndavTrucoBotJugadorTruco::AceptarTruco(truco->bot);

    if (!acepta) {
        cout << "El bot rechazo el Truco. Ganaste la mano!\n";
        cantoRechazado = true;
        truco->puntosHumano += puntosEnJuego;
        UndavTrucoCartas::DestruirCartas(mazo);
        return;
    } else {
        cout << "El bot acepto el Truco.\n";
        trucoCantado = true;
        puntosEnJuego = 2;
    }
}

        }

        auto cartasObj = UndavTrucoJugadorTruco::ObtenerCartas(truco->humano);
        int total = UndavTrucoJugadorTruco::ObtenerCantidadCartas(truco->humano);
        vector<int> disponibles;
        for (int i = 0; i < total; ++i) {
            if (UndavTrucoCartas::ObtenerCartaEnPosicion(cartasObj, i))
                disponibles.push_back(i);
        }

        cout << "\nTus cartas:\n";
        for (int k = 0; k < (int)disponibles.size(); ++k) {
            cout << (k + 1) << ": ";
            MostrarCarta(UndavTrucoCartas::ObtenerCartaEnPosicion(cartasObj, disponibles[k]));
            cout << "\n";
        }

        int choice = 0;
        do {
            cout << "Elegi una carta (1-" << disponibles.size() << "): ";
            cin >> choice;
        } while (choice < 1 || choice > (int)disponibles.size());

        int idxReal = disponibles[choice - 1];
        cartaHumano = UndavTrucoJugadorTruco::JugarCarta(
            truco->humano, static_cast<UndavTrucoEnums::TipoCartaJugador>(idxReal));
        cartasJugadasHumano[ronda] = cartaHumano;

        if (truco->manoHumano) {
            cartaBot = UndavTrucoBotJugadorTruco::JugarCarta(truco->bot, truco->contexto, cartaHumano);
            cartasJugadasBot[ronda] = cartaBot;
            cout << "El bot jugo: ";
            MostrarCarta(cartaBot);
            cout << "\n";
        }

        cout << "Vos jugaste: ";
        MostrarCarta(cartaHumano);
        cout << "\n";

        auto mano = UndavTrucoManoTruco::CrearManoTruco(cartaHumano, cartaBot);
        auto resultado = UndavTrucoManoTruco::Jugar(mano);
        resultados[ronda] = resultado;

        if (resultado == UndavTrucoEnums::GANO_JUGADOR1) {
            cout << "Ganaste esta ronda!\n";
            victoriasHumano++;
            truco->manoHumano = true;
        } else if (resultado == UndavTrucoEnums::GANO_JUGADOR2) {
            cout << "El bot gano esta ronda.\n";
            victoriasBot++;
            truco->manoHumano = false;
        } else {
            cout << "Empate.\n";
        }

        UndavTrucoManoTruco::DestruirManoTruco(mano);

        if (victoriasHumano == 2 || victoriasBot == 2)
            break;
    }

    cout << "\n=== RESULTADO FINAL ===\n";
    if (victoriasHumano > victoriasBot) {
        cout << "Ganaste la mano!\n";
        truco->puntosHumano += puntosEnJuego;
    } else if (victoriasBot > victoriasHumano) {
        cout << "El bot gano la mano.\n";
        truco->puntosBot += puntosEnJuego;
    } else {
        if (truco->manoHumano) {
            cout << "Empate. Gana el mano (vos).\n";
            truco->puntosHumano += puntosEnJuego;
        } else {
            cout << "Empate. Gana el mano (el bot).\n";
            truco->puntosBot += puntosEnJuego;
        }
    }

cout << "\n[INFO] Estrategia del Bot esta mano: ";
if (UndavTrucoBotJugadorTruco::ObtenerEstrategiaBot(truco->bot) == UndavTrucoBotJugadorTruco::Conservador) {
    cout << "Conservador\n";
} else {
    cout << "Ariesgado\n";
}


    UndavTrucoCartas::DestruirCartas(mazo);
}

void UndavTruco::Destruir(Truco* truco) {
    if (truco) {
        UndavTrucoContextoJuegoTruco::DestruirContextoJuegoTruco(truco->contexto);
        delete truco;
    }
}
