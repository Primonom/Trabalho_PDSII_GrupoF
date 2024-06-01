#include "Personagem.hpp"
#include <iostream>
#include <algorithm>

Personagem::Personagem(const std::string& nome, const std::string& classe, int saude, int defesa, int ataque, int agilidade, int magia)
    : Entidade(nome, saude, defesa, ataque, agilidade), classe(classe), magia(magia), xp(0), level(1), xpToLevelUp(100) {}

Personagem::~Personagem() {}

void Personagem::exibir() const {
    std::cout << "Personagem: " << std::endl;
    Entidade::exibir();
    std::cout << "Classe: " << classe << std::endl;
    std::cout << "Magia: " << magia << std::endl;
    std::cout << "XP: " << xp << std::endl;
    std::cout << "Level: " << level << std::endl;
}

void Personagem::distribuirPontos(int pontos) {
    while (pontos > 0) {
        std::cout << "Distribuindo " << pontos << " pontos para os atributos." << std::endl;
        std::cout << "Digite quantos pontos deseja atribuir a cada atributo:" << std::endl;

        int pontosDistribuir;
        
        std::cout << "Saude: ";
        std::cin >> pontosDistribuir;
        saude += std::min(pontosDistribuir, pontos);
        pontos -= pontosDistribuir;

        std::cout << "Defesa: ";
        std::cin >> pontosDistribuir;
        defesa += std::min(pontosDistribuir, pontos);
        pontos -= pontosDistribuir;

        std::cout << "Magia: ";
        std::cin >> pontosDistribuir;
        magia += std::min(pontosDistribuir, pontos);
        pontos -= pontosDistribuir;

        std::cout << "Ataque: ";
        std::cin >> pontosDistribuir;
        ataque += std::min(pontosDistribuir, pontos);
        pontos -= pontosDistribuir;

        std::cout << "Agilidade: ";
        std::cin >> pontosDistribuir;
        agilidade += std::min(pontosDistribuir, pontos);
        pontos -= pontosDistribuir;

        std::cout << "Pontos restantes: " << pontos << std::endl;
    }
}

Personagem criarPersonagem(const std::string& nome, const std::string& classe) {
    return Personagem(nome, classe, 100, 10, 20, 5, 30); // Valores iniciais de exemplo
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

// Implementação dos métodos para manipular os ataques
void Personagem::adicionarAtaque(const std::string& ataque) {
    ataques.adicionarAtaque(ataque);
}

void Personagem::mostrarOpcoesAtaque() const {
    ataques.mostrarOpcoes();
}

void Personagem::usarAtaque(Personagem& alvo, const std::string& ataque) {
    std::cout << nome << " usou " << ataque << " em " << alvo.nome << std::endl;
    // Lógica para realizar o ataque...
}