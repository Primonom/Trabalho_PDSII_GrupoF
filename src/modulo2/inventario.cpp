#include "Inventario.hpp"
#include <iostream>

Inventario::Inventario() {
    itens.reserve(ESPACOS); // Reserva espaço para os itens no vetor
}

Inventario::~Inventario() {
    std::cout << "O objeto Inventario foi destruído." << std::endl;
}

void Inventario::adicionarItem(const std::string& nome, int quantidade, int custo) {
    // Verifica se o inventário já está cheio
    if (itens.size() >= ESPACOS) {
        std::cout << "O inventario esta cheio." << std::endl;
        return;
    }

    // Adiciona o item ao inventário
    itens.push_back({nome, quantidade, custo});
}

void Inventario::mostrarItens() const {
    if (itens.empty()) {
        std::cout << "O inventario esta vazio." << std::endl;
        return;
    }

    std::cout << "Itens no inventario:" << std::endl;
    for (const auto& item : itens) {
        std::cout << item.nome << " (Quantidade: " << item.quantidade << ", Custo: " << item.custo << " de ouro)" << std::endl;
    }
}

void Inventario::comprarItem(const std::string& nome, int quantidade, int custo) {
    // Verifica se o inventário já está cheio
    if (itens.size() >= ESPACOS) {
        std::cout << "O inventario esta cheio." << std::endl;
        return;
    }

    // Verifica se o jogador tem ouro suficiente para comprar o item
    if (getOuro() < custo) {
        std::cout << "Voce nao tem ouro suficiente para comprar este item." << std::endl;
        return;
    }

    // Adiciona o item ao inventário e deduz o ouro do jogador
    itens.push_back({nome, quantidade, custo});
    gastarOuro(custo);
    std::cout << "Item '" << nome << "' comprado com sucesso!" << std::endl;
}

// Implementação da sobrecarga do operador <<
std::ostream& operator<<(std::ostream& os, const Inventario& inventario) {
    os << "Inventario: " << std::endl;
    for (const auto& item : inventario.itens) {
        os << item.nome << " (Quantidade: " << item.quantidade << ", Custo: " << item.custo << " de ouro)" << std::endl;
    }
    return os;
}