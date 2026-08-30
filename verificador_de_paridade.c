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
        do {
            printf("\ndigite 's' para continuar ou digite 'n' para fechar o programa: ");
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N') {
                printf("erro: voce nao pode digitar nada alem de (s/n).");
            }
        } 
        while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');
    }
    while (continuar =='s' || continuar == 'S');
    return 0;
}
