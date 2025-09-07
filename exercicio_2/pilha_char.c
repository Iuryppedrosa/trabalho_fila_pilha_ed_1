#include <stdlib.h>
#include "pilha_char.h"

/*
CRIA_PILHA_CHAR()
entrada: Nenhuma.
pre-condicao: Nenhuma.
processo: Retorna um ponteiro nulo, que representa uma pilha vazia.
saida: Retorna uma PilhaChar vazia (NULL).
pos-condicao: Nenhuma.
*/
PilhaChar cria_pilha_char() {
    return NULL;
}

/*
PILHA_CHAR_VAZIA()
entrada: Uma PilhaChar 'p'.
pre-condicao: Nenhuma.
processo: Verifica se o ponteiro da pilha � nulo.
saida: Retorna 1 se a pilha for vazia, 0 caso contr�rio.
pos-condicao: Nenhuma.
*/
int pilha_char_vazia(PilhaChar p) {
    return (p == NULL);
}

/*
PUSH_CHAR()
entrada: O endere�o da PilhaChar e o caractere a ser inserido.
pre-condicao: Nenhuma.
processo: Aloca um novo n�, preenche com o caractere, e o posiciona no topo
          da pilha, fazendo o ponteiro de topo apontar para ele.
saida: Retorna 1 para sucesso, 0 para falha de aloca��o.
pos-condicao: O caractere 'elem' � o novo elemento do topo da pilha.
*/
int push_char(PilhaChar *p, char elem) {
    PilhaChar N = (PilhaChar) malloc(sizeof(struct no_char));
    if (N == NULL) {
        return 0; // Falha na aloca��o
    }

    N->info = elem;
    N->prox = *p;
    *p = N;

    return 1; // Sucesso
}

/*
POP_CHAR()
entrada: O endere�o da PilhaChar e um ponteiro para char para retorno do valor.
pre-condicao: A pilha n�o pode estar vazia.
processo: Remove o n� do topo da pilha, retorna seu valor atrav�s do ponteiro
          'elem', libera a mem�ria alocada pelo n� e atualiza o topo da pilha.
saida: Retorna 1 em caso de sucesso, 0 se a pilha estiver vazia.
pos-condicao: O elemento do topo � removido e a pilha cont�m um elemento a menos.
*/
int pop_char(PilhaChar *p, char *elem) {
    if (pilha_char_vazia(*p)) {
        return 0; // Pilha vazia
    }

    PilhaChar aux = *p;
    *elem = aux->info;
    *p = aux->prox;

    free(aux);
    return 1; // Sucesso
}

/*
LE_TOPO_CHAR()
entrada: A PilhaChar e um ponteiro para char para retorno do valor.
pre-condicao: A pilha n�o pode estar vazia.
processo: Copia o valor do elemento do topo da pilha para a vari�vel apontada
          por 'elem', sem remover o n�.
saida: Retorna 1 em caso de sucesso, 0 se a pilha estiver vazia.
pos-condicao: Nenhuma; a pilha permanece inalterada.
*/
int le_topo_char(PilhaChar p, char *elem) {
    if (pilha_char_vazia(p)) {
        return 0; // Pilha vazia
    }

    *elem = p->info;
    return 1; // Sucesso
}

/*
APAGA_PILHA_CHAR()
entrada: O endere�o da PilhaChar.
pre-condicao: Nenhuma.
processo: Usa a fun��o pop_char() repetidamente para remover e liberar todos
          os n�s da pilha at� que ela se torne vazia.
saida: Retorna 1 em caso de sucesso.
pos-condicao: A pilha se torna vazia e toda a mem�ria de seus n�s � liberada.
*/
int apaga_pilha_char(PilhaChar *p) {
    while (!pilha_char_vazia(*p)) {
        char elem; // Vari�vel auxiliar, n�o ser� usada
        pop_char(p, &elem);
    }
    return 1; // Sucesso
}
