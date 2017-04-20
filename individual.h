#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>

class Individual
{

public:

    bool *cromossomo;

    int numero_variaveis;
    double acuracia;

    int dominancia;
    double crowding;

public:

    Individual(int variaveis);
};

#endif // INDIVIDUAL_H
