#include "ManoTruco.h"
#include "Carta.h"
#include "EnumsTruco.h" 

using UndavTrucoCarta::Carta;
using UndavTrucoEnums::TipoResultadoManoTruco;  
using UndavTrucoEnums::GANO_JUGADOR1;           
using UndavTrucoEnums::GANO_JUGADOR2;
using UndavTrucoEnums::EMPATE;

namespace UndavTrucoManoTruco {

	struct ManoTruco {
		Carta* cartaJugador1;
		Carta* cartaJugador2;
	};

	// Funcion para comparar cartas de truco
	int ObtenerValorTruco(const Carta* carta) {
        int valor = UndavTrucoCarta::ObtenerValor(carta);
        UndavTrucoCarta::TipoPalo palo = UndavTrucoCarta::ObtenerPalo(carta);

        if (valor == 1 && palo == UndavTrucoCarta::ESPADA) return 14;
        if (valor == 1 && palo == UndavTrucoCarta::BASTO) return 13;
        if (valor == 7 && palo == UndavTrucoCarta::ESPADA) return 12;
        if (valor == 7 && palo == UndavTrucoCarta::ORO) return 11;
		if (valor == 3) return 10;
		if (valor == 2) return 9;
		if (valor == 1) return 8;
		if (valor == 12) return 7;
		if (valor == 11) return 6;
		if (valor == 10) return 5;
		if (valor == 7) return 4;
		if (valor == 6) return 3;
		if (valor == 5) return 2;
		if (valor == 4) return 1;

		return 0; // No deberia si los valores están bien validados
	}

	ManoTruco* CrearManoTruco(Carta* cartaJugador1, Carta* cartaJugador2) {
		ManoTruco* mano = new ManoTruco;
		mano->cartaJugador1 = cartaJugador1;
		mano->cartaJugador2 = cartaJugador2;
		return mano;
	}

	TipoResultadoManoTruco Jugar(const ManoTruco* manoTruco) {
		int valor1 = ObtenerValorTruco(manoTruco->cartaJugador1);
		int valor2 = ObtenerValorTruco(manoTruco->cartaJugador2);

		if (valor1 > valor2) return GANO_JUGADOR1;
        else if (valor2 > valor1) return GANO_JUGADOR2;
		return EMPATE;
	}

	Carta* ObtenerCartaJugador1(const ManoTruco* manoTruco) {
		return manoTruco->cartaJugador1;
	}

	Carta* ObtenerCartaJugador2(const ManoTruco* manoTruco) {
		return manoTruco->cartaJugador2;
	}

	void DestruirManoTruco(ManoTruco* manoTruco) {
		delete manoTruco;
	}
};
