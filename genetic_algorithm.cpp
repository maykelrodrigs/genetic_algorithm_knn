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

        individual *ind = new individual(100);
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

    for (int i = 0; i < total_variaveis; i++ )
        if( ind.getCromossomo()[i] == 1)
            ind.setNumero_variaveis(ind.getNumero_variaveis() + 1);

    //posicao_inicial = rand() % ( ( ponto_corte / 100 ) * total_amostras ); // verificar se pode ser 0

}
