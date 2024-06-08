#include "Sorte.hpp"
#include <cstdlib>
#include <ctime>

Sorte::Sorte() : resultado(0), porcentagem(0.0) {
    // Inicializa a semente do gerador de números aleatórios
    std::srand(std::time(0));
}

Sorte::~Sorte() {
    std::cout << "O objeto Sorte foi destruido." << std::endl;
}

void Sorte::lancarDado() {
    // Gera um número aleatório entre 1 e 6
    resultado = std::rand() % 6 + 1;

    // Calcula a porcentagem de sorte
    porcentagem = (resultado - 1) * 100.0 / 5.0;
}

int Sorte::getResultado() const {
    return resultado;
}

double Sorte::getPorcentagem() const {
    return porcentagem;
}

std::ostream& operator<<(std::ostream& os, const Sorte& sorte) {
    os << "Sorte: Resultado do dado = " << sorte.getResultado() << ", Porcentagem de sorte = " << sorte.getPorcentagem() << "%";
    return os;
}