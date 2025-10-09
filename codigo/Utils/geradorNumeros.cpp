#include "geradorNumeros.hpp"

std::vector<int> geraVetorNumeros(int tamanho, int ordenacao) {
    std::vector<int> numeros;

    // Preenche o vetor com números de 1 até tamanho


    std::random_device seed;
    std::mt19937 randomizer(seed());

    // Embaralha o vetor usando um gerador aleatório
    switch(ordenacao) {
        case CRESCENTE:
            for (int i = 1; i <= tamanho; i++) {
                numeros.push_back(i);
            }
            break;
        case DESORDENADO:
            for (int i = 1; i <= tamanho; i++) {
                numeros.push_back(i);
            }
            std::shuffle(numeros.begin(), numeros.end(), randomizer);
            break;
        case DECRESCENTE:
            for (int i = tamanho; i >= 1; i--) {
                numeros.push_back(i);
            }
            insertionSortDecrescente(numeros);
            break;
        default:
            std::cout << "Opcao de ordenacao invalida! (-1: CRESCENTE, 0: DESORDENADO, 1: DECRESCENTE) " << std::endl;
            break;
    }

    return numeros;
}

int main(int argc, char* argv[]) {
    std::cout << "Verificando argumentos... " << std::endl;
    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " <tamanho> <ordenacao> <nome_arquivo>" << std::endl;
        std::cerr << "Exemplo: " << argv[0] << " 100 1 vetor100A.txt" << std::endl;
        return 1;
    }

    std::cout << "Gerando... " << std::endl;

    // Converte os argumentos da linha de comando
    int tamanho = std::stoi(argv[1]);
    int ordenacao = std::stoi(argv[2]);
    std::string nomeArquivo = argv[3];

    // Gera e salva o vetor
    std::vector<int> vetor = geraVetorNumeros(tamanho, ordenacao);
    salvaVetorEmArquivo(vetor, nomeArquivo);

    std::cout << "Vetor salvo com sucesso em: " << nomeArquivo << std::endl;

    return 0;
}