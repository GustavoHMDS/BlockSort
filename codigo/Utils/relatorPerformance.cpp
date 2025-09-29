#include "relatorPerformance.hpp"

void imprimeRelatorio(const RelatorioPerformance& relatorio, std::ofstream& saida) {
    saida << "Algoritmo: " << relatorio.nomeAlgoritmo << "\n";
    saida << "Tempo (s): " << relatorio.tempoExecucaoEmSegundos << "\n";
    saida << "Memória estimada (bytes): " << relatorio.memoriaEstimadaBytes << "\n";
    saida << "-------------------------------\n";
};