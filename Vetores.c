#include <stdio.h>
#include <math.h>

int main  () {
    int i, j;
    printf("Quantos valores voce deseja inserir?: ");
    scanf("%d", &j);
    float v[j], valor, maior, menor, media = 0, desvioPadrao, variancia = 0;
    for (i = 0; i < j; i++){
        printf("Digite um valor de 0 a 100(%d/%d): ", i+1, j);
        scanf("%f", &valor);
        if (valor > 100 || valor < 0){
            printf("Numero invalido");
            i--;
        }
        else {
            v[i] = valor;
            media += v[i];
        }
    }
    media /= j;
    maior = v[0];
    menor = v[0];
    for (i = 0; i < j; i++){
        if (v[i] > maior) {
            maior = v[i];
        }
        if (v[i] < menor) {
            menor = v[i];
        }
        variancia += pow(v[i] - media, 2);
    }
    variancia /= j;
    desvioPadrao = sqrt(variancia);
    printf("Media: %.2f\n", media);
    printf("Maior: %.2f\n", maior);
    printf("Menor: %.2f\n", menor);
    printf("Variancia: %.2f\n", variancia);
    printf("Desvio Padrao: %.2f\n", desvioPadrao);
    return 0;
}
