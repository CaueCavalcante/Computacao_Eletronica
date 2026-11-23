#include <stdio.h>

float calcular_media () {
    float p1, p2, lista, media;
    printf("Nota da Prova 1: ");
    scanf("%f", &p1);
    printf("Nota da Prova 2: ");
    scanf("%f", &p2);
    printf("Nota da Lista de Exercicios: ");
    scanf("%f", &lista);
    media = (p1 + p2) * 0.4 + (lista * 0.2);
    return media;
}
float calcular_recuperacao(float media_antiga) {
    float rec, nova_media;
    printf("Nota da Recuperacao: ");
    scanf("%f", &rec);
    nova_media = (media_antiga + rec) / 2;
    return nova_media;
}
int main() {
    float media_feiticos, media_pocoes, media_defesa, media_herbologia, cr;
    printf("--- COLETANDO NOTAS ---\n");
    printf("\nDisciplina: Feiticos\n");
    media_feiticos = calcular_media();
    printf("\nDisciplina: Pocoes\n");
    media_pocoes = calcular_media();
    printf("\nDisciplina: Defesa Contra as Artes das Trevas\n");
    media_defesa = calcular_media();
    printf("\nDisciplina: Herbologia\n");
    media_herbologia = calcular_media();
    cr = (media_feiticos + media_pocoes + media_defesa + media_herbologia) / 4;
    if (media_feiticos >= 7 && media_pocoes >= 7 && media_defesa >= 7 && media_herbologia >= 7) {
        printf("\nParabens Harry, voce passou! 100 pontos para a Grifinoria!\n");
        printf("CR: %.2f\n", cr);
    }
    else {
        printf("\n--- RECUPERACAO ---\n");
        if (media_feiticos < 7) {
            printf("\nFeiticos (Media anterior: %.2f)\n", media_feiticos);
            media_feiticos = calcular_recuperacao(media_feiticos);
        }
        if (media_pocoes < 7) {
            printf("\nPocoes (Media anterior: %.2f)\n", media_pocoes);
            media_pocoes = calcular_recuperacao(media_pocoes);
        }
        if (media_defesa < 7) {
            printf("\nDefesa Contra as Artes das Trevas (Media anterior: %.2f)\n", media_defesa);
            media_defesa = calcular_recuperacao(media_defesa);
        }
        if (media_herbologia < 7) {
            printf("\nHerbologia (Media anterior: %.2f)\n", media_herbologia);
            media_herbologia = calcular_recuperacao(media_herbologia);
        }
        cr = (media_feiticos + media_pocoes + media_defesa + media_herbologia) / 4.0;
        printf("\nRecuperacao: CR Final: %.2f\n", cr);
        if (media_feiticos >= 5 && media_pocoes >= 5 && media_defesa >= 5 && media_herbologia >= 5) {
            printf("Harry, apos muito esforco voce conseguiu passar! 50 pontos para a Grifinoria!\n");
        }
        else {
            printf("Harry, voce reprovou e tera que repetir o ano! -100 pontos para a Grifinoria!\n");
        }
    }
    return 0;
}
