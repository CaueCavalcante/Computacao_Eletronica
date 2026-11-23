#include <stdio.h>
int main () {
    int numero, X, Y, Z;
    printf("digite um numero de 3 digitos: ");
    scanf("%d", &numero);
    X = numero/100;
    Y = (numero%100)/10;
    Z = numero%10;
    printf("%d\n%d\n%d\n", X, Y, Z);
}
