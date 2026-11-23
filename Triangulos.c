#include <stdio.h>
int main () {
    float l1, l2, l3;
    printf("digite o modulo dos 3 lados de um triangulo: ");
    scanf("%f %f %f", &l1, &l2, &l3);
    if ((l1+l2)<=l3 || (l1+l3)<=l2 || (l2+l3)<=l1) {
        printf("isso nao forma um triangulo");
    }
    else if (l1==l2 && l2==l3) {
        printf("isso eh um triangulo equilatero");
    }
    else if (l1==l2 || l2==l3 || l1==l3) {
        printf("isso eh um triangulo isoceles");
    }
    else {
        printf("isso eh um triangulo escaleno");
    }
}
