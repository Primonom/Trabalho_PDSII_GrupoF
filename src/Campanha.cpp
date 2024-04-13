#include "Campanha.hpp"

void Campanha::exibirOpcoes() {
    std::cout << "Escolha uma campanha:" << std::endl;
    for (int i = 0; i < opcoes.size(); ++i) {
        std::cout << i + 1 << ". " << opcoes[i] << std::endl;
    }
}

std::string Campanha::escolherCampanha() {
    int escolha;
    exibirOpcoes();
    std::cin >> escolha;

    if (escolha < 1 || escolha > opcoes.size()) {
        std::cerr << "Opcao invalida!" << std::endl;
        return "";
    }

    return opcoes[escolha - 1];
}
