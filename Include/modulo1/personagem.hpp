#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include "Entidade.hpp"
#include <string>

class Personagem : public Entidade {
private:
    std::string classe;
    int magia;
    int xp;
    int level;
    int xpToLevelUp;

public:
    Personagem(const std::string& nome, const std::string& classe, int saude, int defesa, int ataque, int agilidade, int magia);
    virtual ~Personagem();

    void exibir() const override;
    void distribuirPontos(int pontos);
    void addXP(int amount);
    int getLevel() const;
    int getXP() const;

    friend std::ostream& operator<<(std::ostream& os, const Personagem& personagem);
};

Personagem criarPersonagem(const std::string& nome, const std::string& classe);

#endif
