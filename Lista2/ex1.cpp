#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
Entrada: v (vetor de inteiros)
Saída: não tem
Ordena o vetor usando o algoritmo Bubble Sort
*/
void bubbleSort(vector<int> &v);
/*
Entrada: v (vetor de inteiros), ini (índice inicial), fim (índice final), b (valor a ser buscado)
Saída: índice do valor buscado ou -1 se não encontrado
Realiza busca binária no vetor para encontrar o índice do valor b
*/
int buscaBinaria(vector<int> &v, int ini, int fim, int b);
/*
Entrada: v (vetor de inteiros)
Saída: não tem
Exibe os elementos do vetor
*/
void exibir(vector<int> &v);
/*
Entrada: v (vetor de inteiros), min (valor mínimo), max (valor máximo)
Saída: não tem
Preenche o vetor com valores aleatórios entre min e max
*/
void preencher(vector<int> &v, int min, int max);

int main() {
    srand(time(NULL));

    int N = 100, min = 1, max = 200;
    vector<int> v(N);

    preencher(v, min, max);

    cout << "Vetor desordenado: ";
    exibir(v);
    cout << endl;

    bubbleSort(v);

    cout << "Vetor ordenado: ";
    exibir(v);
    cout << endl;

    int busca = min + rand() % (max - min + 1);
    cout << "A posicao do item buscado (" << busca << ") e: " << buscaBinaria(v, 0, v.size() - 1, busca);

    return 0;
}

void bubbleSort(vector<int> &v) {
    bool trocou = true;
    while(trocou) {
        trocou = false;
        for(int i = 1; i < v.size(); i++) {
            if(v[i] < v[i-1]) {
                swap(v[i], v[i-1]);
                trocou = true;
            }
        }
    }
}

int buscaBinaria(vector<int> &v, int ini, int fim, int b) {
    if(ini > fim)
        return -1;
    
    int meio = ini + (fim - ini)/2;

    if (b == v[meio])
        return meio + 1;
    else if (b > v[meio])
        return buscaBinaria(v, meio + 1, fim, b);
    else
        return buscaBinaria(v, ini, meio - 1, b);
}

void exibir(vector<int> &v) {
    for(auto i : v)
        cout << i << " ";
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = min + rand() % (max - min + 1);
}