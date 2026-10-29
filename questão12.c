#include <stdio.h>

int cadastrarNumero (int n) {
    printf("Digite um numero: ");
    scanf("%d", &n);
    if (numero < 0 || numero > 12) {
        printf("Numero fora do intervalo para calcular fatorial com int\n");
        return 0;
    }
    return n;
}

int calcularFatorial (int f) {
    for (i = 1; i <= numero; i++) {
        fatorial *= i;
    }
    printf("Fatorial: %d\n", fatorial);
    return f;
}

int verificarNumeroPrimo(int p) {
    if (numero < 2) {
        primo = 0;
    }
    for (i = 2; i < numero; i++) {
        if (numero % i == 0) {
            primo = 0;
            break;
        }
    }
    printf("Primo: %s\n", primo ? "Sim" : "Nao");
}

int somarAlgarismos (int soma) {
    int temp = numero;
    while (temp != 0) {
        somaAlgarismos += temp % 10;
        temp /= 10;
    }
    printf("Soma dos algarismos: %d\n", somaAlgarismos);
}

int tabuada (int n) {
    int i;
    for (i = 1; i <= 10; i++){
        printf("%d x %d = %d", n, i, n*i);
    }
}

int main(void) {
    int numero, i, opcao, fatorial = 1, primo = 1, quantidadeAlgarismos = 0, somaAlgarismos = 0;
    while (opcao = 6) {
        printf("1. Cadastrar um numero\n");
        printf("2. Calcular o fatorial do numero cadastrado\n");
        printf("3. Verificar se o numero cadastrado eh primo\n");
        printf("4. Calcular a soma dos algarismos do numero cadastrado\n");
        printf("5. Exibir a tabuada do numero cadastrado\n");
        printf("6. Sair do programa\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
            numero = cadastrarNumero(numero);
            break;
            case 2:
            fatorial = calcularFatorial(fatorial);
            break;
            case 3:
            primo = verificarNumeroPrimo;
            break;
            case 4:
            somaAlgarismos = somarAlgarismos(somaAlgarismos);
            break;
            case 5:
            tabuada(numero);
            break
            case 6:
            printf("Fechando programa...");
        }
    }
    return 0;
}
