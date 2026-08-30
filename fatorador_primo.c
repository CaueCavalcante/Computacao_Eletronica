#include <stdio.h>
int main() {
    char continuar;
    int numero;
    do {
        printf("digite um numero inteiro positivo: ");
        scanf("%d", &numero);
        if (numero <= 1) {
            printf("a fatoracao por numeros primos exige valores maiores que 1.\n");
        } 
        else {
            printf("os fatores primos de %d sao: ", numero);
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
            printf("deseja inserir outro numero? (s/n): ");
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N') {
                printf("opcao invalida, digite apenas 's' ou 'n'.");
            }
        } while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');
    } while (continuar == 's' || continuar == 'S');
    return 0;
}
