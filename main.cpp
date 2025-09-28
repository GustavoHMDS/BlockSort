#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "MergeSort/mergeSort.hpp"
#include "BlockSort/blockSort.hpp"
#include "Utils/relatorPerformance.hpp"
#include "Utils/gerenciadorArquivos.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_entrada>" << std::endl;
        return 1;
    }

    std::string nomeArquivo = argv[1];
    std::vector<int> vetorOriginal = lerVetorDeArquivo(nomeArquivo);

    if (vetorOriginal.empty()) {
        std::cerr << "Erro: vetor lido está vazio ou houve falha na leitura." << std::endl;
        return 1;
    }

    std::vector<int> vetorParaMerge = vetorOriginal;
    std::vector<int> vetorParaBlock = vetorOriginal;

    int tamanhoBloco = static_cast<int>(std::sqrt(vetorParaBlock.size()));

    RelatorioPerformance relatorioMerge = mergeSortBenchMark(vetorParaMerge);
    RelatorioPerformance relatorioBlock = blockSortBenchMark(tamanhoBloco, vetorParaBlock); // define tamanho do bloco

    imprimeResultados(relatorioMerge, relatorioBlock, nomeArquivo);
}
