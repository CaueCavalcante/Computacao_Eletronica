#include <stdio.h>
int exibe_menu () {
    int escolha;
    printf("\n===MENU DO APLICATIVO===\n");
    printf("\n1 - Consultar saldo\n");
    printf("2 - Fazer recarga via Pix\n");
    printf("3 - Chamar corrida\n");
    printf("4 - Sair do app\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &escolha);
    return escolha;
}
float fazer_recarga(float saldo_atual) {
    float valor;
    printf("Digite o valor da recarga via Pix: R$");
    scanf("%f", &valor);
    if (valor > 0) {
        saldo_atual+=valor;
        printf("Recarga realizada com sucesso! Saldo atualizado\n");
    }
    else {
        printf("Valor invalido para recarga\n");
    }
    return saldo_atual;
}
float pagar_corrida(float saldo_atual) {
    float valor;
    printf("Digite o valor da corrida: R$");
    scanf("%f", &valor);
    if (saldo_atual < valor) {
        printf("Erro: Saldo insuficiente\n");
    }
    else {
        saldo_atual-=valor;
        printf("Pagamento da corrida efetivado com sucesso\n");
        printf("Seu saldo atual: R$ %.2f\n", saldo_atual);
    }
    return saldo_atual;
}
int main () {
    float saldo = 0;
    int opcao;
    do {
        opcao = exibe_menu();
        switch (opcao) {
            case 1:
            printf("Seu saldo: R$ %.2f\n", saldo);
            break;
            case 2:
            saldo = fazer_recarga(saldo);
            break;
            case 3:
            saldo = pagar_corrida(saldo);
            break;
            case 4:
            printf("Fechando programa...");
            break;
            default:
            printf("Opção invalida digite um numero entre 1 e 4\n");
        }
    }
    while (opcao != 4);
    return 0;
}
