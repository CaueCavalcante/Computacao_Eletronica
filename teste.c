#include <stdio.h>

float calcular_media(float p1, p2, lista) {
    return (p1+p2)*0.4+lista*0.2;
}
float calcular_recuperacao(float media, float recuperacao) {
    return (media+recuperacao)/2;
}
float fechar_disciplina(char nome_cadeira[]) {
    float p1, p2, lista, media, nota_recuperacao, media_final;
    printf("\n--- Notas de %s ---\n", nome_cadeira);
    printf("digite a nota na p1: ");
    scanf("%f", &p1);
    printf("digite a nota na p2: ");
    scanf("%f", &p2);
    printf("digite a nota na lista: ");
    scanf("%f", &lista);
    media = calcular_media(p1, p2, lista);
    printf("media parcial: %.2f\n", media);
    if (media < 7.0 && media >= 3) {
        printf("aluno em recuperacao! digite a nota da recuperacao: ");
        scanf("%f", &nota_recuperacao);
        media_final = calcular_recuperacao(media, nota_recuperacao);
        return media_final;
    }
    return media;
}
int main () {
    float mediaF, mediaP, mediaD, mediaH;
    mediaF=fechar_disciplina("feitico");
    mediaP=fechar_disciplina("porcao");
    mediaD=fechar_disciplina("defesa");
    mediaH=fechar_disciplina("herbologia");
}
