#include "DinEn_CirOrd_FPA.h"
#include <stdlib.h>

struct no{
    Pacientes info;
    struct no *prox;
};

/*Entrada: Nenhuma.
Pré-condição: Nenhuma.
Processo: Cria uma fila vazia (retorna NULL).
Saída: Fila vazia.
Pós-condição: Fila existe mas está vazia.*/
Fila cria_fila(){return NULL;}

/*Entrada: Ponteiro para a fila f.
Pré-condição: Fila deve estar inicializada.
Processo: Verifica se o ponteiro da fila é NULL.
Saída: 1 (verdadeiro) se vazia, 0 (falsa) caso contrário.
Pós-condição: Estrutura da fila não é alterada.*/
int fila_vazia(Fila f){
    if(f == NULL){return 1;}else{return 0;}
}

/*Entrada: Ponteiro para a fila f, paciente elem.
Pré-condição: A fila deve estar inicializada.
Processo:
    -Cria um novo nó.
    -Se fila vazia → insere nó apontando para si mesmo.
    -Caso contrário → percorre até achar posição correta (ordenado por gravidadeDoenca).
    -Ajusta ponteiros para manter circularidade.
Saída: 1 se inserção bem-sucedida, 0 se erro de alocação.
Pós-condição: Paciente inserido mantendo a fila ordenada por gravidade.*/
int insere_ord(Fila *f, Pacientes elem){
    Fila F = (Fila) malloc(sizeof(struct no));
    if(F == NULL){return 0;}

    F->info = elem;

    if(*f == NULL){F->prox = F; *f = F; return 1;}

    Fila atual = *f, ant = NULL;

    do{
        if(elem.gravidadeDoenca < atual->info.gravidadeDoenca){break;}
        ant = atual; atual = atual->prox;
    }while(atual != *f);

    if (ant == NULL) {
        Fila ultimo = *f;
        while(ultimo->prox != *f){ultimo = ultimo->prox;}

        F->prox = *f;
        ultimo->prox = F;
        *f = F;
    }else{
        ant->prox = F;
        F->prox = atual;
    }return 1;
}

/*Entrada: Ponteiro para a fila f, variável para armazenar paciente elem.
Pré-condição: Fila não pode estar vazia.
Processo:
    -Remove o primeiro nó da fila.
    -Ajusta ponteiro do último nó para manter circularidade.
Saída: 1 se remoção bem-sucedida, 0 se fila vazia.
Pós-condição: Paciente removido da fila, fila permanece circular.*/
int remove_ini(Fila *f, Pacientes *elem){
    if(fila_vazia(*f)){return 0;}

    Fila aux = *f;
    *elem = aux->info;

    if(aux->prox == aux){*f = NULL;}
    else{
        Fila ultimo = *f;
        while (ultimo->prox != *f){ultimo = ultimo->prox;}

        *f = aux->prox;
        ultimo->prox = *f;
    }free(aux); return 1;
}

/*Entrada: Ponteiro para a fila f, variável tam.
Pré-condição: Fila inicializada.
Processo: Percorre a fila circular contando os nós até retornar ao início.
Saída: Retorna 1, e tam recebe o número de elementos.
Pós-condição: Fila permanece inalterada.*/
int tamanho_fila(Fila f, int *tam){
    if (f == NULL){*tam = 0; return 1;}

    int cont = 0;
    Fila aux = f;
    do{cont++; aux = aux->prox;
    }while(aux != f);

    *tam = cont;
    return 1;
}

/*Entrada: Ponteiro para a fila f.
Pré-condição: Fila inicializada.
Processo: Remove todos os elementos chamando remove_ini até fila ficar vazia.
Saída: 1 se esvaziou, 0 se fila já estava nula.
Pós-condição: Fila vazia.*/
int esvazia_fila(Fila *f){
    if(*f == NULL){return 0;}
    Pacientes lixo;
    while (!fila_vazia(*f)) {
        remove_ini(f, &lixo);
    }
    return 1;
}

/*Entrada: Ponteiro para a fila f.
Pré-condição: Fila inicializada.
Processo: Chama esvazia_fila e define ponteiro como NULL.
Saída: 1 se fila foi apagada, 0 caso ponteiro inválido.
Pós-condição: Fila apagada (ponteiro aponta para NULL).*/
int apaga_fila(Fila *f){
    if(f == NULL){return 0;}
    esvazia_fila(f);
    *f = NULL;
    return 1;
}

/*Entrada: Ponteiro para a fila f, posição pos, variável elem.
Pré-condição: Fila não pode estar vazia; posição deve ser válida (0 ≤ pos < tamanho).
Processo: Percorre a fila circular até alcançar a posição desejada.
Saída: 1 se encontrou paciente, 0 se posição inválida.
Pós-condição: Fila não sofre alterações.*/
int get_elem_pos(Fila f, int pos, Pacientes *elem){
    if (fila_vazia(f) || pos < 0){return 0;}

    int i = 1;
    Fila aux = f;
    do{
        if (i == pos){*elem = aux->info; return 1;}
        aux = aux->prox;
        i++;
    }while(aux != f);
    return 0;
}


















