#include <stdio.h>
int main () {
    int numero;
    char continuar;
    do {
        printf("digite um numero: ");
        scanf("%d", &numero);
        if (numero%2 == 0) {
            printf("seu numero eh par");
        }
        else {
            printf("seu numero eh impar");
        }
        do {
            printf("\npara continuar digite 's', caso contrario digite 'n': ");
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N') {
                printf("erro: digite apenas 's' para continuar ou 'n' para fechar o programa.\n\n");
            }
        } 
        while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');
    }
    while (continuar =='s' || continuar == 'S');
    return 0;
}
