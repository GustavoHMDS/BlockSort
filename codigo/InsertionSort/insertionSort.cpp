#include "insertionSort.hpp"

void insertionSortCrescente(std::vector<int>& vetor) {
    for (int indice = 1; indice < vetor.size(); indice++) {
        int chave = vetor[indice];
        int indiceBusca = indice - 1;

        while (indiceBusca >= 0 && vetor[indiceBusca] > chave) {
            vetor[indiceBusca + 1] = vetor[indiceBusca];
            indiceBusca--;
        }
        vetor[indiceBusca + 1] = chave;
    }
}

void insertionSortAuxiliar(std::vector<int>& vetor, int comeco, int final) {
    if (final == -1) {
        final = vetor.size();
    }

    for (int indice = comeco + 1; indice < final; indice++) {
        int chave = vetor[indice];
        int indiceBusca = indice - 1;

        while (indiceBusca >= comeco && vetor[indiceBusca] > chave) {
            vetor[indiceBusca + 1] = vetor[indiceBusca];
            indiceBusca--;
        }
        vetor[indiceBusca + 1] = chave;
    }
}

void insertionSortDecrescente(std::vector<int>& vetor, int comeco, int final) {
    if (final == -1) {
        final = vetor.size();
    }

    for (int indice = comeco + 1; indice < final; indice++) {
        int chave = vetor[indice];
        int indiceBusca = indice - 1;

        while (indiceBusca >= comeco && vetor[indiceBusca] < chave) {
            vetor[indiceBusca + 1] = vetor[indiceBusca];
            indiceBusca--;
        }
        vetor[indiceBusca + 1] = chave;
    }
}

size_t estimarMemoriaInsertionSort(size_t tamanhoVetor) {
    return (tamanhoVetor) * sizeof(int);
}

RelatorioPerformance insertionSortBenchMark(std::vector<int>& vetor) {
    auto inicio = std::chrono::high_resolution_clock::now();

    insertionSortCrescente(vetor);

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempo = fim - inicio;

    size_t memoriaUtilizada = estimarMemoriaInsertionSort(vetor.size());

    RelatorioPerformance relatorio;
    relatorio.memoriaEstimadaBytes = memoriaUtilizada;
    relatorio.tempoExecucaoEmSegundos = tempo.count();
    relatorio.nomeAlgoritmo = "InsertionSort";

    return relatorio;
}