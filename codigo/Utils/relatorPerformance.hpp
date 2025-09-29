#ifndef RELATOR_PERFORMANCE_HPP
#define RELATOR_PERFORMANCE_HPP

#include <string>
#include <iostream>
#include <fstream>

struct RelatorioPerformance {
    double tempoExecucaoEmSegundos;
    int memoriaEstimadaBytes;
    std::string nomeAlgoritmo;
};

void imprimeRelatorio(const RelatorioPerformance& relatorio, std::ofstream& saida);

#endif