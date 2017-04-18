#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include <vector>
#include <individual.h>

class genetic_algorithm
{
private:

    std::vector <individual> populacao;
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
    genetic_algorithm();

    void execute();
    void iniciarPopulacao();
    void avaliarPopulacao();
    void ordenarPopulacao();
    void avaliarObjetivo(individual ind);

};

#endif // GENETIC_ALGORITHM_H
