#include "Carta.h"
#include <string>

namespace UndavTrucoCarta {
    struct Carta {                      
        TipoPalo palo;                
        int valor;
    };

    bool EsPaloValido(TipoPalo palo) {
    return palo == ORO || palo == COPA || palo == ESPADA || palo == BASTO;
    }

    Carta* CrearCarta(TipoPalo palo, int valor) {
    if (EsPaloValido(palo) && ((valor >= 1 && valor <= 7) || (valor >= 10 && valor <= 12))) {
        Carta* nueva = new Carta;
        nueva->palo = palo;
        nueva->valor = valor;
        return nueva;
    }
    return nullptr;
    }

    int ObtenerValor(const Carta* carta) {
        return carta->valor;
    }

    TipoPalo ObtenerPalo(const Carta* carta) {
        return carta->palo;
    }

    string ObtenerStringPalo(const Carta* carta) {
        switch (carta->palo) {
            case ORO: return "Oro";
            case COPA: return "Copa";
            case ESPADA: return "Espada";
            case BASTO: return "Basto";
            default: return "Desconocido";
        }
    }

    void DestruirCarta(Carta* carta) {
        delete carta;
    }
};