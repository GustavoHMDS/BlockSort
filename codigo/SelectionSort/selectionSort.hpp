#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>
#include <climits>
#include <chrono>
#include "codigo/Utils/relatorPerformance.hpp"

void selectionSort(std::vector<int>& vetor);
RelatorioPerformance selectionSortBenchMark(std::vector<int>& vetor);

#endif