#ifndef ENTIDADE_HPP
#define ENTIDADE_HPP

#include <string>
#include <iostream>

class Entidade {
protected:
    std::string nome;
    int saude;
    int defesa;
    int ataque;
    int agilidade;

public:
    Entidade(const std::string& nome, int saude, int defesa, int ataque, int agilidade);
    virtual ~Entidade();

    std::string getNome() const;
    int getSaude() const;
    int getDefesa() const;
    int getAtaque() const;
    int getAgilidade() const;
    int getDano() const { return ataque; }

    void setDano(int dano) { ataque = dano; }
    void receberDano(int dano);
    virtual void exibir() const;

    friend std::ostream& operator<<(std::ostream& os, const Entidade& entidade);
};

#endif
