#include <stdio.h>

int main () {
	int respostas[3][5];
	int gabarito[5];
	int resultado [3] = { 0, 0, 0 };
	int i, j, MelhorAluno, MaiorNota;
	printf("Digite a nota dos alunos: ");
	for (i = 0; i < 3; i++) {
	    printf("========== Aluno (%d/3) ==========", i + 1);
		for (j = 0; j < 5; j++) {
			printf("\nQuestao %d: ", j + 1);
			scanf("%d", &respostas[i][j]);
			if (respostas[i][j] > 4 || respostas[i][j] < 1) {
			    printf("\nERRO!! Digite um valor inteiro entre 1 e 4\n");
			    j--;
			}
		}
	}
	printf("========== Gabarito ==========\n");
	printf("Digite o Gabarito:\n");
	for (j = 0; j < 5; j++) {
	    printf("\nQuestao %d: ", j + 1);
	    scanf("%d", &gabarito[j]);
	    if (gabarito[j] > 4 || gabarito[j] < 1) {
	        printf("\nERRO!! Digite um valor inteiro entre 1 e 4");
	        j--;
	    }
	}
	for (i = 0; i < 3; i++) {
	   for (j = 0; j < 5; j++) {
	       if (respostas[i][j] == gabarito [j]) resultado[i]++;
	   }
	   if (resultado[i] > resultado[i - 1] && i > 0) {
	       MelhorAluno = i + 1;
	       MaiorNota = resultado[i];
	   }
	   else if (i == 0) {
	       MelhorAluno = 1;
	       MaiorNota = resultado[0];
	   }
	}
	printf("Melhor Resultado: Aluno (%d), Nota(%d)", MelhorAluno, MaiorNota);
	return 0;
}
