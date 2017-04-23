#include "sample.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>     /* atof */
#include <sstream>
#include <string.h>

using namespace std;

/*-------------------------------------------------------------------*/
/*!

 */
Sample::Sample()
{

    populacao           = 1000;
    geracao             = 1000;
    geracao_alteracao   = 10; // porcentagem

    tx_mutacao_gene     = 0.05;
    tx_mutacao          = 0.30;

    nr_variaveis        = 661;
    nr_amostras         = 69;

}

/*-------------------------------------------------------------------*/
/*!

 */
void Sample::lerAmostras( char file[] )
{

    ifstream arquivo ( file );
    string line;
    string line_value;
    int aux = 1;
    int nr_line = 0;

    while(getline(arquivo, line))
    {

        vector<double> dados_line;
        stringstream ss(line);
        nr_line++;

        while(getline(ss, line_value, ';'))
        {
            double number = atof(line_value.c_str());

            if ( nr_line == nr_variaveis + 1 )
                tipo.push_back( number );

            else if ( aux % ( nr_amostras + 1 ) == 0
                      && aux != 1)
                peso_variaveis.push_back( number );

            else
                dados_line.push_back( number );

            aux++;
        }
        dados.emplace_back( dados_line );
    }

    dados.pop_back(); // está pegando o ultimo elemento zerado
    tipo.pop_back(); // está pegando o ultimo elemento zerado

    arquivo.close();
}
