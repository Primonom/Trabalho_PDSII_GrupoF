// personagem.cpp

#include "personagem.hpp"
#include <iostream>

void Personagem::exibir() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Classe: " << classe << std::endl;
    std::cout << "Saúde: " << saude << std::endl;
    std::cout << "Defesa: " << defesa << std::endl;
    std::cout << "Magia: " << magia << std::endl;
    std::cout << "Ataque: " << ataque << std::endl;
    std::cout << "Agilidade: " << agilidade << std::endl;
}

void Personagem::distribuirPontos(int pontos) {
    std::cout << "Distribuindo " << pontos << " pontos para os atributos." << std::endl;
    std::cout << "Digite quantos pontos deseja atribuir a cada atributo:" << std::endl;

    std::cout << "Saúde: ";
    std::cin >> saude;

    std::cout << "Defesa: ";
    std::cin >> defesa;

    std::cout << "Magia: ";
    std::cin >> magia;

    std::cout << "Ataque: ";
    std::cin >> ataque;

    std::cout << "Agilidade: ";
    std::cin >> agilidade;
}

Personagem criarPersonagem(std::string nome, std::string classe) {
    Personagem novoPersonagem;
    novoPersonagem.nome = nome;
    novoPersonagem.classe = classe;
    return novoPersonagem;
}

void Personagem::addXP(int amount) {
    xp += amount;

    while (xp >= xpToLevelUp) {
        xp -= xpToLevelUp;
        level++;
        xpToLevelUp *= 2;
    }
}

int Personagem::getLevel() const {
    return level;
}

int Personagem::getXP() const {
    return xp;
}