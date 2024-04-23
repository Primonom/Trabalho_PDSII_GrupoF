
#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <string>

class Personagem {
public:
    std::string nome;
    std::string classe;
    int saude;
    int defesa;
    int magia;
    int ataque;
    int agilidade;
    int xp = 0;
    int level = 1;
    int xpToLevelUp = 100;

    void exibir();
    void distribuirPontos(int pontos);
    void addXP(int amount);
    int getLevel() const;
    int getXP() const;
};

Personagem criarPersonagem(std::string nome, std::string classe);

#endif
