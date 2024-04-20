#include <iostream>
#include "Campanha.hpp"
#include "EscolhaClasse.hpp"
#include "Personagem.hpp"
#include "Inventario.hpp"
#include "ataques.hpp"
#include "economia.hpp"
int main() {
   // Solicitar ao usuário que escolha a campanha
    Campanha campanha;
    std::string nomeCampanha = campanha.escolherCampanha();
     std::string classePersonagem = escolherClasse();

    if (!nomeCampanha.empty()) {
        std::cout << "Campanha selecionada: " << nomeCampanha << std::endl;

        // Solicitar ao usuário que entre com o nome do personagem
        std::string nomePersonagem;
        std::cout << "Digite o nome do seu personagem: ";
        std::cin >> nomePersonagem;

        // Solicitar ao usuário que escolha a classe do personagem
        std::string classePersonagem = escolherClasse();

        // Criar um novo personagem com o nome e classe escolhidos e exibir informações
        Personagem personagem = criarPersonagem(nomePersonagem, classePersonagem);
        std::cout << "\nPersonagem criado com sucesso!\n";
        personagem.exibir();
    }
    system ("pause");
    system ("cls");

    // Criar um objeto da classe Economia
    Economia economia;

    // Exemplo de uso da economia
    economia.ganharOuro(100); // O jogador começa com 100 de ouro
    std::cout << "O jogador tem " << economia.getOuro() << " de ouro." << std::endl;

   bool continuarComprando = true; // Variável para controlar se o jogador deseja continuar comprando

while (continuarComprando) {
    // Cria um inventário para o jogador
    Inventario inventario(economia);

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
            inventario.adicionarItem("Espada", 1, 10);
            break;
        case 2:
            inventario.adicionarItem("Poção de vida", 1, 5);
            break;
        case 3:
            inventario.adicionarItem("Armadura", 1, 15);
            break;
        case 4:
            inventario.adicionarItem("Poção de mana", 1, 8);
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

    std::cout << "\nItens comprados:" << std::endl;
    inventario.mostrarItens();
    system ("pause");
    system ("cls");
}

int x;
for(x=0; x<=4; x++){
    
    Ataques ataque;
        std::cout << "\nEscolha um ataque para usar:" << std::endl;
        if (classePersonagem == "Mago") {
            ataque.adicionarAtaque("Bola de fogo");
            ataque.adicionarAtaque("Raio");
        } else if (classePersonagem == "Guerreiro") {
            ataque.adicionarAtaque("Corte horizontal");
            ataque.adicionarAtaque("Investida");
        } else if (classePersonagem == "Assassino") {
            ataque.adicionarAtaque("Ataque sorrateiro");
            ataque.adicionarAtaque("Arremesso de adaga");
        } else if (classePersonagem == "Monge") {
            ataque.adicionarAtaque("Chute giratório");
            ataque.adicionarAtaque("Soco rápido");
        }

        ataque.mostrarOpcoes();
}

return 0;
}