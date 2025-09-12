#ifndef FILA_H
#define FILA_H
#define MAX_PLACA 8
#include <time.h>


typedef struct carro {
    char placa[MAX_PLACA];
    char tipo_servico;
    time_t hora_entrada;
} Carro;


typedef struct fila* Fila;
Fila cria_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);

int insere_fim(Fila f, Carro elem);
int remove_inicio(Fila f, Carro *elem);

int tamanho(Fila f);

int esvazia_fila(Fila f);
int apaga_fila(Fila *f);
#endif
