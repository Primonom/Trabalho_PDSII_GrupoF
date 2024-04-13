#include "Personagem.hpp"
#include <iostream>

void Personagem::exibir() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Classe: " << classe << std::endl;
}
