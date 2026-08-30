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
        do {
            printf("\npara continuar digite 's', caso contrario digite 'n': ");
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N') {
                printf("erro: digite apenas 's' para continuar ou 'n' para fechar o programa.\n\n");
            }
        } 
        while (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');
    }
    while (continuar == 's' || continuar == 'S');
    return 0;
}
