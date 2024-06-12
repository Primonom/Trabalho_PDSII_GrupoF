#include "Monstro.hpp"
#include <iostream>

static Monstro monstro1("Ogro", 100, 10, 20); // Ordem dos parâmetros corrigida
static Monstro monstro2("Esqueleto", 20, 5, 15); // Ordem dos parâmetros corrigida

Monstro::Monstro(const std::string& nome, int saude, int forca, int defesa)
    : Entidade(nome, saude, defesa, forca, 0) {}

Monstro::~Monstro() {}

void Monstro::exibir() const {
    std::cout << "Monstro: " << std::endl;
    Entidade::exibir();
}

void Monstro::adicionarAtaque(const std::string& ataque) {
    int dano = 10; // Defina o dano do ataque aqui
    ataques.adicionarAtaque(ataque, dano);
}

void Monstro::mostrarOpcoesAtaque() const {
    ataques.mostrarOpcoes();
}

void Monstro::usarAtaque(Entidade& alvo, const std::string& ataque) {
    std::cout << nome << " usou " << ataque << " em " << alvo.getNome() << std::endl;
}

Monstro* obterMonstro(const std::string& nome) {
    if (nome == "Ogro") {
        return &monstro1;
    } else if (nome == "Esqueleto") {
        return &monstro2;
    } else {
        return nullptr;
    }
}
