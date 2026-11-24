#include <stdio.h>
#include <string.h>

struct Funcionarios {
    char nome[50];
    char cargo[30];
    float salario_base;
    int avaliacao;
};

int main() {
    struct Funcionarios lista[5];
    float maior_salario = 0.0f;
    char cargo_maior_salario[30] = "";

    for (int i = 0; i < 5; i++) {
        printf("\n--- Funcionario %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %49[^\n]", lista[i].nome);
        printf("Cargo: ");
        scanf(" %29[^\n]", lista[i].cargo);
        printf("Salario base: ");
        scanf("%f", &lista[i].salario_base);
        printf("Avaliacao (1 a 5): ");
        scanf("%d", &lista[i].avaliacao);
    }

    printf("\n=== Resumo ===\n");
    for (int i = 0; i < 5; i++) {
        if (lista[i].avaliacao == 5) {
            lista[i].salario_base *= 1.2f;
        } else if (lista[i].avaliacao == 4) {
            lista[i].salario_base *= 1.1f;
        }

        if (i == 0 || lista[i].salario_base > maior_salario) {
            maior_salario = lista[i].salario_base;
            strcpy(cargo_maior_salario, lista[i].cargo);
        }

        printf("%s | %s | R$ %.2f | Nota: %d\n",
               lista[i].nome,
               lista[i].cargo,
               lista[i].salario_base,
               lista[i].avaliacao);
    }

    printf("\nCargo do maior salario: %s (R$ %.2f)\n", cargo_maior_salario, maior_salario);

    return 0;
}
