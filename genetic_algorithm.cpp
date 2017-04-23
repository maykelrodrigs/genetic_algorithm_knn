#include "genetic_algorithm.h"
#include "algorithm"

#include <iostream>
#include <math.h>
#include <limits>

/*-------------------------------------------------------------------*/
/*!

 */
bool funcao_sort (Individual i, Individual j) {
    return ( i.dominancia > j.dominancia );
}

/*-------------------------------------------------------------------*/
/*!

 */
GeneticAlgorithm::GeneticAlgorithm()
{

    this->dados = new Sample();
    dados->lerAmostras( "dados.csv" );

}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::execute()
{

    iniciarPopulacao();
    avaliarPopulacao();

    for ( int i = 0; i < dados->geracao; i++ )
    {

        for ( int j = 0; j < dados->populacao; j++ )
            cruzamento( torneio() , torneio() );

        avaliarPopulacao();
        std::sort(populacao.begin(), populacao.end(), funcao_sort);

        removerIndividuos( dados->populacao );
        std::cout<<"Geração: " << i << std::endl;

    }
    std::cout<<"Finalizado!";


}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::iniciarPopulacao()
{

    for ( int i = 0; i < dados->populacao; i++ )
    {
        Individual *ind = new Individual();

        for ( int i = 0; i < dados->nr_variaveis; i++ )
            ind->cromossomo.push_back( rand() % 2 );

        populacao.push_back( *ind );
    }

}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::avaliarPopulacao()
{

    for ( std::vector<Individual>::iterator it = populacao.begin() ;
          it != populacao.end();
          ++it)
    {

        avaliarObjetivo( *it );
        avaliarDominancia( *it );

    }


}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::removerIndividuos(int qtd)
{

    for ( int i = 0; i < qtd; i++ )
        populacao.pop_back();


}

/*-------------------------------------------------------------------*/
/*!

*/
void GeneticAlgorithm::avaliarObjetivo(Individual &ind)
{

    int qtd = 0, acertos = 0, contador = 0, melhor;
    double dist_eucle;
    double max;

    // soma as variáveis do cromossomo
    for ( int i = 0; i < dados->nr_variaveis; i++ )
        if( ind.cromossomo[ i ] == 1 )
            qtd++;

    for ( int i = 0 ; i < dados->nr_amostras ; i++ )
    {
        max = std::numeric_limits<double>::max();

        for( int j = 0; j < dados->nr_amostras; j++ )
        {
            if ( i != j )
            {

                dist_eucle = 0;

                for ( int k = 0; k < dados->nr_variaveis; k++ )
                {

                    if ( ind.cromossomo[ k ] == true )
                        dist_eucle +=
                                abs( dados->variaveis[ i ][  k ]
                                      - dados->variaveis[ j ][ k ] );

                }

                if ( dist_eucle < max )
                {
                    melhor = j;
                    max = dist_eucle;
                }
            }
        }

        if ( dados->tipo[i] == dados->tipo[melhor] )
            acertos++;

        contador++;

    }

    ind.acuracia = (double)contador / (double)acertos;
    ind.nr_variaveis = qtd;

}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::cruzamento(Individual pai1, Individual pai2)
{

    Individual *filho = new Individual();

    for ( int i = 0; i < dados->nr_variaveis; i++ )

        rand() % 2 == 1
                ? filho->cromossomo.emplace_back( pai1.cromossomo[i] )
                : filho->cromossomo.emplace_back( pai2.cromossomo[i] );

    mutacaoMaiorPeso( *filho );

    populacao.push_back( *filho );

}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::mutacaoGuiada(Individual &ind)
{
    for ( int i = 0; i < dados->nr_variaveis; i++ )
        if ( ( rand() % 100 + 1 ) / 100 <= dados->tx_mutacao )
            ind.cromossomo[ i ] = rand() % 1; // corrigir o método
}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::mutacaoMaiorPeso(Individual &ind)
{
    for ( int i = 0; i < dados->nr_variaveis; i++ )
        if ( ( rand() % 100 + 1 ) / 100 <= dados->tx_mutacao )
            rand() % 100 + 1 <= 70
                    ? ind.cromossomo[ i ] = false
                    : ind.cromossomo[ i ] = true;
}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::avaliarDominancia(Individual &ind)
{
    int dom = 0;

    for ( std::vector<Individual>::iterator it = populacao.begin() ;
         it != populacao.end();
         ++it)
    {

            if ( ind.nr_variaveis < (*it).nr_variaveis ) // verificar com o Igor
                dom++;

            if ( (ind.acuracia * 100 ) / 100 < ( (*it).acuracia * 100 ) / 100 )
                dom++;
    }


    ind.dominancia = dom;
}

/*-------------------------------------------------------------------*/
/*!

 */
Individual GeneticAlgorithm::torneio()
{

    Individual ind1 = populacao[ rand() % populacao.size() ];
    Individual ind2 = populacao[ rand() % populacao.size() ];

    if ( ind1.dominancia > ind2.dominancia )
        return ind1;

    if ( ind1.dominancia == ind2.dominancia )
        if ( ind1.crowding >= ind2.crowding )
            return ind1;

    return ind2;

}

/*-------------------------------------------------------------------*/
/*!

 */


