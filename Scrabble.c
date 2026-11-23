#include <stdio.h>
#include <ctype.h>

int main() {
    char palavra[50];
    int pontuacao = 0;

    printf("Digite uma palavra: ");
    scanf("%49s", palavra);

    for (int i = 0; palavra[i] != '\0'; i++) {
        char letra = toupper((unsigned char)palavra[i]);

        switch (letra) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
            case 'L': case 'N': case 'R': case 'S': case 'T':
                pontuacao += 1;
                break;

            case 'D': case 'G':
                pontuacao += 2;
                break;

            case 'B': case 'C': case 'M': case 'P':
                pontuacao += 3;
                break;

            case 'F': case 'H': case 'V': case 'W': case 'Y':
                pontuacao += 4;
                break;

            case 'K':
                pontuacao += 5;
                break;

            case 'J': case 'X':
                pontuacao += 8;
                break;

            case 'Q': case 'Z':
                pontuacao += 10;
                break;
        }
    }

    printf("%s: %d pontos\n", palavra, pontuacao);

    return 0;
}
