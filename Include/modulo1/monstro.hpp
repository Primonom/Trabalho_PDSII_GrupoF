#ifndef MONSTRO_HPP
#define MONSTRO_HPP

#include "Entidade.hpp"

class Monstro : public Entidade {
public:
    Monstro(const std::string& nome, int saude, int forca, int defesa);
    virtual ~Monstro();

    void exibir() const override;
};

Monstro* obterMonstro(const std::string& nome);

#endif
