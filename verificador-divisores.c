#include <stdio.h>

int main () {
    char continuar;
    int numero, divisor;
    do {
        printf("digite um numero: ");
        scanf("%d", &numero);
        printf("digite o seu divisor: ");
        scanf("%d", &divisor);
        if (numero%divisor == 0) {
            printf("%d eh divisivel por %d", numero, divisor);
        }
        else {
            printf("%d nao eh divisivel por %d", numero, divisor);
        }
        printf("\nDigite 's' caso queira continuar no programa: ");
        scanf(" %c", &continuar);
    }
    while (continuar == 's' || continuar == 'S');
    return 0;
}
