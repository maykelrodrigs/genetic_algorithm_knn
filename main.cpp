#include "genetic_algorithm.h"
#include <iostream>
#include <time.h>

/*-------------------------------------------------------------------*/
/*!

 */
int main()
{

    srand (time(NULL));


    GeneticAlgorithm *ga = new GeneticAlgorithm();
    ga->execute();

}

/*-------------------------------------------------------------------*/
/*!

 */
