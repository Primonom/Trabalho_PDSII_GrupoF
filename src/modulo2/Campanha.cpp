#include "Campanha.hpp"

Campanha::Campanha() {
    nome = "";
}

Campanha::~Campanha() {
    std::cout << "O objeto Campanha foi destruído." << std::endl;
}

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
                nome = "Caverna do Dragao";
                break;
            case 2:
                nome = "Monte Ararath";
                break;
            case 3:
                nome = "Eclipse";
                break;
            case 4:
                nome = "Em busca de Atlantida";
                break;
            case 5:
                nome = "Perdidos no Espaco";
                break;
            default:
                std::cerr << "Opcao invalida!" << std::endl;
        }
    } while (escolha < 1 || escolha > 5);
}

std::string Campanha::getNome() const {
    return nome;
}

void Campanha::setNome(const std::string& nome) {
    this->nome = nome;
}

std::ostream& operator<<(std::ostream& os, const Campanha& campanha) {
    os << "Campanha: " << campanha.getNome();
    return os;
}