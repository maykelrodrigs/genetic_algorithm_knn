#include "genetic_algorithm.h"
#include "algorithm"

#include <time.h>

/*-------------------------------------------------------------------*/
/*!

 */
bool funcao_sort (Individual i, Individual j) {
    return ( i.numero_variaveis < j.numero_variaveis );
}

/*-------------------------------------------------------------------*/
/*!

 */
GeneticAlgorithm::GeneticAlgorithm()
{

}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::execute()
{
    srand (time(NULL));

    iniciarPopulacao();

    for ( int i = 0; i < numero_geracoes; i++ )
    {

        cruzamentoUniforme( torneio() , torneio() );

        avaliarPopulacao();
        std::sort(populacao.begin(), populacao.end(), funcao_sort);

    }

}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::iniciarPopulacao()
{

    for ( int i = 0; i < tamanho_populacao; i++ )
    {

        Individual *ind = new Individual( total_variaveis );

        for ( int i = 0; i < total_variaveis; i++ )
            ind->cromossomo[i] =  rand() % 1;

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

        avaliarObjetivo( *it );

}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::avaliarObjetivo(Individual &ind)
{

    //int posicao_inicial;
    //double soma_acuracia = 0.0;

    // soma as variáveis do cromossomo
    for ( int i = 0; i < total_variaveis; i++ )
        if( ind.cromossomo[ i ] == 1 )
            ind.numero_variaveis++;

    //posicao_inicial = rand() % ( ( ponto_corte / 100 ) * total_amostras ); // verificar se pode ser 0

}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::cruzamentoUniforme(Individual pai1, Individual pai2)
{
    Individual *filho1 = new Individual( total_variaveis );
    Individual *filho2 = new Individual( total_variaveis );

    for ( int i = 1; i < total_variaveis; i++ )

        if ( rand() % 1 == 1 )
        {
            filho1->cromossomo[i] =  pai1.cromossomo[i];
            filho2->cromossomo[i] =  pai2.cromossomo[i];
        }
        else
        {
            filho1->cromossomo[i] = pai2.cromossomo[i];
            filho2->cromossomo[i] = pai1.cromossomo[i];
        }

    populacao.push_back( *filho1 );
    populacao.push_back( *filho2 );
}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::cruzamentoMaioria(Individual pai1, Individual pai2)
{
    Individual *filho1 = new Individual( total_variaveis );
    Individual *filho2 = new Individual( total_variaveis );

    Individual aux1 = populacao[ rand() % populacao.size() ];
    Individual aux2 = populacao[ rand() % populacao.size() ];

    for ( int i = 0; i < total_variaveis - 1; i++ )
    {
        pai1.cromossomo[i] + pai2.cromossomo[i] +
                aux1.cromossomo[i] >= 2
                ? filho1->cromossomo[i] = 1
                : filho1->cromossomo[i] = 0;

        pai1.cromossomo[i] + pai2.cromossomo[i] +
                aux2.cromossomo[i] >= 2
                ? filho2->cromossomo[i] = 1
                : filho2->cromossomo[i] = 0;
    }

    populacao.push_back( *filho1 );
    populacao.push_back( *filho2 );
}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::mutacaoGuiada(Individual &ind)
{
    for ( int i = 0; i < total_variaveis; i++ )
        if ( ( rand() % 100 + 1 ) / 100 <= tx_mutacao )
            ind.cromossomo[ i ] = rand() % 1; // corrigir o método
}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::mutacaoMaiorPeso(Individual &ind)
{
    for ( int i = 0; i < total_variaveis; i++ )
        if ( ( rand() % 100 + 1 ) / 100 <= tx_mutacao )
            rand() % 100 + 1 <= 70
                    ? ind.cromossomo[ i ] = 0
                    : ind.cromossomo[ i ] = 1;
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

            if ( ind.numero_variaveis > (*it).numero_variaveis )
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



















//

