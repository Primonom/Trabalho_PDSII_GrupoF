#include "combate.hpp"
#include <iostream>

void combate(Personagem& jogador, Monstro& inimigo) {
    std::cout << "Inicia o combate entre " << jogador.nome << " e " << inimigo.getNome() << "!" << std::endl;

    if (jogador.agilidade >= inimigo.getAgilidade()) {
        std::cout << jogador.nome << " ataca primeiro!" << std::endl;
        while (jogador.saude > 0 && inimigo.getSaude() > 0) {
            int danoJogador = jogador.ataque - inimigo.getDefesa();
            if (danoJogador < 0) {
                danoJogador = 0;
            }
            inimigo.receberDano(danoJogador);
            std::cout << jogador.nome << " ataca " << inimigo.getNome() << " causando " << danoJogador << " de dano." << std::endl;
            if (inimigo.getSaude() <= 0) {
                std::cout << inimigo.getNome() << " foi derrotado!" << std::endl;
                break;
            }

            int danoMonstro = inimigo.getForca() - jogador.defesa;
            if (danoMonstro < 0) {
                danoMonstro = 0;
            }
            jogador.saude -= danoMonstro;
            std::cout << inimigo.getNome() << " ataca " << jogador.nome << " causando " << danoMonstro << " de dano." << std::endl;
            if (jogador.saude <= 0) {
                std::cout << jogador.nome << " foi derrotado!" << std::endl;
                break;
            }
        }
    } else {
        std::cout << inimigo.getNome() << " ataca primeiro!" << std::endl;
        while (jogador.saude > 0 && inimigo.getSaude() > 0) {
            int danoMonstro = inimigo.getForca() - jogador.defesa;
            if (danoMonstro < 0) {
                danoMonstro = 0;
            }
            jogador.saude -= danoMonstro;
            std::cout << inimigo.getNome() << " ataca " << jogador.nome << " causando " << danoMonstro << " de dano." << std::endl;
            if (jogador.saude <= 0) {
                std::cout << jogador.nome << " foi derrotado!" << std::endl;
                break;
            }

            int danoJogador = jogador.ataque - inimigo.getDefesa();
            if (danoJogador < 0) {
                danoJogador = 0;
            }
            inimigo.receberDano(danoJogador);
            std::cout << jogador.nome << " ataca " << inimigo.getNome() << " causando " << danoJogador << " de dano." << std::endl;
            if (inimigo.getSaude() <= 0) {
                std::cout << inimigo.getNome() << " foi derrotado!" << std::endl;
                break;
            }
        }
    }
}
