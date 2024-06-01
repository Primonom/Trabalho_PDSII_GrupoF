#include "Ataques.hpp"
#include <iostream>

void Ataques::adicionarAtaque(const std::string& ataque) {
    ataques.push_back(ataque);
}

void Ataques::mostrarOpcoes() const {
    std::cout << "Opções de ataque disponíveis:" << std::endl;
    for (const auto& ataque : ataques) {
        std::cout << "- " << ataque << std::endl;
    }
}

std::string Ataques::escolherAtaque() const {
    std::cout << "Escolha o ataque:" << std::endl;
    mostrarOpcoes();
    std::string escolha;
    std::cin >> escolha;
    return escolha;
}
