#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
#include "BlockSort/blockSort.hpp"

int main() {
    std::vector<int> vetorInicial = {7, 3, 9, 2, 5, 8, 1, 4, 6};
    int tamBlocos =(int)sqrt(vetorInicial.size());
    std::vector<int> ordenado = blockSort(tamBlocos, vetorInicial);

    for (int x : ordenado) std::cout << x << " ";
    std::cout << std::endl;
}