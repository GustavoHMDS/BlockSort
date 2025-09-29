#include "gerenciadorArquivos.hpp"

std::vector<int> lerVetorDeArquivo(const std::string& caminhoArquivo) {
    std::vector<int> vetor;
    std::ifstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo: " << caminhoArquivo << std::endl;
        return vetor;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::istringstream streamLinha(linha);
        int numero;

        while (streamLinha >> numero) {
            vetor.push_back(numero);
        }
    }

    arquivo.close();
    return vetor;
}

void imprimeResultados(RelatorioPerformance relatorioMerge, RelatorioPerformance relatorioBlock, std::string nomeEntrada) {
    std::ofstream relatorio("../../dados/relatorios.txt", std::ios::app);
    if (!relatorio.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de relatorios." << std::endl;
        exit(1);
    }

    relatorio << "Arquivo de entrada: " << nomeEntrada << "\n";

    imprimeRelatorio(relatorioMerge, relatorio);
    imprimeRelatorio(relatorioBlock, relatorio);

    relatorio.close();

    std::cout << "Benchmark concluído. Resultados adicionados ao arquivo 'relatorios.txt'.\n";
}