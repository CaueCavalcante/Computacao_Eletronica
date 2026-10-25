#include <stdio.h>

int main () {
    int Matriz[3][5];
    int Gabarito[5];
    int aluno, questao;
    for (questao = 0; questao<5; questao++) {
        printf("Digite o gabarito da questão (%d): ", questao + 1);
        scanf("%d", &Gabarito[questao]);
    }
    for (aluno = 0; aluno<3; aluno++) {
        for (questao = 0; questao < 5; questao++) {
            printf("Digite o elemento (%d/%d) da matriz: ", aluno, questao);
            scanf("%d", &Matriz[aluno][questao]);
        }
    }
}
