#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include <string>
#include <vector>
#include "Economia.hpp"

struct Item {
    std::string nome;
    int quantidade;
    int custo; // Custo do item em ouro
};

class Inventario : public Economia {
private:
    static const int ESPACOS = 4; // Número de espaços no inventário
    std::vector<Item> itens;

public:
    Inventario(); // Construtor
    ~Inventario(); // Destrutor
    void adicionarItem(const std::string& nome, int quantidade, int custo);
    void mostrarItens() const;
    void comprarItem(const std::string& nome, int quantidade, int custo);

    // Sobrecarga do operador <<
    friend std::ostream& operator<<(std::ostream& os, const Inventario& inventario);
};

#endif // INVENTARIO_HPP