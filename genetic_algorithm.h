#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <vector>
#include <individual.h>

class GeneticAlgorithm
{
private:

    std::vector <Individual> populacao;
    int individuo_vencedor;

    int tamanho_populacao;
    int numero_geracoes;
    int geracao_atual;

    double tx_cruzamento;
    double tx_mutacao;

    int total_variaveis;
    int total_amostras;
    int ponto_corte;

public:

    GeneticAlgorithm();

    void execute();

    void iniciarPopulacao();
    void avaliarPopulacao();
    void ordenarPopulacao();
    void avaliarObjetivo(Individual &ind);

    void cruzamentoUniforme(Individual pai1, Individual pai2);
    void cruzamentoMaioria(Individual pai1, Individual pai2);

    void mutacaoGuiada(Individual &ind);
    void mutacaoMaiorPeso(Individual &ind);

    void avaliarDominancia(Individual &ind);

    Individual torneio();

};

#endif // GENETIC_ALGORITHM_H
