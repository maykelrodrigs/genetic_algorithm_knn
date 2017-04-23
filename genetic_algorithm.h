#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <vector>
#include <individual.h>
#include <sample.h>

class GeneticAlgorithm
{
private:

    std::vector <Individual> populacao;

    Sample *dados;

public:

    GeneticAlgorithm();

    void execute();

    void iniciarPopulacao();
    void avaliarPopulacao();
    void ordenarPopulacao();
    void removerIndividuos(int qtd);
    void avaliarObjetivo(Individual &ind);

    void cruzamentoUniforme(Individual pai1, Individual pai2);
    void cruzamentoMaioria(Individual pai1, Individual pai2);

    void mutacaoGuiada(Individual &ind);
    void mutacaoMaiorPeso(Individual &ind);

    void avaliarDominancia(Individual &ind);

    Individual torneio();

};

#endif // GENETIC_ALGORITHM_H
