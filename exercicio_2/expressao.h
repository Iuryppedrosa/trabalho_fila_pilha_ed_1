#ifndef EXPRESSAO_H_INCLUDED
#define EXPRESSAO_H_INCLUDED

/**
 * @brief Valida os escopos de uma express�o matem�tica.
 * @param exp A string da express�o infixa.
 * @return Retorna 1 se v�lida, 0 caso contr�rio.
 */
int valida_escopo(char *exp);

/**
 * @brief Converte uma express�o infixa para p�s-fixa.
 * @param infixa A string da express�o infixa.
 * @param posfixa Ponteiro para a string que armazenar� a express�o p�s-fixa.
 * @return Retorna 1 em caso de sucesso, 0 em caso de erro.
 */
int infixa_para_posfixa(char *infixa, char *posfixa);

/**
 * @brief Avalia uma express�o p�s-fixa.
 * @param posfixa A string da express�o p�s-fixa.
 * @param resultado Ponteiro para a vari�vel que armazenar� o resultado.
 * @return Retorna 1 em caso de sucesso, 0 em caso de erro.
 */
int avalia_posfixa(char *posfixa, float *resultado);

#endif // EXPRESSAO_H_INCLUDED
