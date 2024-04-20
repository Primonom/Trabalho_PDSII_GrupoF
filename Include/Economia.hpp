#ifndef ECONOMIA_HPP
#define ECONOMIA_HPP

class Economia {
public:
    Economia(); // Construtor
    ~Economia(); // Destrutor

    void ganharOuro(int quantidade);
    void gastarOuro(int quantidade);
    int getOuro() const;

private:
    int ouro;
};

#endif // ECONOMIA_HPP
