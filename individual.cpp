#include "individual.h"
#include "cstdlib"

/*-------------------------------------------------------------------*/
/*!

 */
bool *individual::getCromossomo() const
{
    return cromossomo;
}

void individual::setCromossomo(bool *value)
{
    cromossomo = value;
}

int individual::getNumero_variaveis() const
{
    return numero_variaveis;
}

void individual::setNumero_variaveis(int value)
{
    numero_variaveis = value;
}

/*-------------------------------------------------------------------*/
/*!

 */
individual::individual(int variavel)
{

    cromossomo = new bool[variavel];

    acuracia    = 0;
    dominancia  = 0;
    crowding    = 0;
    numero_variaveis = 0;

    for (int i = 0; i < variavel; i++ )
        cromossomo[i] = rand() % 1;

}

