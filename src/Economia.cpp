#include "economia.hpp"

Economia::Economia() {
    ouro = 0; // Inicializa o ouro do jogador como 0 ao iniciar o jogo
}

Economia::~Economia() {
    // Implementação do destrutor, se necessário
}

void Economia::ganharOuro(int quantidade) {
    ouro += quantidade; // Adiciona a quantidade de ouro ganha ao total
}

void Economia::gastarOuro(int quantidade) {
    if (ouro >= quantidade) {
        ouro -= quantidade; // Subtrai a quantidade de ouro gasta do total, se houver ouro suficiente
    } else {
        // Aqui você pode lidar com a situação de o jogador não ter ouro suficiente para gastar
        // Por exemplo, exibir uma mensagem de erro ou retornar um código de erro
    }
}

int Economia::getOuro() const {
    return ouro; // Retorna a quantidade atual de ouro do jogador
}
