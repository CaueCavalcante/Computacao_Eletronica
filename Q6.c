#include <stdio.h>

typedef struct {
    char nome[40];
    int quantidade;
} Produto;

float calcular_media (int total) {
    return total/7.0;
}

int main () {
    Produto produtos[7];
    FILE *arquivo;
    int i, total = 0, trinta_mais = 0;
    int maior, menor;
    float media;
    for (i = 0; i < 7; i++) {
        printf("Nome do produto: ");
        scanf("%39s", produtos[i].nome);
        printf("Quantidade vendida: ");
        scanf("%d", &produtos[i].quantidade);
    }
    arquivo = fopen("vendas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }
    for (i = 0; i < 7; i++) {
        fprintf(arquivo, "%s %d\n", produtos[i].nome, produtos[i].quantidade);
    }
    fclose(arquivo);
    arquivo = fopen("vendas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo");
        return 1;
    }
    for (i = 0; i < 7; i++) {
        fscanf(arquivo, "%39s %d\n", produtos[i].nome, &produtos[i].quantidade);
        total += produtos[i].quantidade;
        if (produtos[i].quantidade > 30) trinta_mais++;
    }
    fclose(arquivo);
    maior = menor = 0;
    for (i = 0; i < 7; i++) {
        if (produtos[i].quantidade > produtos[maior].quantidade) maior = i;
        if (produtos[i].quantidade < produtos[menor].quantidade) menor = i;
    }
    media = calcular_media(total);
    printf("\n===== RESULTADO DAS VENDAS =====\n");
    printf("Total vendido: %d\n", total);
    printf("Media de vendas: %.2f\n", media);
    printf("Produto que mais vendeu: %s (%d unidades)\n", produtos[maior].nome, produtos[maior].quantidade);
    printf("Produto que menos vendeu: %s (%d unidades)\n", produtos[menor].nome, produtos[menor].quantidade);
    printf("Produtos com mais de 30 unidades: %d\n", trinta_mais);
    
    return 0;
}
