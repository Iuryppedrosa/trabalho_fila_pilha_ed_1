#include <stdio.h>
#include <stdlib.h>
#include "tad.h">
#define MAX 10

struct pilha {
    int vetor_inteiro[MAX];
    int topo;
};

/*
    Entrada: n�o possui.
    Pr�-condi��o: n�o possui.
    Processo: aloca dinamicamente uma pilha e inicializa seu topo como -1.
    Sa�da: retorna a refer�ncia para a pilha criada ou NULL se falhar.
    P�s-condi��o: pilha inicializada e pronta para uso.
*/
Pilha cria_pilha(){
    Pilha p = (Pilha) malloc(sizeof(struct pilha));
    if(p != NULL){
        p->topo = -1;
    }
    return p;
};

/*
    Entrada: uma pilha.
    Pr�-condi��o: pilha deve ter sido criada.
    Processo: verifica se o �ndice do topo est� na �ltima posi��o.
    Sa�da: retorna 1 se cheia, 0 caso contr�rio.
    P�s-condi��o: n�o altera a pilha.
*/
int pilha_cheia(Pilha p){
    if(p != NULL && p->topo == MAX - 1){
        return 1;
    }
    return 0;
}

/*
    Entrada: uma pilha.
    Pr�-condi��o: pilha deve ter sido criada.
    Processo: verifica se o topo est� em -1.
    Sa�da: retorna 1 se vazia, 0 caso contr�rio.
    P�s-condi��o: n�o altera a pilha.
*/
int pilha_vazia(Pilha p){
    if(p != NULL && p->topo == -1){
        return 1;
    }
    return 0;
}

/*
    Entrada: pilha e ponteiro para inteiro.
    Pr�-condi��o: pilha deve ter sido criada e n�o estar vazia.
    Processo: acessa o valor armazenado no topo.
    Sa�da: retorna 1 se conseguiu obter o valor, 0 caso contr�rio.
    P�s-condi��o: n�o altera a pilha.
*/
int get_topo(Pilha p, int *topo){
    if(p == NULL || pilha_vazia(p) == 1){
        return 0;
    }
    *topo = p->vetor_inteiro[p->topo];
    return 1;
}

/*
    Entrada: pilha e elemento inteiro.
    Pr�-condi��o: pilha deve ter sido criada e n�o estar cheia.
    Processo: incrementa o topo e armazena o elemento na nova posi��o.
    Sa�da: retorna 1 em caso de sucesso, 0 caso contr�rio.
    P�s-condi��o: elemento fica no topo da pilha.
*/
int insere_topo(Pilha p, int elemento){
    if(p == NULL || pilha_cheia(p) == 1){
        return 0;
    }
    p->topo++;
    p->vetor_inteiro[p->topo] = elemento;
    return 1;
}

/*
    Entrada: pilha e ponteiro para inteiro.
    Pr�-condi��o: pilha deve ter sido criada e n�o estar vazia.
    Processo: copia o valor do topo e decrementa o �ndice do topo.
    Sa�da: retorna 1 em caso de sucesso, 0 caso contr�rio.
    P�s-condi��o: elemento removido da pilha e devolvido via ponteiro.
*/
int remove_topo(Pilha p, int *devolver_elemento){
    if(p == NULL || pilha_vazia(p) == 1){
        return 0;
    }
    *devolver_elemento = p->vetor_inteiro[p->topo];
    p->topo--;
    return 0;
}

/*
    Entrada: pilha.
    Pr�-condi��o: pilha deve ter sido criada.
    Processo: define o topo como -1.
    Sa�da: retorna 1 em caso de sucesso, 0 caso contr�rio.
    P�s-condi��o: pilha fica vazia.
*/
int esvazia_pilha(Pilha p){
    if(p == NULL || pilha_vazia(p) == 1){
        return 0;
    }
    p->topo = -1;
    return 0;
}

/*
    Entrada: refer�ncia para ponteiro de pilha.
    Pr�-condi��o: pilha deve ter sido criada.
    Processo: libera a mem�ria alocada e coloca ponteiro como NULL.
    Sa�da: retorna 1 em caso de sucesso, 0 caso contr�rio.
    P�s-condi��o: pilha deixa de existir e n�o pode mais ser usada.
*/
int apaga_pilha(Pilha *p){
    if(p == NULL){
        return 0;
    }
    free(*p);
    *p = NULL;
    return 1;
}





