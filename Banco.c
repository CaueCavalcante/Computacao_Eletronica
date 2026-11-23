#include <stdio.h>

int main () {
    float deposito, saque;
    float saldo = 1000;
    int escolha = -1;
    while (escolha != 0) {
        printf("\n---BANCO---\n");
        printf("1 - Depositar\n2 - Sacar\n3 - Consultar saldo\n0 - Encerrar\n");
        printf("Digite qual acao voce deseja executar: ");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
            printf("Digite um valor para o seu deposito: ");
            scanf("%f", &deposito);
            if (deposito>=0) {
                saldo+=deposito;
            }
            else {
                printf("\nNao sao permitidos valores negativos para o deposito");
            }
            break;
            case 2:
            printf("\nDigite um valor para o seu saque: ");
            scanf("%f", &saque);
            if (saque>saldo) {
                printf("\nO valor do saque nao pode ser maior do que o valor do saldo.");
            }
            else if (saque<0) {
                printf("\nNao sao permitidos valores negativos para o saque.");
            }
            else {
                saldo-=saque;
            }
            break;
            case 3:
            printf("\nseu saldo: %.2f", saldo);
            break;
            case 0:
            printf("volte sempre!");
            break;
        }
    }
    return 0;
}
