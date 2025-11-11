#ifndef HASHING_H
#define HASHING_H

#include <stdbool.h>

typedef struct hashtable hashtable;

/*
Entrada: h (ponteiro para a tabela hash), value (valor a ser inserido)
Saída: true se inserido com sucesso, false caso contrário
Insere um valor na tabela hash usando sondagem linear para tratar colisões
*/
int buscar(hashtable* h, int value);
/*
Entrada: c (caractere a ser convertido)
Saída: índice calculado pela função hash
Converte um caractere maiúsculo em um valor inteiro (A=1, B=2, ..., Z=26)
*/
int charParaValor(char c);
/*
Entrada: h (ponteiro para a tabela hash), key (chave para hash)
Saída: índice calculado pela função hash
Calcula o índice na tabela hash para uma dada chave
*/
int calcularHash(hashtable* h, int key);
/*
Entrada: h (ponteiro para a tabela hash), value (valor a ser verificado)
Saída: não tem
Mostra as posições ocupadas na tabela hash durante a resolução de colisões para um valor específico
*/
void colisao(hashtable* h, int value);
/*
Entrada: tam (tamanho da tabela)
Saída: ponteiro para a tabela hash inicializada
Inicializa uma tabela hash de tamanho 'tam' com todas as posições vazias (-1)
*/
hashtable* inicializar(int tam);
/*
Entrada: h (ponteiro para a tabela hash), value (valor a ser inserido)
Saída: true se inserido com sucesso, false caso contrário
Insere um valor na tabela hash usando sondagem linear para tratar colisões
*/
bool inserir(hashtable* h, int value);
/*
Entrada: h (ponteiro para a tabela hash)
Saida: nao tem
Libera a memória alocada para a tabela hash
*/
void liberar(hashtable* h);
/*
Entrada: h (ponteiro para a tabela hash)
Saída: não tem
Mostra o conteúdo da tabela hash
*/
void mostrar(hashtable* h);
/*
Entrada: h (ponteiro para a tabela hash), value (valor a ser removido)
Saída: true se removido com sucesso, false caso contrário
Remove um valor da tabela hash
*/
bool remover(hashtable* h, int value);

/*
Entrada: v (valor inteiro)
Saída: caractere correspondente
Converte um valor inteiro em um caractere maiúsculo (1=A, 2=B, ..., 26=Z)
*/
char valorParaChar(int v);

#endif