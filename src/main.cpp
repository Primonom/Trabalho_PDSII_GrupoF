#include <iostream>
#include <random>
#include <cstdlib> // para std::rand e std::srand
#include <ctime> // para std::time
#include "Campanha.hpp"
#include "EscolhaClasse.hpp"
#include "Personagem.hpp"
#include "Inventario.hpp"
#include "Ataques.hpp"
#include "Economia.hpp"
#include "Sorte.hpp"
#include "Combate.hpp"

/*
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
*/
/*void iniciarCombate(Personagem& personagem, Monstro& monstro) {
    bool combateTerminou = false;
    while (!combateTerminou) {
        std::cout << "\nEscolha um ataque para usar:" << std::endl;
        personagem.mostrarOpcoesAtaque();  // Mostra as opções de ataque
        std::string ataqueEscolhido = personagem.escolherAtaque();
        personagem.usarAtaque(ataqueEscolhido);
        monstro.getAtaque();
         // Criação dos ataques do jogador
    Ataques ataquesJogador;
    // Adicionar ataques ao personagem
    personagem.adicionarAtaque("Bola de Fogo", 5);
    personagem.adicionarAtaque("Raio", 2);

    // Usar um ataque
    ataqueEscolhido = personagem.escolherAtaque();
    personagem.usarAtaque(ataqueEscolhido);
        if (personagem.getSaude() <= 0) {
            std::cout << "Você foi derrotado!" << std::endl;
            combateTerminou = true;
        } else if (monstro.getSaude() <= 0) {
            std::cout << "Você derrotou o monstro!" << std::endl;
            combateTerminou = true;
        }
    }*/

    void iniciarCombate(Personagem& personagem, Monstro& monstro) {
    while (true) {
        // Personagem ataca o monstro
        std::cout << "\nEscolha um ataque para usar:" << std::endl;
        personagem.mostrarOpcoesAtaque();  // Mostra as opções de ataque
        std::string ataqueEscolhido = personagem.escolherAtaque();
        personagem.usarAtaque(ataqueEscolhido);
        int danoPersonagem = personagem.usarAtaque(ataqueEscolhido);  // Supondo que calcularDano() é uma função que retorna o dano
        monstro.receberDano(danoPersonagem);

        // Verifica se o monstro ainda está vivo
        if (monstro.getSaude() <= 0) {
            std::cout << "O monstro foi derrotado!" << std::endl;
            break;
        }

        // Monstro ataca o personagem
        int danoMonstro = monstro.getAtaque();
        personagem.receberDano(danoMonstro);

        // Verifica se o personagem ainda está vivo
        if (personagem.getSaude() <= 0) {
            std::cout << "O personagem foi derrotado!" << std::endl;
            break;
        }
    }
}
/*{
    std::cout << "Você ganhou " << monstro.getXP() << " de experiência." << std::endl;
    personagem.addXP(monstro.getXP());
    std::cout << "Você agora tem " << personagem.getXP() << " de experiência." << std::endl;
}*/



std::string escolherNome() {
    std::string nome;
    std::cout << "Digite o nome do seu personagem: ";
    std::cin.ignore(); // Ignora o '\n' deixado no buffer pelo std::cin anterior
    std::getline(std::cin, nome);
    return nome;
}

int main() {
    std::srand(std::time(0)); // inicializa o gerador de números aleatórios

    // Criação de uma nova campanha
    Campanha campanha;

    // Escolha da campanha
    campanha.escolherCampanha();
    std::string nomeCampanha = campanha.getNome();

    // Escolha da classe do personagem
    std::string classe = escolherClasse();

    // Escolha do nome do personagem
    std::string nomePersonagem = escolherNome();

    // Imprime as escolhas do usuário
    std::cout << "Você escolheu a campanha: " << nomeCampanha << std::endl;
    std::cout << "Você escolheu a classe: " << classe << std::endl;
    std::cout << "Você escolheu o nome: " << nomePersonagem << std::endl;

    // Criar um objeto da classe Inventario
    Inventario inventario;

    // Exemplo de uso da economia
    inventario.ganharOuro(100); // O jogador começa com 100 de ouro
    std::cout << "O jogador tem " << inventario.getOuro() << " de ouro." << std::endl;

    bool continuarComprando = true; // Variável para controlar se o jogador deseja continuar comprando

    while (continuarComprando) {
        std::cout << "\nBem-vindo(a) à loja!" << std::endl;
        std::cout << "Escolha os itens que deseja comprar:" << std::endl;
        std::cout << "1. Espada (10 de ouro)" << std::endl;
        std::cout << "2. Poção de vida (5 de ouro)" << std::endl;
        std::cout << "3. Armadura (15 de ouro)" << std::endl;
        std::cout << "4. Poção de mana (8 de ouro)" << std::endl;
        std::cout << "0. Sair da loja" << std::endl; // Opção para sair da loja

        int escolha;
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                inventario.comprarItem("Espada", 1, 10);
                break;
            case 2:
                inventario.comprarItem("Poção de vida", 1, 5);
                break;
            case 3:
                inventario.comprarItem("Armadura", 1, 15);
                break;
            case 4:
                inventario.comprarItem("Poção de mana", 1, 8);
                break;
            case 0:
                // Opção para sair da loja
                continuarComprando = false;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
                break;
        }

        // Verifica se o jogador escolheu sair da loja
        if (!continuarComprando) {
            std::cout << "Saindo da loja..." << std::endl;
            break; // Sai do loop
        }

        std::cout << "O jogador tem " << inventario.getOuro() << " de ouro." << std::endl;
        std::cout << "\nItens comprados:" << std::endl;
        inventario.mostrarItens();
        system("pause");
        system("cls");
    }
    
    Personagem personagem(nomePersonagem, classe, 100, 10, 20, 5, 30);
    personagem.distribuirPontos(); // Rola o dado e distribui os pontos de atributo

   std::cout << "\nEscolha um ataque para usar:" << std::endl;
    personagem.mostrarOpcoesAtaque();  // Mostra as opções de ataque
    std::string ataqueEscolhido = personagem.escolherAtaque();


      // Obtenção do monstro Esqueleto
    Monstro* Esqueleto = obterMonstro("Esqueleto");
    if (Esqueleto == nullptr) {
        std::cerr << "Erro: Monstro 'Esqueleto' não encontrado." << std::endl;
        return 1; // Retorna um código de erro
    }

    // Criação dos ataques do jogador
    //Ataques ataquesJogador;
    // Adicionar ataques ao personagem
   // personagem.adicionarAtaque("Bola de Fogo", 5);
   // personagem.adicionarAtaque("Raio", 2);

    // Usar um ataque
    //ataqueEscolhido = personagem.escolherAtaque();
    //personagem.usarAtaque(ataqueEscolhido);

    // Combate entre o personagem e o Esqueleto
    //combate(personagem, *Esqueleto, ataquesJogador);
    iniciarCombate(personagem, *Esqueleto);
    return 0;
}
