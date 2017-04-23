#include "genetic_algorithm.h"
#include "algorithm"

#include <iostream>


/*-------------------------------------------------------------------*/
/*!

 */
bool funcao_sort (Individual i, Individual j) {
    return ( i.nr_variaveis < j.nr_variaveis );
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

    for ( int i = 0; i < dados->geracao; i++ )
    {

        for ( int j = 0; j < dados->populacao / 2; j++ )
            cruzamentoUniforme( torneio() , torneio() );

        avaliarPopulacao();
        std::sort(populacao.begin(), populacao.end(), funcao_sort);

        removerIndividuos( dados->populacao );

    }

    //std::cout<<"Finalizado";
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

        avaliarObjetivo( *it );

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

    int qtd = 0;

    // soma as variáveis do cromossomo
    for ( int i = 0; i < dados->nr_variaveis; i++ )
        if( ind.cromossomo[ i ] == 1 )
            qtd++;

    ind.nr_variaveis = qtd;

}

/*-------------------------------------------------------------------*/
/*!

 */
void GeneticAlgorithm::cruzamentoUniforme(Individual pai1, Individual pai2)
{

    Individual *filho1 = new Individual();
    Individual *filho2 = new Individual();

    for ( int i = 0; i < dados->nr_variaveis; i++ )

        if ( rand() % 2 == 1 )
        {
            filho1->cromossomo.emplace_back( pai1.cromossomo[i] );
            filho2->cromossomo.emplace_back( pai2.cromossomo[i] );
        }
        else
        {
            filho1->cromossomo.emplace_back( pai2.cromossomo[i] );
            filho2->cromossomo.emplace_back( pai1.cromossomo[i] );
        }

    populacao.push_back( *filho1 );
    populacao.push_back( *filho2 );
}

///*-------------------------------------------------------------------*/
///*!

// */
//void GeneticAlgorithm::mutacaoGuiada(Individual &ind)
//{
//    for ( int i = 0; i < nr_variaveis; i++ )
//        if ( ( rand() % 100 + 1 ) / 100 <= tx_mutacao )
//            ind.cromossomo[ i ] = rand() % 1; // corrigir o método
//}

///*-------------------------------------------------------------------*/
///*!

// */
//void GeneticAlgorithm::mutacaoMaiorPeso(Individual &ind)
//{
//    for ( int i = 0; i < nr_variaveis; i++ )
//        if ( ( rand() % 100 + 1 ) / 100 <= tx_mutacao )
//            rand() % 100 + 1 <= 70
//                    ? ind.cromossomo[ i ] = 0
//                    : ind.cromossomo[ i ] = 1;
//}

///*-------------------------------------------------------------------*/
///*!

// */
//void GeneticAlgorithm::avaliarDominancia(Individual &ind)
//{
//    int dom = 0;

//    for ( std::vector<Individual>::iterator it = populacao.begin() ;
//         it != populacao.end();
//         ++it)
//    {

//            if ( ind.nr_variaveis > (*it).nr_variaveis )
//                dom++;

//            if ( (ind.acuracia * 100 ) / 100 < ( (*it).acuracia * 100 ) / 100 )
//                dom++;
//    }


//    ind.dominancia = dom;
//}

///*-------------------------------------------------------------------*/
///*!

// */
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

