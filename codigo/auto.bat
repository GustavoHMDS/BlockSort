@echo off
REM ==========================
REM Configuração de caminhos
REM ==========================

REM Caminho para o executável (assumindo que ele está na raiz)
set EXE=comparaOrdenadores.exe

REM Caminho para a pasta de testes
set TESTES=dados\Testes

REM Lista de algoritmos
set algoritmos=insertionsort selectionsort bubblesort

REM Listas de arquivos
set arquivos50=C50k D50k A50k
set arquivos250=C250k D250k A250k
set arquivos500=C500k D500k A500k
set arquivos1m=C1m D1m

REM Tempo até TimeOut (Atualmente 1h)
set tempoMax=3600 

REM ==========================
REM Loop para arquivos 50k
REM ==========================
for %%a in (%algoritmos%) do (
    for %%f in (%arquivos50%) do (
        echo Rodando %%a com %%f...
        %EXE% %%a %TESTES%\%%f y %tempoMax%
    )
)

REM ==========================
REM Loop para arquivos 250k
REM ==========================
for %%a in (%algoritmos%) do (
    for %%f in (%arquivos250%) do (
        echo Rodando %%a com %%f...
        %EXE% %%a %TESTES%\%%f y %tempoMax%
    )
)

REM ==========================
REM Loop para arquivos 500k
REM ==========================
for %%a in (%algoritmos%) do (
    for %%f in (%arquivos500%) do (
        echo Rodando %%a com %%f...
        %EXE% %%a %TESTES%\%%f y %tempoMax%
    )
)

REM ==========================
REM Loop para arquivos 1m
REM ==========================
for %%a in (%algoritmos%) do (
    for %%f in (%arquivos1m%) do (
        echo Rodando %%a com %%f...
        %EXE% %%a %TESTES%\%%f y %tempoMax%
    )
)

echo Todas as execuções terminaram!
pause
