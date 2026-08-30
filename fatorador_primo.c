#include <stdio.h>
int main() {
    char continuar;
    int numero;
    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &numero);
        if (numero <= 1) {
            printf("A fatoracao por numeros primos exige valores maiores que 1.\n");
        } 
        else {
            printf("Os fatores primos sao: ");
            int divisor = 2;
            while (numero > 1) {
                if (numero % divisor == 0) {
                    printf("%d; ", divisor);
                    numero /= divisor;
                } 
                else {
                    divisor++;
                }
            }
            printf("\n");
        }
        do {
            printf("\nDeseja inserir outro numero? (s/n): ");
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N') {
                printf("Opcao invalida! Digite apenas 's' ou 'n'.\n");
            }
        } while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');
    } while (continuar == 's' || continuar == 'S');
    return 0;
}
