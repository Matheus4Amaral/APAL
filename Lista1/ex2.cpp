#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "./includes/Utilitaria.h"

const int TAM = 10;

using namespace std;

void exibir(vector<int> &v);
void exibirAnimado(vector<int> &v, int n);
void exibirAnimadoUltimo(vector<int> &v);
void ordenacaoPorInsercao(vector<int> &v);
void ordenacaoPorInsercaoAnimacao(vector<int> &v);
void preencher(vector<int> &v, int min, int max);

int main() {
    srand(time(NULL));
    vector<int> v(TAM);

    preencher(v, 1, 100);

    ordenacaoPorInsercaoAnimacao(v);

    return 0;
}

void exibir(vector<int> &v) {
    for(auto a : v)
        cout << a << " ";
}

void exibirAnimado(vector<int> &v, int n) {
    Utilitaria::aguardar(2000);
    Utilitaria::limparTela();

    for(int i = 0; i < v.size(); i++) {
        if(i < n) {
            Utilitaria::colorir(Utilitaria::REGULAR, Utilitaria::BLUE);
            cout << v[i] << " ";
        }
        else {
            Utilitaria::colorir(Utilitaria::REGULAR, Utilitaria::RED);
            cout << v[i] << " ";
        }
    }

    Utilitaria::resetarCor();
}

void exibirAnimadoUltimo(vector<int> &v) {
    Utilitaria::aguardar(2000);
    Utilitaria::limparTela();
    Utilitaria::colorir(Utilitaria::REGULAR, Utilitaria::BLUE);
    for(auto a : v)
        cout << a << " ";
    Utilitaria::resetarCor();
}

void ordenacaoPorInsercao(vector<int> &v) {
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

void ordenacaoPorInsercaoAnimacao(vector<int> &v) {
    for(int i = 1; i <= v.size() - 1; i++) {
        int chave = v[i];
        int j = i - 1;
        while(j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
        exibirAnimado(v, i);
        cout << endl;
    }
    exibirAnimadoUltimo(v);
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = (rand() % (max - min + 1)) + min;
}