#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tad.h"

#define NUM_BOXES 3

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void exibir_menu() {
    printf("\n--- ESTACIONAMENTO ---\n");
    printf("1. Entrada de Veiculo\n");
    printf("2. Saida de Veiculo\n");
    printf("0. Sair do Sistema\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Fila boxes[NUM_BOXES];
    int i;

    for (i = 0; i < NUM_BOXES; i++) {
        boxes[i] = cria_fila();
        if (boxes[i] == NULL) {
            printf("Erro ao alocar memoria para o box %d.\n", i + 1);
            return 1;
        }
    }

    int opcao;
    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: {
                int lotado = 1;
                for (i = 0; i < NUM_BOXES; i++) {
                    if (!fila_cheia(boxes[i])) {
                        lotado = 0;
                        break;
                    }
                }

                if (lotado) {
                    printf("\nAVISO: Estacionamento lotado!\n");
                    break;
                }

                Carro novo_carro;
                printf("Digite a placa do veiculo: ");
                scanf("%7s", novo_carro.placa);
                limpar_buffer();

                do {
                    printf("Digite o tipo de servico (A - Avulso, M - Mensal): ");
                    scanf(" %c", &novo_carro.tipo_servico);
                    limpar_buffer();
                    novo_carro.tipo_servico = toupper(novo_carro.tipo_servico);
                } while (novo_carro.tipo_servico != 'A' && novo_carro.tipo_servico != 'M');
                int indice_box_alvo = -1;
                int menor_tamanho = 100;

                for (i = 0; i < NUM_BOXES; i++) {
                    if (tamanho(boxes[i]) < menor_tamanho) {
                        menor_tamanho = tamanho(boxes[i]);
                        indice_box_alvo = i;
                    }
                }

                novo_carro.hora_entrada = time(NULL);

                if (insere_fim(boxes[indice_box_alvo], novo_carro)) {
                    printf("\nSUCESSO: Veiculo de placa %s inserido no Box %d.\n", novo_carro.placa, indice_box_alvo + 1);
                    printf("Hora de entrada: %s", ctime(&novo_carro.hora_entrada));
                } else {
                    printf("\nERRO: Nao foi possivel inserir o veiculo.\n");
                }

                break;
            }
            case 2: {
                char placa_saida[MAX_PLACA];
                printf("Digite a placa do veiculo que esta saindo: ");
                scanf("%7s", placa_saida);
                limpar_buffer();

                int encontrado = 0;
                for (i = 0; i < NUM_BOXES && !encontrado; i++) {
                    int tam_atual = tamanho(boxes[i]);
                    if (tam_atual == 0) continue;

                    int j;
                    for (j = 0; j < tam_atual; j++) {
                        Carro carro_temp;
                        remove_inicio(boxes[i], &carro_temp);

                        if (strcmp(carro_temp.placa, placa_saida) == 0) {
                            encontrado = 1;
                            printf("\nVeiculo %s encontrado no Box %d e removido.\n", placa_saida, i + 1);
                            if (carro_temp.tipo_servico == 'A') {
                                time_t hora_saida = time(NULL);
                                printf("Tipo: Avulso. Hora de saida: %s", ctime(&hora_saida));
                            } else {
                                printf("Tipo: Mensal. Cliente mensalista.\n");
                            }
                            break;
                        } else {
                            insere_fim(boxes[i], carro_temp);
                        }
                    }
                }

                if (!encontrado) {
                    printf("\nAVISO: Veiculo de placa %s nao encontrado no estacionamento.\n", placa_saida);
                }
                break;
            }
            case 0: {
                printf("Encerrando o sistema...\n");
                break;
            }
            default: {
                printf("\nOpcao invalida! Tente novamente.\n");
                break;
            }
        }
    } while (opcao != 0);

    for (i = 0; i < NUM_BOXES; i++) {
        apaga_fila(&boxes[i]);
    }

    return 0;
}
