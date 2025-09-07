#ifndef PILHA_CHAR_H_INCLUDED
#define PILHA_CHAR_H_INCLUDED

/**
 * @brief Estrutura do n� da pilha de caracteres.
 * Cada n� cont�m um caractere (info) e um ponteiro para o pr�ximo n� (prox).
 */
struct no_char {
    char info;
    struct no_char *prox;
};

/**
 * @brief Defini��o do tipo PilhaChar como um ponteiro para o n� do topo.
 * Uma pilha vazia � representada por um ponteiro NULL.
 */
typedef struct no_char *PilhaChar;

// --- Prot�tipos das Opera��es do TAD ---

/**
 * @brief Cria uma inst�ncia de uma pilha vazia.
 * @return Retorna NULL, representando uma pilha vazia.
 */
PilhaChar cria_pilha_char();

/**
 * @brief Verifica se a pilha est� vazia.
 * @param p A pilha a ser verificada.
 * @return Retorna 1 se a pilha estiver vazia, 0 caso contr�rio.
 */
int pilha_char_vazia(PilhaChar p);

/**
 * @brief Insere um caractere no topo da pilha (push).
 * @param p Ponteiro para a pilha onde o elemento ser� inserido.
 * @param elem O caractere a ser inserido.
 * @return Retorna 1 em caso de sucesso, 0 em caso de falha de aloca��o.
 */
int push_char(PilhaChar *p, char elem);

/**
 * @brief Remove um caractere do topo da pilha (pop).
 * @param p Ponteiro para a pilha da qual o elemento ser� removido.
 * @param elem Ponteiro para a vari�vel que armazenar� o caractere removido.
 * @return Retorna 1 se a pilha n�o estiver vazia, 0 caso contr�rio.
 */
int pop_char(PilhaChar *p, char *elem);

/**
 * @brief Obt�m o caractere no topo da pilha sem remov�-lo (peek).
 * @param p A pilha a ser consultada.
 * @param elem Ponteiro para a vari�vel que armazenar� o caractere do topo.
 * @return Retorna 1 se a pilha n�o estiver vazia, 0 caso contr�rio.
 */
int le_topo_char(PilhaChar p, char *elem);

/**
 * @brief Apaga todos os elementos da pilha, liberando a mem�ria alocada.
 * @param p Ponteiro para a pilha a ser apagada.
 * @return Retorna 1 em caso de sucesso.
 */
int apaga_pilha_char(PilhaChar *p);

#endif // PILHA_CHAR_H_INCLUDED
