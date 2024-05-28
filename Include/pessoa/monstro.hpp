// Monstro.hpp

#ifndef MONSTRO_HPP
#define MONSTRO_HPP

#include <string>

class Monstro {
private:
    std::string nome;
    int saude;
    int forca;
    int defesa;

public:
    // Construtor
    Monstro(std::string nome, int saude, int forca, int defesa);

    // Métodos para obter informações do monstro
    std::string getNome() const;
    int getSaude() const;
    int getForca() const;
    int getDefesa() const;

    // Métodos para atualizar informações do monstro
    void receberDano(int dano);
};

// Função para obter um ponteiro para um monstro específico
Monstro* obterMonstro(std::string nome);

#endif
