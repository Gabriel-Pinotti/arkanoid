
![Logo](https://raw.githubusercontent.com/Gabriel-Pinotti/arkanoid/refs/heads/main/assets/misc/mainmenu_logo.png)

## Desenvolvedores

> [Gabriel de Aquino Pinotti](https://www.github.com/gabriel-pinotti)
> [Matheus Fuckner](https://www.github.com/Fuckner-mt)


## Objetivo

Para o projeto de algorítmos e programação II / Universidade do Vale do Itajaí (UNIVALI), foi criado uma réplica do jogo "Arkanoid", lançado originalmente em 1986.
O projeto tem como objetivo colocar em prática conteúdos aprendidos ao decorrer das aulas, incluindo:
- Modularização
- Passagem de parâmetros (por valor e referência)
- Controle de escopos de variáveis
- Manipulação (leitura e escrita) em arquivos
- Sobrecarga de funções
- Estruturas (structs)
- Recursividade de funções


## Bibliotecas Utilizadas

O código foi feito principalmente em arquivos C++ (.cpp), com exceção de módulos (.h). Nestes arquivos, foram utilizadas as bibliotecas:

- [Raylib](https://www.raylib.com/)
- [C Math](https://cplusplus.com/reference/cmath/)
- [C Standard General Utilities](https://cplusplus.com/reference/cstdlib/)
- [C Time](https://cplusplus.com/reference/ctime/)
- [Input/Ouput Stream](https://cplusplus.com/reference/iostream/)
- [File Stream](https://cplusplus.com/reference/fstream/fstream/)
- [Chrono](https://cplusplus.com/reference/chrono/)
- [String Stream](https://cplusplus.com/reference/sstream/)
- [IO Manipulators](https://cplusplus.com/reference/iomanip/)
- [Algorithm](https://cplusplus.com/reference/algorithm/)


## Controles  

![img](https://raw.githubusercontent.com/Gabriel-Pinotti/arkanoid/refs/heads/main/assets/misc/controls.png)


## Regras do Jogo

- Controle o "paddle" para rebater a bola
- Faça com que a bola bata nos blocos, quebrando-os
- Evite que a bola colida com o "chão"
- Ganhe pontos conforme quebrar blocos, dependendo da dificuldade e do tempo
- Progrida entre os níveis, que terão blocos com mais durabilidade


## Compilação

Compile o código na pasta "arkanoid/main/" da seguinte forma:

> bash
```bash
    g++ ./src/main.cpp ./includes/*.cpp -lraylib -o arkanoid.out
    ./arkanoid.out
```
    
