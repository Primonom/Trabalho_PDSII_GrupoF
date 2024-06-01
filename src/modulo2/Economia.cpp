#include "Economia.hpp"

Economia::Economia() {
    ouro = 0; // Inicializa o ouro do jogador como 0 ao iniciar o jogo
}

Economia::~Economia() {
    // Implementação do destrutor
    std::cout << "O objeto Economia foi destruído." << std::endl;
}

void Economia::ganharOuro(int quantidade) {
    ouro += quantidade; // Adiciona a quantidade de ouro ganha ao total
}

bool Economia::gastarOuro(int quantidade) {
    if (ouro >= quantidade) {
        ouro -= quantidade; // Subtrai a quantidade de ouro gasta do total, se houver ouro suficiente
        return true;
    } else {
        std::cout << "Você não tem ouro suficiente para gastar." << std::endl;
        return false;
    }
}

int Economia::getOuro() const {
    return ouro; // Retorna a quantidade atual de ouro do jogador
}

// Implementação da sobrecarga do operador <<
std::ostream& operator<<(std::ostream& os, const Economia& economia) {
    os << "Ouro: " << economia.getOuro();
    return os;
}