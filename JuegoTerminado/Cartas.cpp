#include "Cartas.h"
#include <cstdlib> 
#include "Carta.h"
#include <ctime> 
using namespace UndavTrucoCarta;

namespace UndavTrucoCartas {
	struct Cartas {
    Carta* cartas[40];
    int cantidad;
	};

	// nueva funcion
	int ObtenerCantidad(const Cartas* cartas) {
    return cartas->cantidad;
	}

	Cartas* CrearMazoVacio() {
		Cartas* mazo = new Cartas;
		mazo->cantidad = 0;
		return mazo;
	}

	Cartas* CrearMazoTruco() {
		Cartas* mazo = CrearMazoVacio();
		int paloMax = 4; // 0 a 3
		for (int palo = 0; palo < paloMax; palo++) {
			for (int valor = 1; valor <= 12; valor++) {
				if (valor != 8 && valor != 9) {
					mazo->cartas[mazo->cantidad++] = CrearCarta((TipoPalo)palo, valor);
				}
			}
		}
		return mazo;
	}

	Cartas* CrearCartas(Carta* cartas[], int cantidad) {
		Cartas* nuevo = CrearMazoVacio();
		for (int i = 0; i < cantidad && i < 40; ++i) {
			nuevo->cartas[nuevo->cantidad++] = cartas[i];
		}
		return nuevo;
	}

	void Mezclar(Cartas* cartas) {
		std::srand(std::time(0));
		for (int i = cartas->cantidad - 1; i > 0; --i) {
			int j = rand() % (i + 1);
			Carta* temp = cartas->cartas[i];
			cartas->cartas[i] = cartas->cartas[j];
			cartas->cartas[j] = temp;
		}
	}

	void OrdenarMayorAMenorPorValorEnTruco(Cartas* cartas) {
		for (int i = 0; i < cartas->cantidad - 1; ++i) {
			for (int j = i + 1; j < cartas->cantidad; ++j) {
				if (ObtenerValor(cartas->cartas[i]) < ObtenerValor(cartas->cartas[j])) {
					Carta* temp = cartas->cartas[i];
					cartas->cartas[i] = cartas->cartas[j];
					cartas->cartas[j] = temp;
				}
			}
		}
	}

	void AgregarComoPrimeraCarta(Cartas* cartas, Carta* carta) {
		if (cartas->cantidad < 40) {
			for (int i = cartas->cantidad; i > 0; --i) {
				cartas->cartas[i] = cartas->cartas[i - 1];
			}
			cartas->cartas[0] = carta;
			cartas->cantidad++;
		}
	}

	void AgregarComoUltimaCarta(Cartas* cartas, Carta* carta) {
		if (cartas->cantidad < 40) {
			cartas->cartas[cartas->cantidad++] = carta;
		}
	}

	Carta* QuitarPrimeraCarta(Cartas* cartas) {
		if (cartas->cantidad == 0) return nullptr;
		Carta* primera = cartas->cartas[0];
		for (int i = 0; i < cartas->cantidad - 1; ++i) {
			cartas->cartas[i] = cartas->cartas[i + 1];
		}
		cartas->cantidad--;
		return primera;
	}

	Carta* QuitarUltimaCarta(Cartas* cartas) {
		if (cartas->cantidad == 0) return nullptr;
		return cartas->cartas[--cartas->cantidad];
	}

	Carta* ObtenerCartaEnPosicion(const Cartas* cartas, int posicion) {
		if (posicion < 0 || posicion >= cartas->cantidad) return nullptr;
		return cartas->cartas[posicion];
	}

	void DestruirCartas(Cartas* cartas) {
		for (int i = 0; i < cartas->cantidad; ++i) {
			DestruirCarta(cartas->cartas[i]);
		}
		delete cartas;
	}
}