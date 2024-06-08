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


std::string escolherNome() {
    std::string nome;
    std::cout << "Digite o nome do seu personagem: ";
    std::cin.ignore(); // Ignora o '\n' deixado no buffer pelo std::cin anterior
    std::getline(std::cin, nome);
    return nome;
}

int main() {
    system("pause");
    system("cls");
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
    system("pause");
    system("cls");
    std::cout << "Voce escolheu a campanha: " << nomeCampanha << std::endl;
    std::cout << "Voce escolheu a classe: " << classe << std::endl;
    std::cout << "Voce escolheu o nome: " << nomePersonagem << std::endl;

    // Criar um objeto da classe Inventario
    Inventario inventario;

    // Exemplo de uso da economia
    inventario.ganharOuro(100); // O jogador começa com 100 de ouro
    std::cout << "O jogador tem " << inventario.getOuro() << " de ouro." << std::endl;

    bool continuarComprando = true; // Variável para controlar se o jogador deseja continuar comprando

    while (continuarComprando) {
        std::cout << "\nBem-vindo(a) a loja!" << std::endl;
        std::cout << "Escolha os itens que deseja comprar:" << std::endl;
        std::cout << "1. Espada (10 de ouro)" << std::endl;
        std::cout << "2. Pocao de vida (5 de ouro)" << std::endl;
        std::cout << "3. Armadura (15 de ouro)" << std::endl;
        std::cout << "4. Pocao de mana (8 de ouro)" << std::endl;
        std::cout << "0. Sair da loja" << std::endl; // Opção para sair da loja

        int escolha;
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                inventario.comprarItem("Espada", 1, 10);
                break;
            case 2:
                inventario.comprarItem("Pocao de vida", 1, 5);
                break;
            case 3:
                inventario.comprarItem("Armadura", 1, 15);
                break;
            case 4:
                inventario.comprarItem("Pocao de mana", 1, 8);
                break;
            case 0:
                // Opção para sair da loja
                continuarComprando = false;
                break;
            default:
                std::cout << "Opcao invalida!" << std::endl;
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
    iniciarCombate(personagem, *Esqueleto);
    return 0;
}
