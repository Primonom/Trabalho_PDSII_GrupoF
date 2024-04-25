#include "Sorte.hpp"
#include <cstdlib>
#include <ctime>

Sorte::Sorte() {
    // Inicializa a semente do gerador de números aleatórios
    std::srand(std::time(0));
}

double Sorte::lancarDado() {
    // Gera um número aleatório entre 1 e 6
    int resultado = std::rand() % 6 + 1;

    // Calcula a porcentagem de sorte
    double sorte = (resultado - 1) * 100.0 / 5.0;

    return sorte;
}