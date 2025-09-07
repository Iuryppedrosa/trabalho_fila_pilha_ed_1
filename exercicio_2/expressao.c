#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "pilha_char.h"
#include "pilha_float.h"
#include "expressao.h"

/*
GET_PRECEDENCIA()
entrada: Um caractere de operador.
pre-condicao: Nenhuma.
processo: Retorna um valor inteiro que representa a preced�ncia matem�tica
          do operador de entrada.
saida: Retorna 3 para '^', 2 para '*' ou '/', 1 para '+' ou '-', e 0 para
       qualquer outro caractere.
pos-condicao: Nenhuma.
*/
int get_precedencia(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

/*
VALIDA_ESCOPO()
entrada: Uma string contendo a express�o infixa.
pre-condicao: A string deve ser terminada com '\0'.
processo: Percorre a express�o. Usa uma PilhaChar para empilhar delimitadores
          de abertura. Ao encontrar um de fechamento, verifica a correspond�ncia
          e a regra de preced�ncia de aninhamento. Imprime erros detalhados.
saida: Retorna 1 se os escopos s�o v�lidos, 0 caso contr�rio.
pos-condicao: Nenhuma.
*/
int valida_escopo(char *exp) {
    PilhaChar p = cria_pilha_char();
    int i = 0;
    char topo;

    while (exp[i] != '\0') {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') {
            if (!pilha_char_vazia(p)) {
                le_topo_char(p, &topo);
                if ((exp[i] == '[' && topo == '(') || (exp[i] == '{' && (topo == '(' || topo == '['))) {
                    printf("\nERRO: Escopo com precedencia invalida! '%c' dentro de '%c'.\n", exp[i], topo);
                    apaga_pilha_char(&p);
                    return 0;
                }
            }
            push_char(&p, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (pilha_char_vazia(p)) {
                printf("\nERRO: Fechamento de escopo '%c' sem abertura correspondente.\n", exp[i]);
                apaga_pilha_char(&p);
                return 0;
            }
            pop_char(&p, &topo);
            if ((exp[i] == ')' && topo != '(') || (exp[i] == ']' && topo != '[') || (exp[i] == '}' && topo != '{')) {
                printf("\nERRO: Fechamento de escopo '%c' nao corresponde a abertura '%c'.\n", exp[i], topo);
                apaga_pilha_char(&p);
                return 0;
            }
        }
        i++;
    }

    if (!pilha_char_vazia(p)) {
        printf("\nERRO: Mais aberturas de escopo do que fechamentos.\n");
        apaga_pilha_char(&p);
        return 0;
    }

    apaga_pilha_char(&p);
    return 1;
}

/*
INFIXA_PARA_POSFIXA()
entrada: String da express�o infixa e ponteiro para a string de sa�da p�s-fixa.
pre-condicao: A express�o infixa j� teve seus escopos validados. A string
              p�s-fixa tem tamanho suficiente para armazenar o resultado.
processo: Implementa o algoritmo Shunting-yard. Percorre a infixa, copiando
          operandos para a sa�da e usando uma PilhaChar para gerenciar
          operadores e delimitadores de acordo com suas preced�ncias.
saida: Retorna 1 para sucesso, 0 para erro de sintaxe.
pos-condicao: A string 'posfixa' cont�m a express�o convertida.
*/
int infixa_para_posfixa(char *infixa, char *posfixa) {
    PilhaChar p = cria_pilha_char();
    int i = 0, j = 0;
    char topo;

    while (infixa[i] != '\0') {
        char c = infixa[i];

        if (c >= 'A' && c <= 'F') {
            posfixa[j++] = c;
        }
        else if (c == '(' || c == '[' || c == '{') {
            push_char(&p, c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            char abertura_correspondente = (c == ')') ? '(' : (c == ']') ? '[' : '{';
            while (le_topo_char(p, &topo) && topo != abertura_correspondente) {
                pop_char(&p, &topo);
                posfixa[j++] = topo;
            }
            pop_char(&p, &topo);
        }
        else if (strchr("+-*/^", c)) {
            if (i > 0 && strchr("+-*/^", infixa[i-1])) {
                 printf("\nERRO DE SINTAXE: Operador '%c' segue outro operador.\n", c);
                 apaga_pilha_char(&p);
                 return 0;
            }
            while (!pilha_char_vazia(p) && le_topo_char(p, &topo) && get_precedencia(topo) >= get_precedencia(c)) {
                pop_char(&p, &topo);
                posfixa[j++] = topo;
            }
            push_char(&p, c);
        }
        i++;
    }

    while (pop_char(&p, &topo)) {
        posfixa[j++] = topo;
    }
    posfixa[j] = '\0';
    apaga_pilha_char(&p);
    return 1;
}

/*
AVALIA_POSFIXA()
entrada: String da express�o p�s-fixa e um ponteiro para float para o resultado.
pre-condicao: A express�o p�s-fixa � sintaticamente v�lida.
processo: Percorre a express�o. Empilha os valores num�ricos dos operandos (solicitados
          ao usu�rio) em uma PilhaFloat. Ao encontrar um operador, desempilha dois
          operandos, realiza a opera��o e empilha o resultado.
saida: Retorna 1 para sucesso, 0 em caso de erro na avalia��o.
pos-condicao: A vari�vel apontada por 'resultado' cont�m o valor final calculado.
*/
int avalia_posfixa(char *posfixa, float *resultado) {
    PilhaFloat p = cria_pilha_float();
    float valores[6] = {0};
    int i = 0;
    int vars_usadas[6] = {0};

    while(posfixa[i] != '\0'){
        if(posfixa[i] >= 'A' && posfixa[i] <= 'F'){
            vars_usadas[posfixa[i] - 'A'] = 1;
        }
        i++;
    }

    printf("\n--- Digite os valores para as variaveis ---\n");
    for(i = 0; i < 6; i++){
        if(vars_usadas[i]){
            printf("Valor de %c: ", 'A' + i);
            scanf("%f", &valores[i]);
        }
    }
    while(getchar() != '\n');

    i = 0;
    while (posfixa[i] != '\0') {
        char c = posfixa[i];

        if (c >= 'A' && c <= 'F') {
            push_float(&p, valores[c - 'A']);
        }
        else if (strchr("+-*/^", c)) {
            float op2, op1, res;
            if (!pop_float(&p, &op2) || !pop_float(&p, &op1)) {
                printf("\nERRO DE AVALIACAO: Faltam operandos para o operador '%c'.\n", c);
                apaga_pilha_float(&p);
                return 0;
            }
            switch (c) {
                case '+': res = op1 + op2; break;
                case '-': res = op1 - op2; break;
                case '*': res = op1 * op2; break;
                case '/': res = op1 / op2; break;
                case '^': res = pow(op1, op2); break;
            }
            push_float(&p, res);
        }
        i++;
    }

    if (!pop_float(&p, resultado) || !pilha_float_vazia(p)) {
        printf("\nERRO DE AVALIACAO: A expressao esta mal formada (faltam operadores).\n");
        apaga_pilha_float(&p);
        return 0;
    }

    apaga_pilha_float(&p);
    return 1;
}
