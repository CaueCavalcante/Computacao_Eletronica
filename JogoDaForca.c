#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAM 11
#define CHANCES_INICIAIS 6

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void converter_maiuscula(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

int main() {
    int opcao;
    int vitorias = 0;
    int derrotas = 0;
    char palavra_secreta[MAX_TAM];
    char palavra_descoberta[MAX_TAM];
    char tentativa[MAX_TAM];
    
    while (1) {
        printf("\n=== JOGO DA FORCA ===\n");
        printf("1. Comecar Jogo\n");
        printf("2. Sair\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            printf("Entrada invalida! Digite 1 ou 2.\n");
            continue;
        }
        limpar_buffer();
        
        if (opcao == 2) {
            printf("\n=== FIM DE JOGO ===\n");
            printf("Vitorias: %d\n", vitorias);
            printf("Derrotas: %d\n", derrotas);
            printf("Obrigado por jogar! Encerrando o programa...\n");
            break;
        } 
        else if (opcao == 1) {
            printf("\nDigite a palavra secreta (maximo 10 caracteres): ");
            scanf("%10s", palavra_secreta);
            limpar_buffer();
            converter_maiuscula(palavra_secreta);
            
            int tamanho = strlen(palavra_secreta);
            int chances = CHANCES_INICIAIS;
            int venceu = 0;
            
            for (int i = 0; i < tamanho; i++) {
                palavra_descoberta[i] = '_';
            }
            palavra_descoberta[tamanho] = '\0';
            
            while (chances > 0 && !venceu) {
                printf("\nChances restantes: %d\n", chances);
                printf("Palavra: ");
                for (int i = 0; i < tamanho; i++) {
                    printf("%c ", palavra_descoberta[i]);
                }
                printf("\n");
                
                printf("Digite uma letra ou arrisque a palavra inteira: ");
                scanf("%10s", tentativa);
                limpar_buffer();
                converter_maiuscula(tentativa);
                int tam_tentativa = strlen(tentativa);
                if (tam_tentativa == 1) {
                    char letra = tentativa[0];
                    int acertou_letra = 0;
                    for (int i = 0; i < tamanho; i++) {
                        if (palavra_secreta[i] == letra) {
                            palavra_descoberta[i] = letra;
                            acertou_letra = 1;
                        }
                    }
                    
                    if (!acertou_letra) {
                        printf("A letra '%c' nao existe na palavra!\n", letra);
                        chances--;
                    } else {
                        printf("Boa! A letra '%c' esta na palavra.\n", letra);
                    }
                    
                    if (strcmp(palavra_secreta, palavra_descoberta) == 0) {
                        venceu = 1;
                    }
                } 
                else {
                    if (strcmp(palavra_secreta, tentativa) == 0) {
                        strcpy(palavra_descoberta, palavra_secreta);
                        venceu = 1;
                    } else {
                        int erros_na_palavra = 0;
                        for (int i = 0; tentativa[i] != '\0'; i++) {
                            if (i >= tamanho || tentativa[i] != palavra_secreta[i]) {
                                erros_na_palavra++;
                            }
                        }
                        
                        if (erros_na_palavra == 0) {
                            erros_na_palavra = 1;
                        }
                        printf("Palavra incorreta! Voce perdeu %d chance(s).\n", erros_na_palavra);
                        chances -= erros_na_palavra;
                    }
                }
            }
            
            if (venceu) {
                printf("\nPARABENS! Voce acertou a palavra: %s\n", palavra_secreta);
                vitorias++;
            } else {
                printf("\nVOCE PERDEU! Suas chances acabaram. A palavra era: %s\n", palavra_secreta);
                derrotas++;
            }
        } 
        else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
    
    return 0;
}
