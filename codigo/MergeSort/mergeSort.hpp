#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <vector>
#include <climits>
#include <chrono>
#include "../Utils/ordenacaoGenerica.hpp"
#include "../Utils/relatorPerformance.hpp"

void mergeSort(std::vector<int>& vetorPai);
RelatorioPerformance mergeSortBenchMark(std::vector<int>& vetorPai);

#endif