#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[40];
    float peso;
    int usado;
} Item;

int main() {
    Item mochila[6];
    FILE *arquivo;
    int i, totalItens = 6, superados = 0;
    float pesoTotal = 0;
    char escolhido[40], obstaculos[3][15] = {"Rio", "Montanha", "Castelo"};
    char resultado[20];
    arquivo = fopen("mochila.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir mochila.txt!\n");
        return 1;
    }
    for (i = 0; i < 6; i++) {
        do {
            printf("Nome do item: ");
            scanf("%39s", mochila[i].nome);
            if (strlen(mochila[i].nome) == 0)
                printf("Nome invalido!\n");
        } while (strlen(mochila[i].nome) == 0);
        do {
            printf("Peso (1 a 5 kg): ");
            scanf("%f", &mochila[i].peso);
            if (mochila[i].peso < 1 || mochila[i].peso > 5)
                printf("Peso invalido!\n");
        } while (mochila[i].peso < 1 || mochila[i].peso > 5);
        mochila[i].usado = 0;
        fprintf(arquivo, "%s %.2f\n",
                mochila[i].nome, mochila[i].peso);
    }
    fclose(arquivo);
    arquivo = fopen("mochila.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir mochila.txt!\n");
        return 1;
    }
    for (i = 0; i < 6; i++) {
        fscanf(arquivo, "%39s %f", mochila[i].nome, &mochila[i].peso);
        mochila[i].usado = 0;
    }
    fclose(arquivo);
    while (1) {
        pesoTotal = 0;
        for (i = 0; i < totalItens; i++)
            pesoTotal += mochila[i].peso;
        if (pesoTotal <= 10)
            break;
        int maior = 0;
        for (i = 1; i < totalItens; i++)
            if (mochila[i].peso > mochila[maior].peso)
                maior = i;
        printf("Mochila: Deixando %s para tras!\n", mochila[maior].nome);
        for (i = maior; i < totalItens - 1; i++)
            mochila[i] = mochila[i + 1];
        totalItens--;
    }
    arquivo = fopen("diario.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir diario.txt!\n");
        return 1;
    }
    for (i = 0; i < 3; i++) {
        printf("\nObstaculo: %s\n", obstaculos[i]);
        printf("Qual item deseja usar? ");
        scanf("%39s", escolhido);
        int encontrado = -1;
        for (int j = 0; j < totalItens; j++) {
            if (strcmp(mochila[j].nome, escolhido) == 0) {
                encontrado = j;
                break;
            }
        }
        if (encontrado == -1) {
            printf("Mochila: Nao encontrei esse item!\n");
            strcpy(resultado, "falhou");
        }
        else if (mochila[encontrado].usado == 1) {
            printf("Mochila: Esse item ja foi usado!\n");
            strcpy(resultado, "falhou");
        }
        else {
            printf("Dora usou %s. Obstaculo superado!\n", escolhido);
            mochila[encontrado].usado = 1;
            superados++;
            strcpy(resultado, "superado");
        }
        fprintf(arquivo, "%s: %s - %s\n", obstaculos[i], escolhido, resultado);
    }
    fclose(arquivo);
    arquivo = fopen("relatorio.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir relatorio.txt!\n");
        return 1;
    }
    fprintf(arquivo, "ITENS NA MOCHILA:\n");
    pesoTotal = 0;
    for (i = 0; i < totalItens; i++) {
        fprintf(arquivo, "%s - %.2f kg\n", mochila[i].nome, mochila[i].peso);
        pesoTotal += mochila[i].peso;
    }
    fprintf(arquivo, "Peso total: %.2f kg\n", pesoTotal);
    if (superados == 3)
        fprintf(arquivo, "Dora chegou ao Castelo!\n");
    else
        fprintf(arquivo, "Dora nao conseguiu chegar. Superou %d de 3 obstaculos.\n", superados);
    fclose(arquivo);
    arquivo = fopen("diario.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir diario.txt!\n");
        return 1;
    }
    char linha[100];
    printf("\n===== DIARIO DA VIAGEM =====\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
        printf("%s", linha);
    fclose(arquivo);

    return 0;
}
