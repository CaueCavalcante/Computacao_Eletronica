#include <stdio.h>
int main() {
    float IMC, altura, peso;
    char continuar;
    do  {
        printf("digite seu peso em (kg): ");
        scanf("%f", &peso);
        printf("digite sua altura em (m): ");
        scanf("%f", &altura);
        IMC = peso/(altura*altura);
        printf("seu IMC é  %.2f", IMC);
        do {
            printf("\ndeseja continuar no programa? (s/n): ");
            scanf(" %c", &continuar);
            if (continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N') {
                printf("opcao invalida, digite apenas 's' ou 'n'.");
            }
        }
        while(continuar != 's' && continuar != 'S' && continuar != 'n' && continuar != 'N');
    }
    while(continuar == 's' || continuar == 'S');
    return 0;
}
