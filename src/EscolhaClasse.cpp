#include "EscolhaClasse.hpp"
#include <iostream>

std::string escolherClasse() {
    std::string classe;
    bool escolhaValida = false;

    while (!escolhaValida) {
        std::cout << "Escolha a classe do personagem:" << std::endl;
        std::cout << "1. Mago\n2. Bruxo\n3. Necromante\n";
        std::cout << "4. Guerreiro\n5. Assassino\n6. Tanque\n";
        std::cout << "7. Monge\n8. Bardo\n9. Paladino\n";
        int escolha;
        std::cin >> escolha;

        switch (escolha) {
            case 1:
                classe = "Mago";
                escolhaValida = true;
                break;
            case 2:
                classe = "Bruxo";
                escolhaValida = true;
                break;
            case 3:
                classe = "Necromante";
                escolhaValida = true;
                break;
            case 4:
                classe = "Guerreiro";
                escolhaValida = true;
                break;
            case 5:
                classe = "Assassino";
                escolhaValida = true;
                break;
            case 6:
                classe = "Tanque";
                escolhaValida = true;
                break;
            case 7:
                classe = "Monge";
                escolhaValida = true;
                break;
            case 8:
                classe = "Bardo";
                escolhaValida = true;
                break;
            case 9:
                classe = "Paladino";
                escolhaValida = true;
                break;
            default:
                std::cout << "Opção inválida!" << std::endl;
                break;
        }
    }

    return classe;
}
