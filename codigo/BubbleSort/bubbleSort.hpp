#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <vector>
#include <climits>
#include <chrono>
#include "codigo/Utils/relatorPerformance.hpp"

void bubbleSort(std::vector<int>& vetor);
RelatorioPerformance bubbleSortBenchMark(std::vector<int>& vetor);

#endif