#ifndef PILHA_FLOAT_H_INCLUDED
#define PILHA_FLOAT_H_INCLUDED

/**
 * @brief Estrutura do n� da pilha de floats.
 */
struct no_float {
    float info;
    struct no_float *prox;
};

/**
 * @brief Defini��o do tipo PilhaFloat como um ponteiro para o n� do topo.
 */
typedef struct no_float *PilhaFloat;

// --- Prot�tipos das Opera��es do TAD ---

/**
 * @brief Cria uma inst�ncia de uma pilha vazia.
 * @return Retorna NULL.
 */
PilhaFloat cria_pilha_float();

/**
 * @brief Verifica se a pilha est� vazia.
 * @param p A pilha a ser verificada.
 * @return Retorna 1 se a pilha estiver vazia, 0 caso contr�rio.
 */
int pilha_float_vazia(PilhaFloat p);

/**
 * @brief Insere um float no topo da pilha (push).
 * @param p Ponteiro para a pilha.
 * @param elem O float a ser inserido.
 * @return Retorna 1 em caso de sucesso, 0 em caso de falha.
 */
int push_float(PilhaFloat *p, float elem);

/**
 * @brief Remove um float do topo da pilha (pop).
 * @param p Ponteiro para a pilha.
 * @param elem Ponteiro para a vari�vel que armazenar� o float removido.
 * @return Retorna 1 se a pilha n�o estiver vazia, 0 caso contr�rio.
 */
int pop_float(PilhaFloat *p, float *elem);

/**
 * @brief Apaga todos os elementos da pilha.
 * @param p Ponteiro para a pilha a ser apagada.
 * @return Retorna 1 em caso de sucesso.
 */
int apaga_pilha_float(PilhaFloat *p);

#endif // PILHA_FLOAT_H_INCLUDED
