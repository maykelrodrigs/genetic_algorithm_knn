#include "individual.h"
#include "cstdlib"

/*-------------------------------------------------------------------*/
/*!

 */

Individual::Individual(int variaveis)
{

    cromossomo  = new bool[variaveis];
    acuracia    = 0;
    dominancia  = 0;
    crowding    = 0;
    numero_variaveis = 0;

}

