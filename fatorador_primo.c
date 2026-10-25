#include <stdio.h>

int main () {
    char continuar;
    int numero;
    do {
        printf("Digite um numero inteiro positivo: ");
        scanf("%d", &numero);
        if (numero <= 1) {
            printf("A fatoracao por numeros primos exige valores maiores que 1.\n");
        } 
        else {
            printf("Os fatores primos de %d sao: ", numero);
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
        }
        printf("Digite 'S' se quiser fatorar outro numero: ");
        scanf(" %c", &continuar);
    }
    while (continuar == 's' || continuar == 'S');
    return 0;
}
