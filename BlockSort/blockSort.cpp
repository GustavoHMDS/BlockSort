#include "blockSort.hpp"

std::vector<std::vector<int>> divideBloco(int tamanhoBlocos, std::vector<int>& vetorInicial) {
    int numPartes = (vetorInicial.size() + tamanhoBlocos - 1) / tamanhoBlocos;
    std::vector<std::vector<int>> blocos;

    for (int indice = 0; indice < numPartes; indice++) {
        int ini = indice * tamanhoBlocos;
        int fim;
        if (indice == numPartes-1) {
            fim = vetorInicial.size();
        } else {
            fim = (indice+1) * tamanhoBlocos;
        }
        blocos.push_back(std::vector<int>(vetorInicial.begin() + ini, vetorInicial.begin() + fim));
    }

    return blocos;
}

void blockSort(int tamanhoBlocos, std::vector<int>& vetor) {
    std::vector<std::vector<int>> blocos;
    std::vector<int> novoVetor;

    int numBlocos = vetor.size() / tamanhoBlocos;

    blocos = divideBloco(tamanhoBlocos, vetor);
    // Organiza os blocos internamente
    for (auto& bloco : blocos) {
        insertionSortCrescente(bloco);
    }

    vetor.clear();
    while(true) {
        int menor = INT_MAX;
        int indiceMenor = -1;

        // procura menor elemento entre blocos
        for (int i = 0; i < blocos.size(); i++) {
            if (!blocos[i].empty() && blocos[i][0] < menor) {
                menor = blocos[i][0];
                indiceMenor = i;
            }
        }

        if (indiceMenor == -1) break; // todos os blocos vazios
        vetor.push_back(menor);
        blocos[indiceMenor].erase(blocos[indiceMenor].begin()); // remove usado
    }
}

size_t estimarMemoriaBlockSort(size_t tamanhoVetor, int tamanhoBloco) {
    int numBlocos = (tamanhoVetor + tamanhoBloco - 1) / tamanhoBloco;
    size_t memoriaBlocos = numBlocos * sizeof(std::vector<int>);
    size_t memoriaElementos = tamanhoVetor * sizeof(int);

    return memoriaBlocos + memoriaElementos * 2;
}

RelatorioPerformance blockSortBenchMark(int tamanhoBlocos, std::vector<int>& vetorInicial) {
    auto inicio = std::chrono::high_resolution_clock::now();

    blockSort(tamanhoBlocos, vetorInicial);

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempo = fim - inicio;

    size_t memoriaUtilizada = estimarMemoriaBlockSort(vetorInicial.size(), tamanhoBlocos);

    RelatorioPerformance relatorio;
    relatorio.memoriaEstimadaBytes = memoriaUtilizada;
    relatorio.tempoExecucaoEmSegundos = tempo.count();
    relatorio.nomeAlgoritmo = "BlockSort";

    return relatorio;
}