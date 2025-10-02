#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "./includes/Utilitaria.h"

const int TAM = 10;

using namespace std;

void exibir(vector<int> &v);
void exibirAnimado(vector<int> &v, int n);
void ordenacao(vector<int> &v);
void ordenacaoAnimacao(vector<int> &v);
void preencher(vector<int> &v, int min, int max);

int main() {
    srand(time(NULL));
    vector<int> v(TAM);

    preencher(v, 1, 100);

    ordenacaoAnimacao(v);

    return 0;
}

void exibir(vector<int> &v) {
    for(auto a : v)
        cout << a << " ";
}

void exibirAnimado(vector<int> &v, int n) {
    for(int i = 0; i < v.size(); i++) {
        if(i < n) {
            Utilitaria::colorir(Utilitaria::REGULAR, Utilitaria::BLUE);
            cout << v[i] << " ";
        }
        else {
            Utilitaria::colorir(Utilitaria::REGULAR, Utilitaria::RED);
            cout << v[i] << " ";
        }

        if(i == v.size() - 1) {
            Utilitaria::limparTela();
            Utilitaria::colorir(Utilitaria::REGULAR, Utilitaria::BLUE);
            for(auto a : v)
                cout << a << " ";
            Utilitaria::resetarCor();
        }
    }

    Utilitaria::resetarCor();
}

void ordenacao(vector<int> &v) {
    for(int i = 1; i <= v.size() - 1; i++) {
        int chave = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
}

void ordenacaoAnimacao(vector<int> &v) {
    for(int i = 1; i <= v.size() - 1; i++) {
        int chave = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
        Utilitaria::limparTela();
        exibirAnimado(v, i);
        Utilitaria::aguardar(2000);
        cout << endl;
    }
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = (rand() % (max - min + 1)) + min;
}