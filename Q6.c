#include <stdio.h>

typedef struct {
    char nome[40];
    int quantidade;
} Produto;

float calcularMedia(int total) {
    return total / 7.0;
}

int main() {
    Produto produtos[7];
    FILE *arquivo;
    int i, total = 0, mais30 = 0;
    int maior, menor;
    float media;
    for (i = 0; i < 7; i++) {
        printf("\nNome do produto: ");
        scanf(" %39[^\n]", produtos[i].nome);

        printf("Quantidade vendida: ");
        scanf("%d", &produtos[i].quantidade);
    }
    arquivo = fopen("vendas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    for (i = 0; i < 7; i++) {
        fprintf(arquivo, "%s %d\n", produtos[i].nome, produtos[i].quantidade);
    }
    fclose(arquivo);
    arquivo = fopen("vendas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    for (i = 0; i < 7; i++) {
        fscanf(arquivo, "%39s %d",
               produtos[i].nome, &produtos[i].quantidade);
        total += produtos[i].quantidade;
        if (produtos[i].quantidade > 30)
            mais30++;
    }
    fclose(arquivo);
    maior = menor = 0;
    for (i = 1; i < 7; i++) {
        if (produtos[i].quantidade > produtos[maior].quantidade)
            maior = i;
        if (produtos[i].quantidade < produtos[menor].quantidade)
            menor = i;
    }
    media = calcularMedia(total);
    printf("\n===== RESULTADO DAS VENDAS =====\n");
    printf("Total vendido: %d\n", total);
    printf("Media de vendas: %.2f\n", media);
    printf("Produto que mais vendeu: %s (%d unidades)\n", produtos[maior].nome, produtos[maior].quantidade);
    printf("Produto que menos vendeu: %s (%d unidades)\n", produtos[menor].nome, produtos[menor].quantidade);
    printf("Produtos com mais de 30 unidades: %d\n", mais30);

    return 0;
}
