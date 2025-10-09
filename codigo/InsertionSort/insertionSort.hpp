#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>
#include <climits>
#include <chrono>
#include "codigo/Utils/relatorPerformance.hpp"

void insertionSortCrescente(std::vector<int>& vetor);
void insertionSortAuxiliar(std::vector<int>& vetor, int comeco, int final);
void insertionSortDecrescente(std::vector<int>& vetor, int comeco = 1, int final = -1);
RelatorioPerformance insertionSortBenchMark(std::vector<int>& vetor);

#endif