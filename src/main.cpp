#include <iostream>
#include <random>
#include "Campanha.hpp"
#include "EscolhaClasse.hpp"
#include "Personagem.hpp"
#include "Inventario.hpp"
#include "Ataques.hpp"
#include "Economia.hpp"
#include "Sorte.hpp"
#include "Combate.hpp"

void atribuirAtributos(Personagem& personagem) {
    int pontos;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6);
    int dado = dis(gen); // Simula a rolagem de um dado de 6 lados

    if (dado == 6) {
        pontos = 10;
    } else if (dado == 1) {
        pontos = 5;
    } else if (dado == 2) {
        pontos = 6;
    } else if (dado == 3) {
        pontos = 7;
    } else if (dado == 4) {
        pontos = 8;
    } else if (dado == 5) {
        pontos = 9;
    }
    personagem.distribuirPontos(pontos);
}

int main() {
    // Solicitar ao usuário que escolha a campanha e a classe do personagem
    Campanha campanha;
    std::string nomeCampanha = campanha.escolherCampanha();
    std::string classePersonagem = escolherClasse();

    if (!nomeCampanha.empty()) {
        std::cout << "Campanha selecionada: " << nomeCampanha << std::endl;

        // Solicitar ao usuário que entre com o nome do personagem
        std::string nomePersonagem;
        std::cout << "Digite o nome do seu personagem: ";
        std::cin >> nomePersonagem;

        // Criar um novo personagem com o nome e classe escolhidos e exibir informações
        Personagem personagem = criarPersonagem(nomePersonagem, classePersonagem);
        std::cout << "\nPersonagem criado com sucesso!\n";
        atribuirAtributos(personagem); // Atribuir pontos aos atributos do personagem
        personagem.exibir();

        // Criando ataques para o jogador
        Ataques ataquesJogador;
        ataquesJogador.adicionarAtaque("Ataque Rápido");
        ataquesJogador.adicionarAtaque("Corte Profundo");
        ataquesJogador.adicionarAtaque("Magia Elemental");

        // Criar um monstro para combate
        Monstro monstro("Ogro", 100, 20, 10);

        // Iniciar combate
        combate(personagem, monstro, ataquesJogador);
    }

    return 0;
}
