#include <stdio.h>

int main() {
    FILE *arquivo, *possiveis;
    char nome[40];
    float preco, orcamento;
    int quantidade, i;
    printf("Quantos itens deseja cadastrar? ");
    scanf("%d", &quantidade);
    arquivo = fopen("compras.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    for (i = 0; i < quantidade; i++) {
        printf("\nNome do produto: ");
        scanf(" %39s", nome);
        printf("Preco: R$ ");
        scanf("%f", &preco);
        fprintf(arquivo, "%s;%.2f\n", nome, preco);
    }
    fclose(arquivo);
    printf("\nDigite seu orcamento: R$ ");
    scanf("%f", &orcamento);
    arquivo = fopen("compras.txt", "r");
    possiveis = fopen("Compras_Possiveis.txt", "w");
    if (arquivo == NULL || possiveis == NULL) {
        printf("Erro ao abrir arquivo!\n");
        if (arquivo != NULL) fclose(arquivo);
        if (possiveis != NULL) fclose(possiveis);
        return 1;
    }
    while (fscanf(arquivo, " %39s;%f", nome, &preco) == 2) {
        if (preco <= orcamento) {
            fprintf(possiveis, "%s;%.2f\n", nome, preco);
        }
    }
    fclose(arquivo);
    fclose(possiveis);
    possiveis = fopen("Compras_Possiveis.txt", "r");
    if (possiveis == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    printf("\n===== COMPRAS POSSIVEIS =====\n");
    while (fscanf(possiveis, " %39s;%f", nome, &preco) == 2) {
        printf("%s - R$ %.2f\n", nome, preco);
    }
    fclose(possiveis);
    
    return 0;
}
