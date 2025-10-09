#ifndef GERADOR_NUMEROS_HPP
#define GERADOR_NUMEROS_HPP

#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>
#include <string>
#include "codigo/InsertionSort/insertionSort.hpp"
#include "gerenciadorArquivos.hpp"

#define CRESCENTE -1
#define DESORDENADO 0
#define DECRESCENTE 1

// -1: CRESCENTE, 0: DESORDENADO, 1: DECRESCENTE
std::vector<int> geraVetorNumeros(int tamanho, int ordenacao);

#endif