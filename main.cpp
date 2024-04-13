#include "Personagem.hpp"
#include "EscolhaClasse.hpp"
#include <iostream>

int main() {
    std::string nome;

    std::cout << "Digite o nome do personagem: ";
    std::cin >> nome;

    std::string classe = escolherClasse();

    Personagem meuPersonagem = criarPersonagem(nome, classe);
    std::cout << "\nPersonagem criado com sucesso!\n";
    meuPersonagem.exibir();

    return 0;
}
