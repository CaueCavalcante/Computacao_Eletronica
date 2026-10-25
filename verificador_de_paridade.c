#include <stdio.h>

int main () {
    int numero;
    char continuar;
    do {
        printf("digite um numero: ");
        scanf("%d", &numero);
        if (numero%2 == 0) {
            printf("%d eh um numero par", numero);
        }
        else {
            printf("%d eh um numero impar", numero);
        }
        printf("\nDigite 's' se deseja continuar no programa: ");
        scanf(" %c", &continuar);
    }
    while (continuar =='s' || continuar == 'S');
    return 0;
}
