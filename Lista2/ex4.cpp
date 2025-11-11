#include <iostream>
#include <cctype>
#include "./includes/hashing.h"

using namespace std;

int main() {
    hashtable* tabela = inicializar(11);
    if (!tabela) {
        cout << "Erro ao criar tabela hash!" << endl;
        return 1;
    }

    // NIOVZAPROST
    char c;

    while (1) {
        cin >> c;
        c = toupper(c);

        int valor = charParaValor(c);

        if(inserir(tabela, valor)) {
            cout << endl << "Valor inserido na tabela Hash: ";
            mostrar(tabela);
            cout << endl;

            colisao(tabela, valor);
            cout << endl;
        }
        else
            cout << "Falha ao inserir" << endl;
    }

    liberar(tabela);
    return 0;
}

