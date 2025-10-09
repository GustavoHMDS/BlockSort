#include "blockSort.hpp"

std::vector<Bloco> divideBloco(const std::vector<int>& vetor) {
    int tamanhoBlocos = static_cast<int>(std::sqrt(vetor.size()));
    int numPartes = (vetor.size() + tamanhoBlocos - 1) / tamanhoBlocos;
    std::vector<Bloco> blocos;

    for (int i = 0; i < numPartes; i++) {
        int ini = i * tamanhoBlocos;
        int fim = std::min((i+1) * tamanhoBlocos, (int)vetor.size());
        blocos.push_back({ini, fim});
    }

    return blocos;
}


void blockSort(std::vector<int>& vetor) {
    std::vector<Bloco> blocos;
    std::vector<int> novoVetor;

    std::vector<int> copiaDoVetor = vetor;

    blocos = divideBloco(copiaDoVetor);
    int numBlocos = blocos.size();

    // Organiza os blocos internamente
    for (auto& bloco : blocos) {
        insertionSortAuxiliar(copiaDoVetor, bloco.inicio, bloco.fim);
    }

    int numBlocosValidos = numBlocos;

    // ordena o vetor original
    for (int i = 0; i < vetor.size(); i++) {
        int blocoMenorElemento = 0;
        int menorAteAgora = blocos[0].inicio;

        // busca o menor elemento
        for (int j = 1; j < numBlocosValidos; j++) {
            int primeiroDoBloco = blocos[j].inicio;
            if (copiaDoVetor[primeiroDoBloco] < copiaDoVetor[menorAteAgora]) {
                blocoMenorElemento = j;
                menorAteAgora = primeiroDoBloco;
            }
        }

        // atualiza o vetor com o menor indice
        vetor[i] = copiaDoVetor[menorAteAgora];
        blocos[blocoMenorElemento].inicio++;

        // remove o bloco se ele estiver "vazio", evita ter que reordenar o vetor de bloco
        if (blocos[blocoMenorElemento].inicio >= blocos[blocoMenorElemento].fim) {
            blocos[blocoMenorElemento] = blocos.back(); // copia o ultimo para a posição atual
            blocos.pop_back(); // remove o ultimo "original"
            numBlocosValidos--;
        }
    }
}

size_t estimarMemoriaBlockSort(size_t tamanhoVetor) {
    int tamanhoBlocos = static_cast<int>(std::sqrt(tamanhoVetor));
    return (2 * tamanhoVetor + 2 * (tamanhoVetor + tamanhoBlocos - 1) / tamanhoBlocos) * sizeof(int); // Vetor original + copia + cada bloco salva dois ints
}

RelatorioPerformance blockSortBenchMark(std::vector<int>& vetorInicial) {
    auto inicio = std::chrono::high_resolution_clock::now();

    blockSort(vetorInicial);

    auto fim = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> tempo = fim - inicio;

    size_t memoriaUtilizada = estimarMemoriaBlockSort(vetorInicial.size());

    RelatorioPerformance relatorio;
    relatorio.memoriaEstimadaBytes = memoriaUtilizada;
    relatorio.tempoExecucaoEmSegundos = tempo.count();
    relatorio.nomeAlgoritmo = "BlockSort";

    return relatorio;
}