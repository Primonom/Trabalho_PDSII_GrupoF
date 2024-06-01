#ifndef ECONOMIA_HPP
#define ECONOMIA_HPP

#include <iostream>

class Economia {
public:
    Economia(); // Construtor
    ~Economia(); // Destrutor

    void ganharOuro(int quantidade);
    bool gastarOuro(int quantidade); // Retorna true se a operação foi bem-sucedida, false caso contrário
    int getOuro() const;

    // Sobrecarga do operador <<
    friend std::ostream& operator<<(std::ostream& os, const Economia& economia);

private:
    int ouro;
};

#endif // ECONOMIA_HPP