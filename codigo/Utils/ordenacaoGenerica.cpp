#include"ordenacaoGenerica.hpp"

void insertionSortCrescente(std::vector<int>& blocoDesorganizado) {
    int tamBloco = blocoDesorganizado.size();
    for (int indice = 1; indice < tamBloco; indice++) {
        int chave = blocoDesorganizado[indice];
        int indiceBusca = indice - 1;

        while (indiceBusca >= 0 && blocoDesorganizado[indiceBusca] > chave) {
            blocoDesorganizado[indiceBusca + 1] = blocoDesorganizado[indiceBusca];
            indiceBusca--;
        }
        blocoDesorganizado[indiceBusca + 1] = chave;
    }
}

void insertionSortDecrescente(std::vector<int>& blocoDesorganizado) {
    int tamBloco = blocoDesorganizado.size();
    for (int indice = 1; indice < tamBloco; indice++) {
        int chave = blocoDesorganizado[indice];
        int indiceBusca = indice - 1;

        while (indiceBusca >= 0 && blocoDesorganizado[indiceBusca] < chave) {
            blocoDesorganizado[indiceBusca + 1] = blocoDesorganizado[indiceBusca];
            indiceBusca--;
        }
        blocoDesorganizado[indiceBusca + 1] = chave;
    }
}