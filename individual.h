#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>

class individual
{

public:

    bool *cromossomo;

    int numero_variaveis;
    double acuracia;

    int dominancia;
    double crowding;

public:

    individual(int variaveis);
};

#endif // INDIVIDUAL_H
