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
    while (pontos > 0) {
        std::cout << "Distribuindo " << pontos << " pontos para os atributos." << std::endl;
        std::cout << "Digite quantos pontos deseja atribuir a cada atributo:" << std::endl;

        std::cout << "Saude: ";
        std::cin >> saude;
        saude = std::min(saude, pontos);
        pontos -= saude;

        std::cout << "Defesa: ";
        std::cin >> defesa;
        defesa = std::min(defesa, pontos);
        pontos -= defesa;

        std::cout << "Magia: ";
        std::cin >> magia;
        magia = std::min(magia, pontos);
        pontos -= magia;

        std::cout << "Ataque: ";
        std::cin >> ataque;
        ataque = std::min(ataque, pontos);
        pontos -= ataque;

        std::cout << "Agilidade: ";
        std::cin >> agilidade;
        agilidade = std::min(agilidade, pontos);
        pontos -= agilidade;

        std::cout << "Pontos restantes: " << pontos << std::endl;
    }
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

/*  IMPLEMENTAÇÃO DO CÓDIGO PRINCIPAL

// Create a new character
Personagem myCharacter = criarPersonagem("John", "Warrior");

// The character gains 150 XP
myCharacter.addXP(150);

// Print the character's current level and XP
std::cout << "Level: " << myCharacter.getLevel() << ", XP: " << myCharacter.getXP() << std::endl;

// The character gains 200 XP
myCharacter.addXP(200);

// Print the character's current level and XP
std::cout << "Level: " << myCharacter.getLevel() << ", XP: " << myCharacter.getXP() << std::endl;

*/