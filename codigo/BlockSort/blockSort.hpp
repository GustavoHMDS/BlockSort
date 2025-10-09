#ifndef BLOCK_SORT_HPP
#define BLOCK_SORT_HPP

#include <vector>
#include <climits>
#include <chrono>
#include <cmath>
#include "codigo/InsertionSort/insertionSort.hpp"
#include "codigo/Utils/relatorPerformance.hpp"

typedef struct {
    int inicio;
    int fim;
} Bloco;

void blockSort(std::vector<int>& vetor);
RelatorioPerformance blockSortBenchMark(std::vector<int>& vetorInicial);

#endif