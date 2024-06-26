#include "Ataques.hpp"
#include <iostream>

void Ataques::adicionarAtaque(const std::string& ataque, int dano) {
    ataques[ataque] = dano;
}

void Ataques::mostrarOpcoes() const {
    std::cout << "Opcoes de ataque disponiveis:" << std::endl;
    for (const auto& ataque : ataques) {
        std::cout << "- " << ataque.first << std::endl;
    }
}

int Ataques::usarAtaque(const std::string& ataque) {
    auto it = ataques.find(ataque);
    if (it != ataques.end()) {
        return it->second;
    } else {
        std::cerr << "Erro: Ataque '" << ataque << "' nao encontrado." << std::endl;
        return 0;
    }
}