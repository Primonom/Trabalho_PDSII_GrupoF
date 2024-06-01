#include "Combate.hpp"
#include <iostream>

void combate(Personagem& jogador, Monstro& inimigo, Ataques& ataquesJogador) {
    std::cout << "Inicia o combate entre " << jogador.getNome() << " e " << inimigo.getNome() << "!" << std::endl;

    while (jogador.getSaude() > 0 && inimigo.getSaude() > 0) {
        // Turno do jogador
        std::string ataqueEscolhido = ataquesJogador.escolherAtaque();
        int danoJogador = jogador.getAtaque() - inimigo.getDefesa();
        if (danoJogador < 0) {
            danoJogador = 0;
        }
        inimigo.receberDano(danoJogador);
        std::cout << jogador.getNome() << " ataca " << inimigo.getNome() << " com " << ataqueEscolhido << " causando " << danoJogador << " de dano." << std::endl;
        if (inimigo.getSaude() <= 0) {
            std::cout << inimigo.getNome() << " foi derrotado!" << std::endl;
            break;
        }

        // Turno do monstro
        int danoMonstro = inimigo.getAtaque() - jogador.getDefesa();
        if (danoMonstro < 0) {
            danoMonstro = 0;
        }
        jogador.receberDano(danoMonstro);
        std::cout << inimigo.getNome() << " ataca " << jogador.getNome() << " causando " << danoMonstro << " de dano." << std::endl;
        if (jogador.getSaude() <= 0) {
            std::cout << jogador.getNome() << " foi derrotado!" << std::endl;
            break;
        }
    }
}
    