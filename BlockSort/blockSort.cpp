#include "blockSort.hpp"

std::vector<std::vector<int>> divideBloco(int tamanhoBlocos, std::vector<int>& vetorInicial) {
    int numPartes = vetorInicial.size() / tamanhoBlocos;
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

std::vector<int> blockSort(int tamanhoBlocos, std::vector<int>& vetorInicial) {
    std::vector<std::vector<int>> blocos;
    std::vector<int> novoVetor;

    int numBlocos = vetorInicial.size() / tamanhoBlocos;

    blocos = divideBloco(tamanhoBlocos, vetorInicial);
    // Organiza os blocos internamente
    for (auto& bloco : blocos) {
        insertionSortCrescente(bloco);
    }

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
        novoVetor.push_back(menor);
        blocos[indiceMenor].erase(blocos[indiceMenor].begin()); // remove usado
    }
    return novoVetor;
}