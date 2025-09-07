#include <stdio.h>
#include <stdlib.h>
#include "DinEn_CirOrd_FPA.h"

int main()
{
    Fila f;
    Pacientes dado;
    Pacientes dadoaux;
    int criada=0, opcao, tam, pos;

    do{
        printf(".:: MENU - PACIENTES ::.\n");
        printf("(1)Cria fila\n");
        printf("(2)Verifica se a fila esta vazia\n");
        printf("(3)Insere paciente na fila\n");
        printf("(4)Remove paciente da fila\n");
        printf("(5)Esvazia fila\n");
        printf("(6)Tamanho fila\n");
        printf("(7)Pegar infos do paciente em determinada posicao\n");
        printf("(8)Imprime fila\n");
        printf("(9)Apaga fila\n");
        printf("(10)Sair do programa\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        printf("\n");
        switch(opcao){
        case 1:
            if(!criada){
                f = cria_fila();
                criada = 1;
                printf("Fila criada com sucesso.\n");
            }else{printf("A fila ja foi criada.\n");}
            break;
        case 2:
            if(!criada){printf("Crie a fila primeiro.\n");break;}
            if(fila_vazia(f)) printf("A fila esta vazia.\n");
            else{printf("A fila nao esta vazia.\n");}
            break;
        case 3:
            if(!criada){printf("Crie a fila primeiro.\n");break;}
            printf("Nome: ");
            getchar();
            scanf("%30[^\n]", dado.nome);
            printf("Idade: ");
            scanf("%d", &dado.idade);
            printf("Peso (kg): ");
            scanf("%f", &dado.peso);
            printf("Altura (m): ");
            scanf("%f", &dado.altura);
            printf("Tipo de Doenca ('C'-Cardiaca, 'N'-Neurologica, 'S'-Sanguinea ou 'R'-Respiratoria): ");
            scanf(" %c", &dado.tipoDoenca);
            printf("Gravidade da Doenca (Sendo 1 a mais grave e 5 a menos grave): ");
            scanf("%d", &dado.gravidadeDoenca);
            if(insere_ord(&f, dado)){printf("Paciente cadastrado.\n");}
            else{printf("Erro ao cadastrar paciente.\n");}
            break;
        case 4:
            if(!criada){printf("Crie a fila primeiro.\n");break;}
            if(remove_ini(&f, &dadoaux)){printf("O paciente removido foi: %s | %d | %.2fkg | %.2fm | Tipo de Doenca: %c | Gravidade da Doenca: %d.\n", dadoaux.nome, dadoaux.idade, dadoaux.peso, dadoaux.altura, dadoaux.tipoDoenca, dadoaux.gravidadeDoenca);}
            else{printf("Erro ao remover paciente.\n");}
            break;
        case 5:
            if(!criada){printf("Crie a fila primeiro.\n");break;}
            if(esvazia_fila(&f)){printf("Fila esvaziada.\n");}
            else{printf("Erro ao esvaziar a fila.\n");}
            break;
        case 6:
            if(!criada){printf("Crie a fila primeiro.\n");break;}
            if(tamanho_fila(f, &tam)){printf("O tamanho da fila eh: %d.\n", tam);}
            else{printf("Erro ao encontrar o tamanho da fila.\n");}
            break;
        case 7:
            if(!criada){printf("Crie a fila primeiro.\n");break;}
            printf("Informe a posicao: ");
            scanf("%d", &pos);
            if(get_elem_pos(f, pos, &dadoaux)){printf("Na posicao %d da fila: %s | %d | %.2fkg | %.2fm | Tipo de Doenca: %c | Gravidade da Doenca: %d.\n", pos, dadoaux.nome, dadoaux.idade, dadoaux.peso, dadoaux.altura, dadoaux.tipoDoenca, dadoaux.gravidadeDoenca);}
            else{printf("Erro ao encontrar paciente na referida posicao.\n");}
            break;
        case 8:
            if(!criada){printf("Crie a fila primeiro.\n");break;}
            if(fila_vazia(f)){printf("Fila vazia.\n");break;}
            tamanho_fila(f, &tam);
            printf("Fila:\n");
            for(int i = 1; i <= tam; i++){
                get_elem_pos(f, i, &dadoaux);
                printf("%d): %s | %d | %.2fkg | %.2fm | Tipo de Doenca: %c | Gravidade da Doenca: %d.\n", i, dadoaux.nome, dadoaux.idade, dadoaux.peso, dadoaux.altura, dadoaux.tipoDoenca, dadoaux.gravidadeDoenca);
            }break;
        case 9:
            if(!criada){printf("Crie a fila primeiro.\n");break;}
            if(apaga_fila(&f)){printf("Fila apagada.\n"); criada=0;}
            else{printf("Erro ao apagar a fila.\n");}
            break;
        case 10:
            break;
        default: printf("Escolha invalida.\n");}printf("\n");
    }while(opcao != 10);

    system("pause");
    return 0;
}

