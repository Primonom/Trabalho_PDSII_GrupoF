#ifndef ATAQUES_HPP
#define ATAQUES_HPP

#include <string>
#include <map>
#include <iostream>

class Ataques {
private:
    std::map<std::string, int> ataques;

public:
    void adicionarAtaque(const std::string& ataque, int dano);
    void mostrarOpcoes() const;
    int usarAtaque(const std::string& ataque);

    std::string escolherAtaque() const {
        std::cout << "Escolha um ataque:" << std::endl;
        int i = 1;
        for (const auto& ataque : ataques) {
            std::cout << i << ". " << ataque.first << std::endl;
            i++;
        }

        int escolha;
        std::cin >> escolha;

        // Verificar se a escolha é válida
        if (escolha < 1 || escolha > ataques.size()) {
            std::cout << "Escolha inválida. Tente novamente." << std::endl;
            return escolherAtaque();
        }

        // Retornar o ataque escolhido
        auto it = ataques.begin();
        std::advance(it, escolha - 1);
        return it->first;
    }
};

#endif