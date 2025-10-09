#include "relatorPerformance.hpp"

std::string imprimeRelatorio(const RelatorioPerformance& relatorio) {
    std::ostringstream texto;
    if(relatorio.sucesso){
        texto << "Algoritmo: " << relatorio.nomeAlgoritmo << "\n";
        texto << "Tempo (s): " << relatorio.tempoExecucaoEmSegundos << "\n";
        texto << "Memória estimada (bytes): " << relatorio.memoriaEstimadaBytes << "\n";
        texto << "-------------------------------\n";
    }
    else {
        texto << "Algoritmo: " << relatorio.nomeAlgoritmo << "\n";
        texto << "Tempo (s): Não completou \n";
        texto << "Memória estimada (bytes): Não completou \n";
        texto << "-------------------------------\n";
    }
    return texto.str();
};