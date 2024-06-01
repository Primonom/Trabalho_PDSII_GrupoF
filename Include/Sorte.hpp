#ifndef SORTE_HPP
#define SORTE_HPP

#include <iostream>
#include <utility>

class Sorte {
private:
    int resultado;
    double porcentagem;

public:
    Sorte(); // Construtor
    ~Sorte(); // Destrutor
    void lancarDado();

    // Getters
    int getResultado() const;
    double getPorcentagem() const;

    // Sobrecarga do operador <<
    friend std::ostream& operator<<(std::ostream& os, const Sorte& sorte);
};

#endif