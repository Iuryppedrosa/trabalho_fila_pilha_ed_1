typedef struct pacientes{
    int idade, gravidadeDoenca;
    char nome[30], tipoDoenca;
    float peso, altura;
}Pacientes;

typedef struct no *Fila;

Fila cria_fila();
int fila_vazia(Fila f);
int insere_ord(Fila *f, Pacientes elem);
int remove_ini(Fila *f, Pacientes *elem);
int tamanho_fila(Fila f, int *tam);
int esvazia_fila(Fila *f);
int apaga_fila(Fila *f);
int get_elem_pos(Fila f, int pos, Pacientes *elem);
