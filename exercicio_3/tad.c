#include <stdio.h>
#include <stdlib.h>
#include "tad.h"
#define MAX 6

struct fila {
    Carro info[MAX];
    int ini;
    int fim;
};

/*
Entrada: Nenhuma
Pre-condicao: Nenhuma
Processo: Aloca dinamicamente uma estrutura de fila na memória e inicializa
          seus campos 'ini' e 'fim' para 0.
Saida: Ponteiro para a fila criada ou NULL em caso de falha de alocação.
Pos-condicao: A fila está criada, vazia e pronta para ser usada.
*/
Fila cria_fila() {
    Fila f = (Fila) malloc(sizeof(struct fila));
    if (f != NULL) {
        f->ini = 0;
        f->fim = 0;
    }
    return f;
}

/*
Entrada: Ponteiro para uma fila.
Pre-condicao: A fila deve ter sido criada.
Processo: Verifica se os índices de início e fim da fila são iguais.
Saida: Retorna 1 se a fila estiver vazia ou 0 caso contrário.
Pos-condicao: Nenhuma.
*/
int fila_vazia(Fila f) {
    if (f == NULL) return 0;
    return (f->ini == f->fim);
}

/*
Entrada: Ponteiro para uma fila.
Pre-condicao: A fila deve ter sido criada.
Processo: Verifica se a próxima posição do fim, de forma circular, é igual
          ao início, indicando que a fila está cheia (estratégia de
          desperdício de posição).
Saida: Retorna 1 se a fila estiver cheia ou 0 caso contrário.
Pos-condicao: Nenhuma.
*/
int fila_cheia(Fila f) {
    if (f == NULL) return 0;
    return ((f->fim + 1) % MAX == f->ini);
}

/*
Entrada: Ponteiro para uma fila e o elemento (Carro) a ser inserido.
Pre-condicao: A fila deve ter sido criada e não pode estar cheia.
Processo: Adiciona o elemento no final da fila e atualiza o índice 'fim'
          de forma circular.
Saida: Retorna 1 em caso de sucesso ou 0 em caso de falha.
Pos-condicao: A fila contém o novo elemento na sua última posição.
*/
int insere_fim(Fila f, Carro elem) {
    if (f == NULL || fila_cheia(f)) {
        return 0;
    }
    f->info[f->fim] = elem;
    f->fim = (f->fim + 1) % MAX;
    return 1;
}

/*
Entrada: Ponteiro para uma fila e um ponteiro para uma variável Carro onde o
         elemento removido será armazenado.
Pre-condicao: A fila deve ter sido criada e não pode estar vazia.
Processo: Remove o elemento do início da fila, armazena-o na variável de
          retorno e atualiza o índice 'ini' de forma circular.
Saida: Retorna 1 em caso de sucesso ou 0 em caso de falha.
Pos-condicao: A fila não contém mais o elemento que estava no início.
*/
int remove_inicio(Fila f, Carro *elem) {
    if (f == NULL || fila_vazia(f)) {
        return 0;
    }
    *elem = f->info[f->ini];
    f->ini = (f->ini + 1) % MAX;
    return 1;
}

/*
Entrada: Ponteiro para uma fila.
Pre-condicao: A fila deve ter sido criada.
Processo: Calcula a quantidade de elementos presentes na fila, tratando
          corretamente o caso circular (quando fim < ini).
Saida: Retorna o número de elementos na fila.
Pos-condicao: Nenhuma.
*/
int tamanho(Fila f) {
    if (f == NULL) return 0;
    if (f->fim >= f->ini) {
        return f->fim - f->ini;
    } else {
        return MAX - f->ini + f->fim;
    }
}

/*
Entrada: Ponteiro para uma fila.
Pre-condicao: A fila deve ter sido criada.
Processo: Reseta os índices de início e fim da fila para 0, tornando-a
          logicamente vazia.
Saida: Retorna 1 em caso de sucesso ou 0 em caso de falha (fila não existe).
Pos-condicao: A fila está vazia.
*/
int esvazia_fila(Fila f) {
    if (f == NULL) {
        return 0;
    }
    f->ini = 0;
    f->fim = 0;
    return 1;
}

/*
Entrada: Endereço de um ponteiro para uma fila.
Pre-condicao: A fila deve ter sido criada.
Processo: Libera a memória alocada para a estrutura da fila e atribui NULL
          ao ponteiro original para evitar uso indevido (dangling pointer).
Saida: Retorna 1 em caso de sucesso ou 0 em caso de falha.
Pos-condicao: A memória da fila foi liberada e o ponteiro aponta para NULL.
*/
int apaga_fila(Fila *f) {
    if (f == NULL || *f == NULL) {
        return 0;
    }
    free(*f);
    *f = NULL;
    return 1;
}
