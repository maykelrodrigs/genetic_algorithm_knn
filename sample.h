#ifndef SAMPLE_H
#define SAMPLE_H

#include <vector>

class Sample
{

public:

    std::vector< std::vector <double> > variaveis;
    std::vector<bool> tipo;
    std::vector<double> peso_variaveis;

    int populacao;
    int geracao;
    int geracao_alteracao;

    double tx_mutacao_gene;
    double tx_mutacao;

    int nr_variaveis;
    int nr_amostras;

public:

    Sample();
    void lerAmostras(char file[]);
};

#endif // SAMPLE_H
