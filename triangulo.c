#include <stdio.h>

int main () {
    int base, altura, i, j;
    printf("digite um valor para a base do triangulo: ");
    scanf("%d", &base);
    printf("digite um valor para a altura do triangulo: ");
    scanf("%d", &altura);
    for (i = 0; i < altura; i++) {
        for (j = 0; j <= i; j++){
            printf("%d ", base+j);
        }
        printf("\n");
    }
    i--;
    for (i; i >= 0; i--) {
        for (j=0; j < i; j++) {
            printf("%d ", base+j);
        }
        printf("\n");
    }
}
