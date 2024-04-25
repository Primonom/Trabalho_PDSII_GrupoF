#include "Campanha.hpp"

void Campanha::exibirOpcoes() {
    std::cout << "Escolha uma campanha:" << std::endl;
    std::cout << "1. Caverna do Dragao" << std::endl;
    std::cout << "2. Monte Ararath" << std::endl;
    std::cout << "3. Eclipse" << std::endl;
    std::cout << "4. Em busca de Atlantida" << std::endl;
    std::cout << "5. Perdidos no Espaco" << std::endl;
}

std::string Campanha::escolherCampanha() {
    int escolha;
    std::string input;

    do {
        exibirOpcoes();
        std::cin >> input;

        try {
            escolha = std::stoi(input);
        } catch (const std::exception& e) {
            std::cerr << "Entrada invalida! Digite um numero." << std::endl;
            continue;
        }

        switch (escolha) {
            case 1:
                return "Caverna do Dragao";
            case 2:
                return "Monte Ararath";
            case 3:
                return "Eclipse";
            case 4:
                return "Em busca de Atlantida";
            case 5:
                return "Perdidos no Espaco";
            default:
                std::cerr << "Opcao invalida!" << std::endl;
        }
    } while (escolha < 1 || escolha > 5);

    return "";
}

