#include "BlockSort/blockSort.hpp"
#include "InsertionSort/insertionSort.hpp"
#include "SelectionSort/selectionSort.hpp"
#include "BubbleSort/bubbleSort.hpp"
#include "Utils/relatorPerformance.hpp"
#include "Utils/gerenciadorArquivos.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <future>
#include <chrono>
#include <functional>

#define DEZ_MINUTOS 600

template<typename Func>
RelatorioPerformance runComTimeout(Func algoritmoOrdenacao, std::chrono::seconds timeout, const std::string& nomeAlgoritmo, std::vector<int>& vetor) {
    auto thread = std::async(std::launch::async, algoritmoOrdenacao, std::ref(vetor));
    RelatorioPerformance relatorio;
    if (thread.wait_for(timeout) == std::future_status::timeout) {
        relatorio.sucesso = false;
        relatorio.nomeAlgoritmo = nomeAlgoritmo;
    } else {
        relatorio = thread.get();
        relatorio.sucesso = true; // opcional, dependendo da função
    }

    return relatorio;
}


int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << "<nome_algoritmo> <arquivo_entrada> <imprimir_vetor(Y/n)>" << std::endl;
        return 1;
    }

    std::string nomeAlgoritmo = argv[1];
    std::string nomeArquivo = argv[2];
    std::string escolhaImpressao = argv[3];
    
    bool imprimeVetores = (escolhaImpressao == "y" || escolhaImpressao == "Y");
    std::vector<int> vetor = lerVetorDeArquivo(nomeArquivo);

    if (vetor.empty()) {
        std::cerr << "Erro: vetor lido está vazio ou houve falha na leitura." << std::endl;
        return 1;
    }
    
    RelatorioPerformance relatorio;

    constexpr std::chrono::seconds tempoMax(DEZ_MINUTOS);
    std::function<RelatorioPerformance(std::vector<int>&)> ordenador;
    
    if(nomeAlgoritmo == "insertionsort") {
        ordenador = insertionSortBenchMark;
    }
    else if(nomeAlgoritmo == "selectionsort") {
        ordenador = selectionSortBenchMark;
    }
    else if(nomeAlgoritmo == "bubblesort") {
        ordenador = bubbleSortBenchMark;
    }
    else if(nomeAlgoritmo == "blocksort") {
        ordenador = blockSortBenchMark;
    }
    else {
        std::cout << "Nome de algoritmo invalido. Escolha: 'insertionsort', 'selectionsort', 'bubblesort', 'blocksort' " << std::endl;
        exit(1);
    }
    std::cout << "Ordenando..." << std::endl;
    auto thread = std::async(std::launch::async, ordenador, std::ref(vetor));
    if (thread.wait_for(tempoMax) == std::future_status::timeout) {
        relatorio.sucesso = false;
        relatorio.nomeAlgoritmo = nomeAlgoritmo;

        imprimeResultados(relatorio, nomeArquivo);
        if(imprimeVetores){
            imprimeVetorOrdenado(vetor, relatorio, nomeArquivo);
        }
        std::cout << "O tempo acabou. O algoritmo não conseguiu completar a tempo.\n";
        exit(1);
    } else {
        relatorio = thread.get();
        relatorio.sucesso = true;

        imprimeResultados(relatorio, nomeArquivo);
        if(imprimeVetores){
            imprimeVetorOrdenado(vetor, relatorio, nomeArquivo);
        }
        std::cout << "Benchmark concluído. Resultados adicionados ao arquivo 'relatorios.txt'.\n";
        return 0;
    }
}
