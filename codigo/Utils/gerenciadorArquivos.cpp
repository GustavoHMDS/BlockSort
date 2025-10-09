#include "gerenciadorArquivos.hpp"

std::string extrairNomeArquivo(std::string caminho) {
    size_t posBarra = caminho.find_last_of('/');
    if (posBarra == std::string::npos) {
        return caminho;
    }
    return caminho.substr(posBarra + 1);
}

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

void imprimeResultados(RelatorioPerformance relatorio, std::string nomeEntrada) {
    std::ofstream ArquivoRelatorio("dados/relatorios.txt", std::ios::app);
    
    if (!ArquivoRelatorio.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de relatorios." << std::endl;
        exit(1);
    }
    std::string nomeSemBarra = extrairNomeArquivo(nomeEntrada);
    ArquivoRelatorio << "Arquivo de entrada: " << nomeSemBarra << "\n";

    ArquivoRelatorio << imprimeRelatorio(relatorio);

    ArquivoRelatorio.flush();
    ArquivoRelatorio.close();
}

void imprimeVetorOrdenado(std::vector<int> vetor, RelatorioPerformance relatorio, std::string nomeEntrada) {
    std::ostringstream nomeSaida;
    std::string nomeSemBarra = extrairNomeArquivo(nomeEntrada);
    nomeSaida << "dados/Saidas/" << nomeSemBarra;

    std::ofstream saida(nomeSaida.str(), std::ios::app);
    
    if (!saida.is_open()) {
        std::cerr << "Erro ao abrir o arquivo de saida." << std::endl;
        return;
    }
    saida << "Vetor do " << relatorio.nomeAlgoritmo << ": \n";
    for(int elemento : vetor) { 
        saida << elemento << " ";
    }
    saida << "\n------------------------------------------------------------------\n";
    
    saida.flush();
    saida.close();
}

void salvaVetorEmArquivo(const std::vector<int>& vetor, const std::string& nomeArquivo) {
    std::ostringstream nomeSaida;
    std::string nomeSemBarra = extrairNomeArquivo(nomeArquivo);
    nomeSaida << "dados/Testes/" << nomeSemBarra;
    std::ofstream arquivo(nomeSaida.str()); // Abre o arquivo para escrita

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo: " << nomeSaida.str() << std::endl;
        return;
    }

    for (int numero : vetor) {
        arquivo << numero << " ";
    }

    arquivo << std::endl; // Nova linha no final (opcional)

    arquivo.close(); // Fecha o arquivo
}