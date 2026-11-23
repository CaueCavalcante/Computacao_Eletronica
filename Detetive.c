#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define QTD_NOMES 6
#define QTD_CRIMINOSOS 5
#define MAX_LEN 100

int ler_nome_valido(char *destino, int tamanho, int indice) {
    while (1) {
        printf("Digite o %do nome: ", indice + 1);
        if (fgets(destino, tamanho, stdin) == NULL) {
            return 0;
        }

        destino[strcspn(destino, "\n")] = '\0';

        int tem_conteudo = 0;
        for (int i = 0; destino[i] != '\0'; i++) {
            if (!isspace((unsigned char)destino[i])) {
                tem_conteudo = 1;
                break;
            }
        }

        if (tem_conteudo) {
            return 1;
        }
        printf("Nome vazio nao e aceito! Tente novamente.\n");
    }
}

int nomes_iguais(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (tolower((unsigned char)a[i]) != tolower((unsigned char)b[i])) {
            return 0;
        }
        i++;
    }
    return a[i] == '\0' && b[i] == '\0';
}

int main() {
    const char *criminosos[QTD_CRIMINOSOS] = {
        "Kurou Otoharada",
        "Takuo Shibuimaru",
        "Kiichiro Osoreda",
        "Lind L. Tailor",
        "Naoki Kamoda"
    };

    char nomes_digitados[QTD_NOMES][MAX_LEN];
    char encontrados[QTD_NOMES][MAX_LEN];
    int total_encontrados = 0;

    for (int i = 0; i < QTD_NOMES; i++) {
        ler_nome_valido(nomes_digitados[i], MAX_LEN, i);

        int achou = 0;
        for (int j = 0; j < QTD_CRIMINOSOS; j++) {
            if (nomes_iguais(nomes_digitados[i], criminosos[j])) {
                achou = 1;
                break;
            }
        }

        if (achou) {
            printf("Light: Este nome está na lista de criminosos!\n\n");
            strcpy(encontrados[total_encontrados], nomes_digitados[i]);
            total_encontrados++;
        } else {
            printf("Light: O L não perceberá caso eu coma mais uma batatinha\n\n");
        }
    }

    if (total_encontrados == QTD_NOMES) {
        printf("Todos os nomes são de criminosos conhecidos.\n");
    } else if (total_encontrados == 0) {
        printf("Nenhum dos nomes está na lista de criminosos.\n");
    } else {
        printf("Nomes encontrados: ");
        for (int i = 0; i < total_encontrados; i++) {
            printf("%s", encontrados[i]);
            if (i < total_encontrados - 1) {
                printf(", ");
            }
        }
        printf(".\n");
    }

    printf("Total: %d de %d nomes encontrados.\n", total_encontrados, QTD_NOMES);

    return 0;
}
