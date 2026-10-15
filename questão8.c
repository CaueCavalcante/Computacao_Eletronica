#include <stdio.h>

int main() {
    int v[10], i, j, cont, max = 0, num = 0;
    for (i = 0; i < 10; i++) {
        printf("Digite o numero %d/10: ", i + 1);
        scanf("%d", &v[i]);
    }
    printf("\nVetor: ");
    for (i = 0; i < 10; i++) printf("%d ", v[i]);
    printf("\n\n");
    for (i = 0; i < 10; i++) {
        cont = 0;
        for (j = 0; j < i; j++) if (v[i] == v[j]) cont++;
        if (cont > 0) continue;
        cont = 0;
        for (j = 0; j < 10; j++) if (v[i] == v[j]) cont++;
        if (cont > 1) {
            printf("O numero %d repetiu %d vezes.\n", v[i], cont);
            if (cont > max) { max = cont; num = v[i]; }
        }
    }
    if (max > 0) printf("\n=> Mais repetido: %d (%d vezes).\n", num, max);
     return 0;
}
