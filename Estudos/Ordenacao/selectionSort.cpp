#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int busca_linear(int *v, int n, int k);
int busca_linear_otim(int *v, int n, int k);
void exibir(int *v, int n);
void preencher(int *v, int n, int min, int max);
void selectionSort(int *v, int n);

const int TAM = 30; // #define TAM 30

int main() {
    srand(time(NULL));
    int v[TAM];
    
    preencher(v, TAM, 1, 100);
    exibir(v, TAM);
    cout << endl;
    /*cout << busca_linear(v, TAM, v[5]) << endl;
    cout << busca_linear(v, TAM, 101) << endl;*/
    selectionSort(v, TAM);
    exibir(v, TAM);
    cout << endl;

    return 0;
}

int busca_linear(int *v, int n, int k) {
    for(int i = 0; i < n; i++)
        if(v[i] == k)
            return i;
    
    return -1;
}

int busca_linear_otim(int *v, int n, int k) {
    for(int i = 0; i < n && v[i] <= k; i++)
        if(v[i] == k)
            return i;
    
    return -1;
}

void exibir(int *v, int n) {
    for(int i = 0; i < n; i++) {
        int a = v[i];
        cout << a << " ";
    }
}

void selectionSort(int *v, int n) {
    for(int i = 0; i < n-1; i++) {
        int id_menor = i;
        for(int j = i+1; j < n; j++)
            if(v[j] < v[id_menor])
                id_menor = j;
        int aux = v[i];
        v[i] = v[id_menor];
        v[id_menor] = aux;
    }
}

void preencher(int *v, int n, int min, int max) {
    for(int i = 0; i < n; i++)
        v[i] = min + rand()%(max - min + 1);      // min + rand()%(qtde) => qtde = max - min + 1
}