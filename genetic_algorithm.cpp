#include "genetic_algorithm.h"
#include "algorithm"

/*-------------------------------------------------------------------*/
/*!

 */
bool funcao_sort (individual i, individual j) {
    return ( i.getNumero_variaveis() < j.getNumero_variaveis() );
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

        for (int i = 0; i < total_variaveis - 1; i++ )
            ind->setCromossomo( rand() % 1, i);

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
    {
        avaliarObjetivo(*it);
    }

}

/*-------------------------------------------------------------------*/
/*!

 */
void genetic_algorithm::avaliarObjetivo(individual ind)
{

    int posicao_inicial;
    double soma_acuracia = 0.0;

    for (int i = 0; i < total_variaveis - 1; i++ )
        if( ind.getCromossomo()[i] == 1)
            ind.setNumero_variaveis(ind.getNumero_variaveis() + 1);

    //posicao_inicial = rand() % ( ( ponto_corte / 100 ) * total_amostras ); // verificar se pode ser 0

}

/*-------------------------------------------------------------------*/
/*!

 */
void genetic_algorithm::cruzamentoUniforme(individual pai1, individual pai2)
{
    individual *filho1 = new individual( total_variaveis );
    individual *filho2 = new individual( total_variaveis );

    for ( int i = 1; i < total_variaveis - 1; i++ )
    {
        if ( rand() % 1 == 1 )
        {
            filho1->setCromossomo( pai1.getCromossomo()[ i ], i );
            filho2->setCromossomo( pai2.getCromossomo()[ i ], i );
        }
        else
        {
            filho1->setCromossomo( pai2.getCromossomo()[ i ], i );
            filho2->setCromossomo( pai1.getCromossomo()[ i ], i );
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
        pai1.getCromossomo()[i] + pai2.getCromossomo()[i] +
                aux1.getCromossomo()[i] >= 2 ? filho1->setCromossomo( 1, i )
                                             : filho1->setCromossomo( 0 , i );

        pai1.getCromossomo()[i] + pai2.getCromossomo()[i] +
                aux2.getCromossomo()[i] >= 2 ? filho2->setCromossomo( 1, i )
                                             : filho2->setCromossomo( 0 , i );
    }
}

/*-------------------------------------------------------------------*/
/*!

 */



















//

