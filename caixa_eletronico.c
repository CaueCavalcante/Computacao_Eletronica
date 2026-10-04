#include <stdio.h>

int main () {
    int saque, n100, n50, n20, n10, n5, n1;
    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        printf("digite um valor inteiro e positivo para o seu saque: ");
        scanf("%d", &saque);
        n100=saque/100;
        n50=(saque%100)/50;
        n20=(saque%50)/20;
        n10=((saque%50)%20)/10;
        n5=(saque%10)/5;
        n1=(saque%5)/1;
        printf("notas de 100: %d\nnotas de 50: %d\nnotas de 20: %d\nnotas de 10: %d\nnotas de 5: %d\nnotas de 1: %d\n", n100, n50, n20, n10, n5, n1);
        printf("voce deseja continuar? se sim, digite 's': ");
        scanf(" %c", &continuar);
    }
}
