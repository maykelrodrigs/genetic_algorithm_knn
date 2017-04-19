#include "genetic_algorithm.h"
#include "algorithm"

/*-------------------------------------------------------------------*/
/*!

 */
bool funcao_sort (individual i, individual j) {
    return ( i.numero_variaveis < j.numero_variaveis );
}

/*-------------------------------------------------------------------*/
/*!

 */
genetic_algorithm::genetic_algorithm()
{

    iniciarPopulacao();

    for (int i = 0; i < numero_geracoes; i++ )
    {

        avaliarPopulacao();
        std::sort(populacao.begin(), populacao.end(), funcao_sort);

    }

}

/*-------------------------------------------------------------------*/
/*!

 */
void genetic_algorithm::iniciarPopulacao()
{

    for (int i = 0; i < tamanho_populacao; i++ )
    {

        individual *ind = new individual( total_variaveis );

        for (int i = 0; i < total_variaveis; i++ )
            ind->cromossomo[i] =  rand() % 1;

        populacao.push_back(*ind);

    }

}

/*-------------------------------------------------------------------*/
/*!

 */
void genetic_algorithm::avaliarPopulacao()
{

    for (std::vector<individual>::iterator it = populacao.begin() ;
         it != populacao.end();
         ++it)

        avaliarObjetivo(*it);

}

/*-------------------------------------------------------------------*/
/*!

 */
void genetic_algorithm::avaliarObjetivo(individual ind)
{

    int posicao_inicial;
    double soma_acuracia = 0.0;

    // soma as variáveis do cromossomo
    for (int i = 0; i < total_variaveis; i++ )
        if( ind.cromossomo[i] == 1)
            ind.cromossomo[i]++;

    //posicao_inicial = rand() % ( ( ponto_corte / 100 ) * total_amostras ); // verificar se pode ser 0

}

/*-------------------------------------------------------------------*/
/*!

 */
void genetic_algorithm::cruzamentoUniforme(individual pai1, individual pai2)
{
    individual *filho1 = new individual( total_variaveis );
    individual *filho2 = new individual( total_variaveis );

    for ( int i = 1; i < total_variaveis; i++ )
    {
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
    }
}

/*-------------------------------------------------------------------*/
/*!

 */
void genetic_algorithm::cruzamentoMaioria(individual pai1, individual pai2)
{
    individual *filho1 = new individual( total_variaveis );
    individual *filho2 = new individual( total_variaveis );

    individual aux1 = populacao[ rand() % tamanho_populacao ];
    individual aux2 = populacao[ rand() % tamanho_populacao ];

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
}

/*-------------------------------------------------------------------*/
/*!

 */
void genetic_algorithm::mutacaoGuiada(individual ind)
{
    for (int i = 0; i < total_variaveis; i++ )
        if ( ( rand() % 100 + 1 ) / 100 <= tx_mutacao )
            ind.cromossomo[ i ] = rand() % 1;
}

/*-------------------------------------------------------------------*/
/*!

 */
void genetic_algorithm::mutacaoMaiorPeso(individual ind)
{
    for (int i = 0; i < total_variaveis; i++ )
        if ( ( rand() % 100 + 1 ) / 100 <= tx_mutacao )
            rand() % 100 + 1 <= 70
                    ? ind.cromossomo[ i ] = 0
                    : ind.cromossomo[ i ] = 1;
}

/*-------------------------------------------------------------------*/
/*!

 */



















//

