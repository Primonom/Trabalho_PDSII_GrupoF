#include "personagem.hpp"

Personagem::Personagem(std::string nome, std::string classe, int saude, int defesa)
    : nome(nome), classe(classe), saude(saude), defesa(defesa), magia(0), ataque(0), agilidade(0) {}

Personagem::~Personagem() {
    // Código de limpeza, se necessário
}

void Personagem::exibir() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Classe: " << classe << std::endl;
    std::cout << "Saúde: " << saude << std::endl;
    std::cout << "Defesa: " << defesa << std::endl;
    std::cout << "Magia: " << magia << std::endl;
    std::cout << "Ataque: " << ataque << std::endl;
    std::cout << "Agilidade: " << agilidade << std::endl;
}

void Personagem::distribuirPontos(int pontos) {
    while (pontos > 0) {
        std::cout << "Distribuindo " << pontos << " pontos para os atributos." << std::endl;
        std::cout << "Digite quantos pontos deseja atribuir a cada atributo:" << std::endl;

        int valor;
        
        std::cout << "Saude: ";
        std::cin >> valor;
        valor = std::min(valor, pontos);
        saude += valor;
        pontos -= valor;

        std::cout << "Defesa: ";
        std::cin >> valor;
        valor = std::min(valor, pontos);
        defesa += valor;
        pontos -= valor;

        std::cout << "Magia: ";
        std::cin >> valor;
        valor = std::min(valor, pontos);
        magia += valor;
        pontos -= valor;

        std::cout << "Ataque: ";
        std::cin >> valor;
        valor = std::min(valor, pontos);
        ataque += valor;
        pontos -= valor;

        std::cout << "Agilidade: ";
        std::cin >> valor;
        valor = std::min(valor, pontos);
        agilidade += valor;
        pontos -= valor;

        std::cout << "Pontos restantes: " << pontos << std::endl;
    }
}

void Personagem::addXP(int amount) {
    xp += amount;

    while (xp >= xpToLevelUp) {
        xp -= xpToLevelUp;
        level++;
        xpToLevelUp *= 2;
    }
}

int Personagem::getLevel() const {
    return level;
}

int Personagem::getXP() const {
    return xp;
}

std::ostream& operator<<(std::ostream& os, const Personagem& personagem) {
    os << "Nome: " << personagem.nome << "\nClasse: " << personagem.classe << "\nSaúde: " << personagem.saude
       << "\nDefesa: " << personagem.defesa << "\nMagia: " << personagem.magia << "\nAtaque: " << personagem.ataque
       << "\nAgilidade: " << personagem.agilidade << "\nXP: " << personagem.xp << "\nNível: " << personagem.level;
    return os;
}

Personagem criarPersonagem(std::string nome, std::string classe) {
    Personagem novoPersonagem(nome, classe, 100, 50); // Valores iniciais de saúde e defesa
    return novoPersonagem;
}