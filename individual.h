#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>

class Individual
{

public:

    std::vector<bool> cromossomo;

    int nr_variaveis;
    double acuracia;

    int dominancia;
    double crowding;

public:

    Individual();
};

#endif // INDIVIDUAL_H
