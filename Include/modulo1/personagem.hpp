#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>
#include <iostream>

class Personagem {
protected:
    int saude;
    int defesa;

public:
    std::string nome;
    std::string classe;
    int magia;
    int ataque;
    int agilidade;
    int xp = 0;
    int level = 1;
    int xpToLevelUp = 100;

    // Construtor
    Personagem(std::string nome, std::string classe, int saude, int defesa);

    // Destrutor
    virtual ~Personagem();

    void exibir() const;
    void distribuirPontos(int pontos);
    void addXP(int amount);
    int getLevel() const;
    int getXP() const;

    // Sobrecarga do operador <<
    friend std::ostream& operator<<(std::ostream& os, const Personagem& personagem);
};

Personagem criarPersonagem(std::string nome, std::string classe);

#endif