#include "mergeSort.hpp"

void mergeSort(std::vector<int>& vetorPai) {
    if(vetorPai.size() <= 1) {
        return;
    }

    int meio = vetorPai.size() / 2;

    std::vector<int> vetorA(vetorPai.begin(), vetorPai.begin() + meio);
    std::vector<int> vetorB(vetorPai.begin() + meio, vetorPai.end());
    
    mergeSort(vetorA);
    mergeSort(vetorB);

    int indiceA = 0, indiceB = 0, indicePai = 0;
    while (indiceA < vetorA.size() && indiceB < vetorB.size()) {
        if (vetorA[indiceA] < vetorB[indiceB]) {
            vetorPai[indicePai++] = vetorA[indiceA++];
        } else {
            vetorPai[indicePai++] = vetorB[indiceB++];
        }
    }
    while (indiceA < vetorA.size()) vetorPai[indicePai++] = vetorA[indiceA++];
    while (indiceB < vetorB.size()) vetorPai[indicePai++] = vetorB[indiceB++];
}

size_t estimarMemoriaMergeSort(size_t tamanhoVetor) {
    if (tamanhoVetor <= 1) return 0;

    size_t meio = tamanhoVetor / 2;
    size_t memoriaLocal = tamanhoVetor * sizeof(int); // vetorA + vetorB

    size_t picoEsquerda = estimarMemoriaMergeSort(meio);
    size_t picoDireita = estimarMemoriaMergeSort(tamanhoVetor - meio);

    size_t picoComFilhos = memoriaLocal + std::max(picoEsquerda, picoDireita);

    return std::max(memoriaLocal, picoComFilhos);
}

RelatorioPerformance mergeSortBenchMark(std::vector<int>& vetorPai) {
    auto inicio = std::chrono::high_resolution_clock::now();

    mergeSort(vetorPai);

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempo = fim - inicio;

    size_t memoriaUtilizada = estimarMemoriaMergeSort(vetorPai.size());

    RelatorioPerformance relatorio;
    relatorio.memoriaEstimadaBytes = memoriaUtilizada;
    relatorio.tempoExecucaoEmSegundos = tempo.count();
    relatorio.nomeAlgoritmo = "MergeSort";

    return relatorio;
}