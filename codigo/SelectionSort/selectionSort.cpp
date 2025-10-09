#include "selectionSort.hpp"

void selectionSort(std::vector<int>& vetor) {
    for (int indice = 0; indice < vetor.size() - 1; indice++) {
        int indiceMenor = indice;
        for(int indiceBusca = indice + 1; indiceBusca < vetor.size(); indiceBusca++){
            if(vetor[indiceBusca] < vetor[indiceMenor]) {
                indiceMenor = indiceBusca;
            }
        }
        int buffer = vetor[indice];
        vetor[indice] = vetor[indiceMenor];
        vetor[indiceMenor] = buffer;
    }
}

size_t estimarMemoriaSelectionSort(size_t tamanhoVetor) {
    return (tamanhoVetor) * sizeof(int);
}

RelatorioPerformance selectionSortBenchMark(std::vector<int>& vetor) {
    auto inicio = std::chrono::high_resolution_clock::now();

    selectionSort(vetor);

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempo = fim - inicio;

    size_t memoriaUtilizada = estimarMemoriaSelectionSort(vetor.size());

    RelatorioPerformance relatorio;
    relatorio.memoriaEstimadaBytes = memoriaUtilizada;
    relatorio.tempoExecucaoEmSegundos = tempo.count();
    relatorio.nomeAlgoritmo = "selectionSort";

    return relatorio;
}