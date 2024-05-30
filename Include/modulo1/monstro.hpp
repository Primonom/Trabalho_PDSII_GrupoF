#ifndef MONSTRO_HPP
#define MONSTRO_HPP

#include <string>
#include "personagem.hpp"

class Monstro : public Personagem {
private:
    int forca;

public:
    // Construtor
    Monstro(std::string nome, int saude, int forca, int defesa);

    // Métodos para obter informações do monstro
    int getForca() const;

    // Métodos para atualizar informações do monstro
    void receberDano(int dano);

    // Sobrecarga do operador <<
    friend std::ostream& operator<<(std::ostream& os, const Monstro& monstro);
};

// Função para obter um ponteiro para um monstro específico
Monstro* obterMonstro(std::string nome);

#endif