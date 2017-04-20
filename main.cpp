#include "genetic_algorithm.h"

#include <iostream>
#include <fstream>

#define FILE "teste.csv"

/*-------------------------------------------------------------------*/
/*!

 */
void lerAmostras()
{

    int matriz[7][7];

    std::ifstream arquivo ( FILE );

    while ( arquivo  && !arquivo.eof() )
        for (int i = 0; i < 7; i++)
            for (int j = 0; j < 7; j++)
                arquivo >> matriz[i][j];

    arquivo.close();
}

/*-------------------------------------------------------------------*/
/*!

 */
int main()
{

    lerAmostras();

    GeneticAlgorithm *ga = new GeneticAlgorithm();
    ga->execute();

}

/*-------------------------------------------------------------------*/
/*!

 */
