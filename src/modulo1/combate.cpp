#include "Combate.hpp"
#include <iostream>

void iniciarCombate(Personagem& personagem, Monstro& monstro) {
    std::cout << "Inicia o combate entre " << personagem.getNome() << " e " << monstro.getNome() << "!" << std::endl;

    while (personagem.getSaude() > 0 && monstro.getSaude() > 0) {
        // Turno do personagem
        std::cout << "\nEscolha um ataque para usar:" << std::endl;
        personagem.mostrarOpcoesAtaque();  // Mostra as opções de ataque
        std::string ataqueEscolhido = personagem.escolherAtaque();
        int danoPersonagem = personagem.usarAtaque(ataqueEscolhido);  // Supondo que usarAtaque() é uma função que retorna o dano
        monstro.receberDano(danoPersonagem);
        std::cout << personagem.getNome() << " ataca " << monstro.getNome() << " com " << ataqueEscolhido << " causando " << danoPersonagem << " de dano." << std::endl;

        // Verifica se o monstro ainda está vivo
        if (monstro.getSaude() <= 0) {
            std::cout << monstro.getNome() << " foi derrotado!" << std::endl;
            break;
        }

        // Turno do monstro
        int danoMonstro = monstro.getAtaque() - personagem.getDefesa();
        if (danoMonstro < 0) {
            danoMonstro = 0;
        }
        personagem.receberDano(danoMonstro);
        std::cout << monstro.getNome() << " ataca " << personagem.getNome() << " causando " << danoMonstro << " de dano." << std::endl;

        // Verifica se o personagem ainda está vivo
        if (personagem.getSaude() <= 0) {
            std::cout << personagem.getNome() << " foi derrotado!" << std::endl;
            break;
        }
    }
}