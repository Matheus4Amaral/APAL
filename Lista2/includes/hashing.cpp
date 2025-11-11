#include <iostream>
#include <cstdlib>
#include "hashing.h"

struct hashtable {
    int *table;
    int size;
};

int buscar(hashtable* h, int value) {
    int pos = calcularHash(h, value);
    int inicio = pos;
    int tentativas = 0; // evita loop infinito

    while (h->table[pos] != -1 && tentativas < h->size) {
        if (h->table[pos] == value)
            return pos;
        pos = (pos + 1) % h->size;
        tentativas++;
    }
    return -1;
}

int calcularHash(hashtable* h, int key){
    return (key + 2) % h->size;
}

int charParaValor(char c){
    return (c - 'A' + 1);
}

void colisao(hashtable* h, int value) {
    int posInicial = calcularHash(h, value);
    int posFinal = buscar(h, value);

    if (posFinal == posInicial) {
        std::cout << "Nenhuma colisao" << std::endl;
        return;
    }

    std::cout << "Colisao no(s) indice(s): ";

    int pos = posInicial;
    int colisoes = 0;

    while (pos != posFinal) {
        if (h->table[pos] != -1 && h->table[pos] != value) {
            std::cout << pos << " ";
            colisoes++;
        }
        pos = (pos + 1) % h->size;
    }

    std::cout << "\nTotalizando: " << colisoes << " colisao(oes)" << std::endl;
}

hashtable* inicializar(int tam) {
    hashtable *tabela = (hashtable*) malloc(sizeof(hashtable));
    if (!tabela)
        return NULL;

    tabela->table = (int*) malloc(tam * sizeof(int));
    if (!tabela->table){
        free(tabela);
        return NULL;
    }

    tabela->size = tam;

    for (int i = 0; i < tam; i++)
        tabela->table[i] = -1;

    return tabela;
}

bool inserir(hashtable* h, int value){
    int pos = calcularHash(h, value);

    int inicio = pos;
    while(h->table[pos] != -1){
        pos = (pos + 1) % h->size;
        if (pos == inicio) 
            return false;
    }

    h->table[pos] = value;

    return true;
}

void liberar(hashtable* h) {
    if(h){
        if (h->table)
            free(h->table);
        free(h);
    }
}

void mostrar(hashtable* h) {
    for(int i = 0; i < h->size; i++)
        if(h->table[i] == -1)
            std::cout << "-";
        else
            std::cout << valorParaChar(h->table[i]);
        std::cout << " ";
}

bool remover(hashtable* h, int value){
    int pos = buscar(h, value);
    if(pos != -1) {
        h->table[pos] = -1;
        return true;
    }

    return false;
}

char valorParaChar(int v){
    return (v + 'A' - 1);
}