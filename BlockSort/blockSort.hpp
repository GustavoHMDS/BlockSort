#ifndef BLOCK_SORT_HPP
#define BLOCK_SORT_HPP

#include <vector>
#include <climits>
#include <chrono>
#include "../Utils/ordenacaoGenerica.hpp"
#include "../Utils/relatorPerformance.hpp"

void blockSort(int tamanhoBlocos, std::vector<int>& vetor);
RelatorioPerformance blockSortBenchMark(int tamanhoBlocos, std::vector<int>& vetorInicial);

#endif