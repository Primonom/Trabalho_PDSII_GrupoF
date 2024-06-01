#include "Monstro.hpp"

// Declaração das variáveis estáticas
static Monstro monstro1("Ogro", 100, 20, 10);
static Monstro monstro2("Esqueleto", 80, 15, 5);

Monstro* obterMonstro(const std::string& nome) {
    if (nome == "Ogro") {
        return &monstro1;
    } else if (nome == "Esqueleto") {
        return &monstro2;
    } else {
        return nullptr;
    }
}

Monstro::Monstro(const std::string& nome, int saude, int forca, int defesa)
    : Entidade(nome, saude, defesa, forca, 0) {}

Monstro::~Monstro() {}

void Monstro::exibir() const {
    std::cout << "Monstro: " << std::endl;
    Entidade::exibir();
}
