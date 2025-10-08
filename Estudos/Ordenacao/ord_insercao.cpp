#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void exibir(vector<int> &v);
void preencher(vector<int> &v, int min, int max);
void ord_insercao(vector<int> &v);

const int TAM = 30; // #define TAM 30

int main() {
    srand(time(NULL));
    vector<int> v(TAM);
    
    preencher(v, 1, 100);
    exibir(v);
    cout << endl;

    ord_insercao(v);
    exibir(v);
    cout << endl;

    return 0;
}

void exibir(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        int a = v[i];
        cout << a << " ";
    }
}

void ord_insercao(vector<int> &v) {
    for(int i = 0; i < v.size() - 1; i++) {
        int id_menor = i;

        for(int j = i+1; j < v.size(); j++)
            if(v[j] < v[id_menor])
                id_menor = j;

        int aux = v[i];
        v[i] = v[id_menor];
        v[id_menor] = aux;
    }
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = min + rand()%(max - min + 1);      // min + rand()%(qtde) => qtde = max - min + 1
}