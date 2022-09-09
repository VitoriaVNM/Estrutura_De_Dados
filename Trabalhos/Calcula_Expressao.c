/*
Estrutura de dados - Trabalho 2 - Calculadora em pilha
Vitória Nazareth || 17/06/2022
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//tamanho máximo da expressão de entrada
#define MAX 1000 

//inicio da definição das pilhas
typedef struct _StackInt{
    int *stackInt;
    int elementos;
    int vagas;
} StackInt;

typedef struct _StackChar{
    char *stackChar;
    int elementos;
    int vagas;
} StackChar;
//fim da definição das pilhas


StackInt stki; //ponteiro para a pilha de inteiros
StackChar stkc; //ponteiro para a pilha de símbolos

void result(int total){ printf("\nO resultado eh: %d", total); }

void pushChar(char simb, StackChar *stkc){
    if(stkc->elementos >= stkc->vagas){
        stkc->vagas*=2;
        stkc->stackChar = realloc(stkc->stackChar, sizeof(int)*stkc->vagas);
    }
    stkc->elementos++;
    stkc->stackChar[stkc->elementos] = simb;
}

void pushInt(int num, StackInt *stki){
    if(stki->elementos >= stki->vagas){
        stki->vagas*=2;
        stki->stackInt = realloc(stki->stackInt, sizeof(int)*stki->vagas);
    }
    stki->stackInt[stki->elementos] = num;
    stki->elementos++;
}

int popInt(StackInt *stki){
    int popInt = stki->stackInt[stki->elementos-1];
    stki->elementos--;
    return popInt;
}

int popChar(StackChar *stkc){
    char popChar = stkc->stackChar[stkc->elementos-1];
    stkc->elementos--;
    return popChar;
}

int calculus(StackInt *stki, StackChar *stkc){
    char sign;
    int val1, val2;
    while(stki->elementos > 1){
        sign = popChar(stkc);
        if(sign == '+'){
            val1 = popInt(stki);
            val2 = popInt(stki);
            pushInt((val2+val1), stki);
        }
        else if(sign == '-'){
            val1 = popInt(stki);
            val2 = popInt(stki);
            pushInt((val2-val1), stki);
        }
        else if(sign == '/'){
            val1 = popInt(stki);
            val2 = popInt(stki);
            pushInt((val2/val1), stki);
        }
        else if(sign == '*'){
            val1 = popInt(stki);
            val2 = popInt(stki);
            pushInt((val2*val1), stki);
        }
    }
    return popInt(stki);
}

void convert(char *expre, int tam)
{
    int i = 0, num = 0;
    for(; i < tam; i++){
        while(isdigit(expre[i])){
            num = expre[i] - '0' + num*10;
            i++;
        }
        pushInt(num, &stki);
        pushChar(expre[i], &stkc);
        num = 0;
    }
}

int Expresize(char *expre){ return strlen(expre); }

void ExpreIn(char *expre){
    printf("Entre com uma expressao matematica: \n");
    scanf("%s", expre);
}

void init_stackInt(StackInt *stki){
    stki->elementos = 0;
    stki->vagas = 4;
    stki->stackInt = malloc(sizeof(int)*stki->vagas);
}

void init_stackChar(StackChar *stkc){ 
    stkc->elementos = 0;
    stkc->vagas = 4;
    stkc->stackChar = malloc(sizeof(char)*stkc->vagas);
}

int main(){

    char expre[MAX] = ""; //vetor que guarda a expressão
    init_stackInt(&stki); //inicia a pilha de inteiros
    init_stackChar(&stkc); //inicia a pilha de símbolos
    ExpreIn(expre); //recebe a expressão e aloca no vetor
    int size = Expresize(expre); //retorna o tamanho da expressão
    convert(expre, size); //converte os inteiros e add os valores nas pilhas
    int total = calculus(&stki, &stkc); //retorna o valor da expressão
    result(total); //exibe o resultado
    
    return 0;
}
