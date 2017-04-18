#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>

class individual
{
    bool *cromossomo;

    int numero_variaveis;
    double acuracia;

    int dominancia;
    double crowding;

public:

    individual(int variavel);

    bool *getCromossomo() const;
    int getNumero_variaveis() const;

    void setCromossomo(bool *value);
    void setNumero_variaveis(int value);
};

#endif // INDIVIDUAL_H
