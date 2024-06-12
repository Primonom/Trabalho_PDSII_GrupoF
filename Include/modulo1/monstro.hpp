#ifndef MONSTRO_HPP
#define MONSTRO_HPP

#include "Entidade.hpp"
#include "Ataques.hpp"
#include <string>

class Monstro : public Entidade {
private:
    Ataques ataques;

public:
    Monstro(const std::string& nome, int saude, int forca, int defesa); // Corrigido o parâmetro 'forca'
    virtual ~Monstro();

    void exibir() const override;

    void adicionarAtaque(const std::string& ataque);
    void mostrarOpcoesAtaque() const;
    void usarAtaque(Entidade& alvo, const std::string& ataque);
};

Monstro* obterMonstro(const std::string& nome);

#endif 
