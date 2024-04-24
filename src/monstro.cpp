// Monstro.cpp

#include "Monstro.hpp"

// Declaração das variáveis estáticas
static Monstro monstro1("Ogro", 100, 20, 10);
static Monstro monstro2("Esqueleto", 80, 15, 5);

// Função para obter um ponteiro para um monstro específico
Monstro* obterMonstro(std::string nome) {
    if (nome == "Ogro") {
        return &monstro1;
    } else if (nome == "Esqueleto") {
        return &monstro2;
    } else {
        return nullptr; // Retorna nullptr se o monstro não for encontrado
    }
}

// Construtor
Monstro::Monstro(std::string nome, int saude, int forca, int defesa)
    : nome(nome), saude(saude), forca(forca), defesa(defesa) {}

// Métodos para obter informações do monstro
std::string Monstro::getNome() const {
    return nome;
}

int Monstro::getSaude() const {
    return saude;
}

int Monstro::getForca() const {
    return forca;
}

int Monstro::getDefesa() const {
    return defesa;
}

// Método para atualizar a saúde do monstro quando recebe dano
void Monstro::receberDano(int dano) {
    // Reduz a saúde do monstro de acordo com o dano recebido
    saude -= dano;

    // Garante que a saúde não seja negativa
    if (saude < 0) {
        saude = 0;
    }
}
