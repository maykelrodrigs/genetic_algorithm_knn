#include "individual.h"
#include "cstdlib"

/*-------------------------------------------------------------------*/
/*!

 */
bool *individual::getCromossomo() const
{
    return cromossomo;
}

void individual::setCromossomo(bool value, int index)
{
    cromossomo[index] = value;
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

individual::individual(int variaveis)
{

    cromossomo  = new bool[variaveis];
    acuracia    = 0;
    dominancia  = 0;
    crowding    = 0;
    numero_variaveis = 0;

}

