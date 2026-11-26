#include <stdio.h>
#include <string.h>

int main() {
    FILE *arquivo, *possiveis;
    char nome[40];
    char linha[100];
    float preco, orcamento;
    int quantidade, i;
    printf("Quantos itens deseja cadastrar? ");
    scanf("%d", &quantidade);
    getchar();
    arquivo = fopen("compras.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return 1;
    }
    for (i = 0; i < quantidade; i++) {
        printf("\nNome do produto: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0';
        printf("Preco: R$ ");
        scanf("%f", &preco);
        getchar();
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
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%39[^;];%f", nome, &preco) == 2) {
            if (preco <= orcamento) {
                fprintf(possiveis, "%s;%.2f\n", nome, preco);
            }
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
    while (fgets(linha, sizeof(linha), possiveis) != NULL) {
        if (sscanf(linha, "%39[^;];%f", nome, &preco) == 2) {
            printf("%s - R$ %.2f\n", nome, preco);
        }
    }
    fclose(possiveis);

    return 0;
}
