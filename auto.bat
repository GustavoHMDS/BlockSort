@echo off
REM Lista de algoritmos e arquivos
set algoritmos=insertionsort selectionsort bubblesort 

REM arquivos 50k
set arquivos50=C50k D50k A50k

REM arquivos 250k
set arquivos250=C250k D250k A250k

REM arquivos 500k
set arquivos500k=C500k D500k A500k

REM arquivos 1m
set arquivos1m=C1mk D1mk 

REM Loop para os arquivos 50k
for %%a in (%algoritmos%) do (
    for %%f in (%arquivos50%) do (
        echo Rodando %%a com %%f...
        comparaOrdenadores.exe %%a dados/Testes/%%f y 3600
    )
)

REM Loop para os arquivos 250k
for %%a in (%algoritmos%) do (
    for %%f in (%arquivos250%) do (
        echo Rodando %%a com %%f...
        comparaOrdenadores.exe %%a dados/Testes/%%f y 3600
    )
)

REM Loop para os arquivos 500k
for %%a in (%algoritmos%) do (
    for %%f in (%arquivos500k%) do (
        echo Rodando %%a com %%f...
        comparaOrdenadores.exe %%a dados/Testes/%%f y 3600
    )
)

REM Loop para os arquivos 1m
for %%a in (%algoritmos%) do (
    for %%f in (%arquivos1m%) do (
        echo Rodando %%a com %%f...
        comparaOrdenadores.exe %%a dados/Testes/%%f y 3600
    )
)

echo Todas as execuções terminaram!
pause
