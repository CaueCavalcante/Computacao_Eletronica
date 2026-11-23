#include <stdio.h>

int main () {
    int nota, n = 0;
    float media = 0;
    float n5=0, n4=0, n3=0, n2=0, n1=0;
    while (nota != 0) {
        printf("digite uma nota de 1 a 5, ou digite 0 para encerrar o programa: ");
        scanf("%d", &nota);
        if (nota >= 1 && nota <=5) {
            switch (nota) {
                case 5:
                n5++; break;
                case 4:
                n4++; break;
                case 3:
                n3++; break;
                case 2:
                n2++; break;
                case 1:
                n1++; break;
            }
            media+=nota;
            n++;
        }
        else if (nota == 0) {
        }
        else {
            printf("INVALIDO\n");
        }
    }
    media/=n;
    printf("media das notas: %.1f\n", media);
    printf("quantidade de avaliacoes: %d\n", n);
    printf("---Porcentagem de avaliacoes em cada nota---\n");
    printf("nota 5: %.2f%\n", n5*100/n);
    printf("nota 4: %.2f%\n", n4*100/n);
    printf("nota 3: %.2f%\n", n3*100/n);
    printf("nota 2: %.2f%\n", n2*100/n);
    printf("nota 1: %.2f%\n", n1*100/n);
    return 0;
}
