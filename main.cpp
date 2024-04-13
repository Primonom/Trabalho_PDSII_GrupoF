#include <iostream>
#include "Campanha.hpp"
#include "EscolhaClasse.hpp"
#include "Personagem.hpp"

int main() {
    // Solicitar ao usuário que escolha a campanha
    Campanha campanha;
    std::string nomeCampanha = campanha.escolherCampanha();

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

    return 0;
}

