#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TOTAL_VAGAS 20

typedef struct {
    char placa[9];
    char modelo[40];
    int horaEntrada;
    int minutoEntrada;
    int vaga;
    int ocupada;
} Veiculo;

int totalEntradas = 0;
int totalSaidas = 0;
float totalArrecadado = 0;

int compararPlacas(char placa1[], char placa2[]) {
    int i = 0;
    while (placa1[i] != '\0' && placa2[i] != '\0') {
        if (toupper(placa1[i]) != toupper(placa2[i])) {
            return 0;
        }
        i++;
    }
    return placa1[i] == '\0' && placa2[i] == '\0';
}

int buscarVeiculo(Veiculo vagas[], char placa[]) {
    for (int i = 0; i < TOTAL_VAGAS; i++) {
        if (vagas[i].ocupada == 1 &&
            compararPlacas(vagas[i].placa, placa)) {
            return i;
        }
    }
    return -1;
}

void registrarEntrada(Veiculo vagas[]) {
    char placa[9];
    char modelo[40];
    int hora, minuto;
    int vagaLivre = -1;
    printf("\n===== REGISTRAR ENTRADA =====\n");
    printf("Digite a placa: ");
    scanf(" %8s", placa);
    if (buscarVeiculo(vagas, placa) != -1) {
        printf("Esta placa ja esta cadastrada!\n");
        return;
    }
    for (int i = 0; i < TOTAL_VAGAS; i++) {
        if (vagas[i].ocupada == 0) {
            vagaLivre = i;
            break;
        }
    }
    if (vagaLivre == -1) {
        printf("Estacionamento lotado!\n");
        return;
    }
    printf("Digite o modelo: ");
    scanf(" %39[^\n]", modelo);
    printf("Hora de entrada (0 a 23): ");
    scanf("%d", &hora);
    printf("Minuto de entrada (0 a 59): ");
    scanf("%d", &minuto);
    if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59) {
        printf("Horario invalido!\n");
        return;
    }
    strcpy(vagas[vagaLivre].placa, placa);
    strcpy(vagas[vagaLivre].modelo, modelo);
    vagas[vagaLivre].horaEntrada = hora;
    vagas[vagaLivre].minutoEntrada = minuto;
    vagas[vagaLivre].vaga = vagaLivre + 1;
    vagas[vagaLivre].ocupada = 1;
    totalEntradas++;
    printf("\nVeiculo cadastrado com sucesso!\n");
    printf("Vaga atribuida: %d\n", vagaLivre + 1);
}

void registrarSaida(Veiculo vagas[]) {
    char placa[9];
    int hora, minuto;
    int indice;
    int entrada, saida, permanencia;
    int horas, minutos;
    int horasAdicionais;
    float valor;
    printf("\n===== REGISTRAR SAIDA =====\n");
    printf("Digite a placa: ");
    scanf(" %8s", placa);
    indice = buscarVeiculo(vagas, placa);
    if (indice == -1) {
        printf("VEICULO NAO ENCONTRADO!\n");
        return;
    }
    printf("Hora de saida (0 a 23): ");
    scanf("%d", &hora);
    printf("Minuto de saida (0 a 59): ");
    scanf("%d", &minuto);
    if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59) {
        printf("Horario invalido!\n");
        return;
    }
    entrada = vagas[indice].horaEntrada * 60 + vagas[indice].minutoEntrada;
    saida = hora * 60 + minuto;
    if (saida <= entrada) {
        printf("O horario de saida deve ser posterior a entrada!\n");
        return;
    }
    permanencia = saida - entrada;
    horas = permanencia / 60;
    minutos = permanencia % 60;
    if (permanencia <= 60) {
        valor = 5.00;
    } else {
        horasAdicionais = (permanencia - 60 + 59) / 60;
        valor = 5.00 + (horasAdicionais * 3.00);
    }
    printf("\nVeiculo: %s\n", vagas[indice].modelo);
    printf("Vaga: %d\n", vagas[indice].vaga);
    printf("Tempo de permanencia: %dh %dmin\n",horas, minutos);
    printf("Valor a pagar: R$ %.2f\n", valor);
    printf("Saida registrada com sucesso!\n");
    totalSaidas++;
    totalArrecadado += valor;
    vagas[indice].ocupada = 0;
}

void listarVeiculos(Veiculo vagas[]) {
    int ocupadas = 0;
    printf("\n======= VEICULOS ESTACIONADOS =======\n");
    for (int i = 0; i < TOTAL_VAGAS; i++) {
        if (vagas[i].ocupada == 1) {
            printf("Vaga %d | %s | %s | %02d:%02d\n", vagas[i].vaga, vagas[i].placa, vagas[i].modelo, vagas[i].horaEntrada, vagas[i].minutoEntrada);
            ocupadas++;
        }
    }
    printf("\nVagas ocupadas: %d\n", ocupadas);
    printf("Vagas livres: %d\n", TOTAL_VAGAS - ocupadas);
    printf("=====================================\n");
}

void consultarVeiculo(Veiculo vagas[]) {
    char placa[9];
    int indice;
    printf("\n===== CONSULTAR VEICULO =====\n");
    printf("Digite a placa: ");
    scanf(" %8s", placa);
    indice = buscarVeiculo(vagas, placa);
    if (indice == -1) {
        printf("VEICULO NAO ENCONTRADO!\n");
    } else {
        printf("\nVeiculo encontrado!\n");
        printf("Placa: %s\n", vagas[indice].placa);
        printf("Modelo: %s\n", vagas[indice].modelo);
        printf("Vaga: %d\n", vagas[indice].vaga);
        printf("Horario de entrada: %02d:%02d\n", vagas[indice].horaEntrada, vagas[indice].minutoEntrada);
    }
}

void exibirResumo(Veiculo vagas[]) {
    int ocupadas = 0;
    for (int i = 0; i < TOTAL_VAGAS; i++) {
        if (vagas[i].ocupada == 1) {
            ocupadas++;
        }
    }
    printf("\n========== RESUMO ==========\n");
    printf("Vagas ocupadas: %d\n", ocupadas);
    printf("Vagas livres: %d\n", TOTAL_VAGAS - ocupadas);
    printf("Total de entradas: %d\n", totalEntradas);
    printf("Total de saidas: %d\n", totalSaidas);
    printf("Valor arrecadado: R$ %.2f\n", totalArrecadado);
    printf("============================\n");
}

int main() {
    Veiculo vagas[TOTAL_VAGAS] = {0};
    int opcao;
    do {
        printf("\n========== ESTACIONAMENTO ==========\n");
        printf("1 - Registrar entrada de veiculo\n");
        printf("2 - Registrar saida de veiculo\n");
        printf("3 - Listar veiculos estacionados\n");
        printf("4 - Consultar veiculo pela placa\n");
        printf("5 - Exibir resumo do estacionamento\n");
        printf("6 - Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                registrarEntrada(vagas);
                break;
            case 2:
                registrarSaida(vagas);
                break;
            case 3:
                listarVeiculos(vagas);
                break;
            case 4:
                consultarVeiculo(vagas);
                break;
            case 5:
                exibirResumo(vagas);
                break;
            case 6:
                printf("\nEncerrando o programa... \n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente\n");
        }
    } while (opcao != 6);

    return 0;
}
