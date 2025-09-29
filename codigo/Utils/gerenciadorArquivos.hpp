#ifndef GERENCIADOR_ARQUIVOS_HPP
#define GERENCIADOR_ARQUIVOS_HPP

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <string>
#include "relatorPerformance.hpp"

std::vector<int> lerVetorDeArquivo(const std::string& caminhoArquivo);
void imprimeResultados(RelatorioPerformance relatorioMerge, RelatorioPerformance relatorioBlock, std::string nomeEntrada);

#endif