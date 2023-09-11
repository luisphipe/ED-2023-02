#include <stdio.h>

//1. Leitura de dados:
void lerDimensoes(int *linhas, int *colunas) {
    printf("Digite o número de linhas: ");
    scanf("%d", linhas);

    printf("Digite o número de colunas: ");
    scanf("%d", colunas);
}

//2. Alocação dinâmica:
unsigned char** alocarMatriz(int linhas, int colunas) {
    unsigned char** matriz = (unsigned char**)malloc(linhas * sizeof(unsigned char*));

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (unsigned char*)malloc(colunas * sizeof(unsigned char));
    }

    return matriz;
}

//3. Preenchimento da imagem:
void preencherImagem(unsigned char** imagem, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            imagem[i][j] = (unsigned char)(rand() % 256);
        }
    }
}

//4. Salvar imagem:
void salvarImagem(unsigned char** imagem, int linhas, int colunas) {
    FILE* arquivo;
    arquivo = fopen("imagem.ppm", "wb");

    fprintf(arquivo, "P2\n%d %d\n255\n", colunas, linhas);

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            fputc(imagem[i][j], arquivo);
            fputc(imagem[i][j], arquivo);
            fputc(imagem[i][j], arquivo);
        }
    }

    fclose(arquivo);
}

//Agora, a função `main` que vai juntar tudo:
int main() {
    int linhas, colunas;

    lerDimensoes(&linhas, &colunas);

    unsigned char** imagem = alocarMatriz(linhas, colunas);

    preencherImagem(imagem, linhas, colunas);

    salvarImagem(imagem, linhas, colunas);

    // Liberando a memória alocada
    for (int i = 0; i < linhas; i++) {
        free(imagem[i]);
    }
    free(imagem);

    return 0;
}

//Esse código lê as dimensões da imagem, aloca memória dinamicamente para a imagem, preenche a imagem com valores aleatórios, 
//salva a imagem em formato PPM e libera a memória alocada. Lembre-se de incluir a biblioteca `stdlib.h` para utilizar as funções `malloc` e `free`.
