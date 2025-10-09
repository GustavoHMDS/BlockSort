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
void imprimeResultados(RelatorioPerformance relatorio, std::string nomeEntrada);
void imprimeVetorOrdenado(std::vector<int> vetor, RelatorioPerformance relatorios, std::string nomeEntrada);
void salvaVetorEmArquivo(const std::vector<int>& vetor, const std::string& nomeArquivo);

#endif