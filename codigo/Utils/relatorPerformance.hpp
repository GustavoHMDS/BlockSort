#ifndef RELATOR_PERFORMANCE_HPP
#define RELATOR_PERFORMANCE_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

struct RelatorioPerformance {
    double tempoExecucaoEmSegundos;
    int memoriaEstimadaBytes;
    std::string nomeAlgoritmo;
    bool sucesso;
};

std::string imprimeRelatorio(const RelatorioPerformance& relatorio);

#endif