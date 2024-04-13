#ifndef CAMPANHA_HPP
#define CAMPANHA_HPP

#include <iostream>
#include <string>
#include <vector>

class Campanha {
private:
    std::vector<std::string> opcoes = {
        "Caverna do Dragao",
        "Monte Ararath",
        "Eclipse",
        "Em busca de Atlantida",
        "Perdidos no Espaco"
    };

public:
    void exibirOpcoes();
    std::string escolherCampanha();
};

#endif
