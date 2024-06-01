#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include "Entidade.hpp"
#include "Ataques.hpp" // Adicionamos o header de ataques
#include <string>

class Personagem : public Entidade {
private:
    std::string classe;
    int magia;
    int xp;
    int level;
    int xpToLevelUp;
    Ataques ataques; // Adicionamos um objeto de Ataques

public:
    Personagem(const std::string& nome, const std::string& classe, int saude, int defesa, int ataque, int agilidade, int magia);
    virtual ~Personagem();

    void exibir() const override;
    void distribuirPontos(int pontos);
    void addXP(int amount);
    int getLevel() const;
    int getXP() const;
    
    // Métodos para manipular os ataques
    void adicionarAtaque(const std::string& ataque);
    void mostrarOpcoesAtaque() const;
    void usarAtaque(Personagem& alvo, const std::string& ataque);
};

Personagem criarPersonagem(const std::string& nome, const std::string& classe);

#endif
