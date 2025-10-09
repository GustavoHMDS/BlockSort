#include "bubbleSort.hpp"

void bubbleSort(std::vector<int>& vetor) {
    int ultimoElemento = vetor.size();
    while(ultimoElemento > 1) {
        for(int indiceBusca = 0; indiceBusca < ultimoElemento - 1; indiceBusca++) {
            if(vetor[indiceBusca] > vetor[indiceBusca + 1]) {
                int buffer = vetor[indiceBusca];
                vetor[indiceBusca] = vetor[indiceBusca + 1];
                vetor[indiceBusca + 1] = buffer;
            }
        }
        ultimoElemento--;
    }
}

size_t estimarMemoriaBubbleSort(size_t tamanhoVetor) {
    return (tamanhoVetor) * sizeof(int);
}

RelatorioPerformance bubbleSortBenchMark(std::vector<int>& vetor) {
    auto inicio = std::chrono::high_resolution_clock::now();

    bubbleSort(vetor);

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempo = fim - inicio;

    size_t memoriaUtilizada = estimarMemoriaBubbleSort(vetor.size());

    RelatorioPerformance relatorio;
    relatorio.memoriaEstimadaBytes = memoriaUtilizada;
    relatorio.tempoExecucaoEmSegundos = tempo.count();
    relatorio.nomeAlgoritmo = "bubbleSort";

    return relatorio;
}