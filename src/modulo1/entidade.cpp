#include "Entidade.hpp"
#include <iostream>

Entidade::Entidade(const std::string& nome, int saude, int defesa, int ataque, int agilidade)
    : nome(nome), saude(saude), defesa(defesa), ataque(ataque), agilidade(agilidade) {}

Entidade::~Entidade() {}

std::string Entidade::getNome() const {
    return nome;
}

int Entidade::getSaude() const {
    return saude;
}

int Entidade::getDefesa() const {
    return defesa;
}

int Entidade::getAtaque() const {
    return ataque;
}

int Entidade::getAgilidade() const {
    return agilidade;
}

void Entidade::receberDano(int dano) {
    saude -= dano;
    if (saude < 0) {
        saude = 0;
    }
}

void Entidade::exibir() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Saude: " << saude << std::endl;
    std::cout << "Defesa: " << defesa << std::endl;
    std::cout << "Ataque: " << ataque << std::endl;
    std::cout << "Agilidade: " << agilidade << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Entidade& entidade) {
    os << "Nome: " << entidade.nome << "\nSaude: " << entidade.saude << "\nDefesa: " << entidade.defesa
       << "\nAtaque: " << entidade.ataque << "\nAgilidade: " << entidade.agilidade;
    return os;
}
