#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include <string>
#include <vector>
#include "economia.hpp"

struct Item {
    std::string nome;
    int quantidade;
    int custo; // Custo do item em ouro
};

class Inventario {
private:
    static const int ESPACOS = 4; // Número de espaços no inventário
    std::vector<Item> itens;
    Economia* economia; // Referência para o objeto de economia

public:
    Inventario(Economia& eco); // Construtor que recebe uma referência para o objeto de economia
    void adicionarItem(const std::string& nome, int quantidade, int custo);
    void mostrarItens() const;
    void comprarItem(const std::string& nome, int quantidade, int custo);
};

#endif // INVENTARIO_HPP
