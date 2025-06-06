#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int primeiroNavio[3] = {3, 3, 3}; // Navio Horizontal
    int segundoNavio[3] = {3, 3, 3}; // Navio Vertical
    int terceiroNavio[3] = {3, 3, 3}; // Navio Diagonal 
    int quartoNavio[3] = {3, 3, 3}; // Navio Diagonal 

    // Coordenadas dos navios
    int linhaPrimeiroNavio = 2;
    int colunaPrimeiroNavio = 4;

    int linhaSegundoNavio = 6;
    int colunaSegundoNavio = 1;

    int linhaTerceiroNavio = 0;
    int colunaTerceiroNavio = 0;

    int linhaQuartoNavio = 6;
    int colunaQuartoNavio = 9;

    // Coordenadas das habilidades
    int linhaCone = 5;
    int colunaCone = 5;

    int linhaCruz = 0;
    int colunaCruz = 4;

    int linhaOctaedro = 4;
    int colunaOctaedro = 0;

    // Flags de validacao dentro do tabuleiro
    int primeiroNavioDentro, segundoNavioDentro, terceiroNavioDentro, quartoNavioDentro;
    int coneDentro, cruzDentro, octaedroDentro;

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Criação do Tabuleiro
    int tabuleiro[10][10];

    // Criação das matrizes de habilidade
    int cone[3][5];
    int cruz[3][5];
    int octaedro[3][5];

    // Preenchimento das matrizes de habilidade
    // Cone
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(i == 0){
                if(j !=2 )
                    cone[i][j] = 0;
                else
                    cone[i][j] = 1;
            }else if(i == 1){
                if(j != 0 && j != 4)
                    cone[i][j] = 1;
                else
                    cone[i][j] = 0;
            }else{
                cone[i][j] = 1;
            }
        }
    }

    // Cruz
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(i == 0 || i == 2){
                if(j != 2)
                    cruz[i][j] = 0;
                else
                    cruz[i][j] = 1;
            }else if(i == 1){
                cruz[i][j] = 1;
            }
        }
    }

    // Octaedro
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(i == 0 || i == 2){
                if(j != 2)
                    octaedro[i][j] = 0;
                else
                    octaedro[i][j] = 1;
            }else{
                if(j != 0 && j != 4)
                    octaedro[i][j] = 1;
                else
                    octaedro[i][j] = 0;
            }
        }
    }

    // Preenchendo todas as posições do tabuleiro com 0
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }

    primeiroNavioDentro = colunaPrimeiroNavio + 3 <= 10;
    segundoNavioDentro = linhaSegundoNavio + 3 <= 10;
    terceiroNavioDentro = linhaTerceiroNavio + 3 <= 10 && colunaTerceiroNavio + 3 <= 10;
    quartoNavioDentro = linhaQuartoNavio + 3 <= 10 && colunaQuartoNavio - 2 >= 0;

    coneDentro = linhaCone + 3 <= 10 && colunaCone + 5 <= 10;
    cruzDentro = linhaCruz + 3 <= 10 && colunaCruz + 5 <= 10;
    octaedroDentro = linhaOctaedro + 3 <= 10 && colunaOctaedro + 5 <= 10;

    // Garantindo que as habilidades cabem no tabuleiro
    if (!coneDentro || !cruzDentro || !octaedroDentro) {
        printf("\nErro: Uma ou mais habilidades estao fora dos limites do tabuleiro\n");
        return 1;
    }

    // Garantindo que os navios cabem no tabuleiro
    if (!primeiroNavioDentro || !segundoNavioDentro || !terceiroNavioDentro || !quartoNavioDentro) {
        printf("Erro: Um ou mais navios estao fora dos limites do tabuleiro\n");
        return 1; // Encerra o programa
    }

    // Posiciona o primeiro navio horizontalmente
    for(int i = 0; i < 3; i++){
        tabuleiro[linhaPrimeiroNavio][colunaPrimeiroNavio + i] = primeiroNavio[i];
    }

    // Posiciona o segundo navio verticalmente, e verifica se se sobrepoe com o primeiro navio
    for(int i = 0; i < 3; i++){
        if(tabuleiro[linhaSegundoNavio + i][colunaSegundoNavio] == 0){
            tabuleiro[linhaSegundoNavio + i][colunaSegundoNavio] = segundoNavio[i];
        } else{
            printf("Erro: Navios estao sobrepostos na posicao [%d][%d]\n", linhaSegundoNavio + i, colunaSegundoNavio);
            return 1;
        }
    }

    // Posiciona o terceiro navio na diagonal (linha e coluna aumentam)
    for(int i = 0; i < 3; i++){
        if(tabuleiro[linhaTerceiroNavio + i][colunaTerceiroNavio + i] == 0){
            tabuleiro[linhaTerceiroNavio + i][colunaTerceiroNavio + i] = terceiroNavio[i];
        } else {
            printf("Erro: Navios estao sobrepostos na posicao [%d][%d]\n", linhaTerceiroNavio + i, colunaTerceiroNavio + i);
            return 1;
        }
    }

    // Posiciona o quarto navio na diagonal (linha aumenta e coluna diminui)
    for(int i = 0; i < 3; i++){
        if(tabuleiro[linhaQuartoNavio + i][colunaQuartoNavio - i] == 0){
            tabuleiro[linhaQuartoNavio + i][colunaQuartoNavio - i] = quartoNavio[i];
        } else {
            printf("Erro: Navios estao sobrepostos na posicao [%d][%d]\n", linhaQuartoNavio + i, colunaQuartoNavio - i);
            return 1;
        }
    }

    // Posicionando habilidade CONE no tabuleiro
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(cone[i][j] == 1){
                int lin = linhaCone + i;
                int col = colunaCone + j;
                if(tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = 1;
                else if(tabuleiro[lin][col] == 3)
                    tabuleiro[lin][col] = 4;
            }
        }
    }

    // Posicionando habilidade CRUZ no tabuleiro
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(cruz[i][j] == 1){
                int lin = linhaCruz + i;
                int col = colunaCruz + j;
                if(tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = 1;
                else if(tabuleiro[lin][col] == 3)
                    tabuleiro[lin][col] = 4;
            }
        }
    }

    // Posicionando habilidade OCTAEDRO no tabuleiro
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            if(octaedro[i][j] == 1){
                int lin = linhaOctaedro + i;
                int col = colunaOctaedro + j;
                if(tabuleiro[lin][col] == 0)
                    tabuleiro[lin][col] = 1;
                else if(tabuleiro[lin][col] == 3)
                    tabuleiro[lin][col] = 4;
            }
        }
    }

    // Imprimindo o titulo
    printf("TABULEIRO BATALHA NAVAL \n");
    printf("   ");
    for(int i = 0; i < 10; i++){
        printf("%c ", linha[i]); // Imprime os números das colunas
    }

    // Imprimindo o valor da cada linha com seu conteudo respectivo
    for(int i = 0; i < 10; i++){
        printf("\n%d ", i + 1);
        for(int j = 0; j < 10; j++){
            if(i == 9 && j == 0)
                printf("%d", tabuleiro[i][j]);
            else
                printf(" %d", tabuleiro[i][j]);
        }
    }

    printf("\n\nLegenda: 0 = agua | 3 = navio | 1 = Areas afetadas por hab. | 4 Barcos afetados por hab.\n");

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
