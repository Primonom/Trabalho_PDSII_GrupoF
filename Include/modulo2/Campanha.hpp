#ifndef CAMPANHA_HPP
#define CAMPANHA_HPP

#include <iostream>
#include <string>

class Campanha {
private:
    std::string nome;

public:
    Campanha(); // Construtor
    ~Campanha(); // Destrutor
    void exibirOpcoes();
    std::string escolherCampanha();

    // Getters e Setters
    std::string getNome() const;
    void setNome(const std::string& nome);

    // Sobrecarga do operador <<
    friend std::ostream& operator<<(std::ostream& os, const Campanha& campanha);
};

#endif