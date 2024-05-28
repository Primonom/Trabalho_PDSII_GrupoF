#ifndef ATAQUES_HPP
#define ATAQUES_HPP

#include <string>
#include <vector>

class Ataques {
private:
    std::vector<std::string> ataques;

public:
    void adicionarAtaque(const std::string& ataque);
    void mostrarOpcoes() const;
};

#endif
