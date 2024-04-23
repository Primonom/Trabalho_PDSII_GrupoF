
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

    void exibir();
    void distribuirPontos(int pontos);
};

Personagem criarPersonagem(std::string nome, std::string classe);

#endif
