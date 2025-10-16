#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v);
void exibir(vector<int> &v);
void insertionSort(vector<int> &v);
void merge(vector<int> &v, int e, int m, int d);
void mergeSort(vector<int> &v, int e, int d);
int particionamento(vector<int> &v, int e, int d);
void preencher(vector<int> &v, int min, int max);
void quickSort(vector<int> &v, int e, int d);
void selectionSort(vector<int> &v);

const int TAM = 30; // #define TAM 30

int main() {
    srand(time(NULL));
    vector<int> v(TAM);
    
    preencher(v, 1, 100);
    exibir(v);
    cout << endl;

    //quickSort(v, 0, v.size());
    mergeSort(v, 0, v.size()-1);
    exibir(v);
    cout << endl;

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

void exibir(vector<int> &v) {
    for(auto i : v)
        cout << i << " ";
}

void insertionSort(vector<int> &v) {
    for(int i = 1; i < v.size(); i++) {
        int chave = v[i], j = i-1;
        while(j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = chave;
    }
}

void merge(vector<int> &v, int e, int m, int d) {
    vector<int> aux(d - e + 1);
    int ide = e, idm = m+1, id = 0;

    while(ide <= m && idm <= d) 
        if(v[ide] <= v[idm])
            aux[id++] = v[ide++];
        else
            aux[id++] = v[idm++];
    
    while(ide <= m)
        aux[id++] = v[ide++];
    while(idm <= d)
        aux[id++] = v[idm++];

    id = 0;
    for(int i = e; i <= d; i++)
        v[i] = aux[id++];
    
}

void mergeSort(vector<int> &v, int e, int d) {
    if(e >= d)
        return;
    
    int m = e + (d-e)/2;
    mergeSort(v, e, m);
    mergeSort(v, m+1, d);
    merge(v, e, m, d);
}

int particionamento(vector<int> &v, int e, int d) {
    int p = e, k, atual;
    k = atual = e + 1;

    while(atual <= d) {
        if(v[atual] <= v[p]) {
            swap(v[atual], v[k]);
            k++;
        }
        atual++;
    }
    swap(v[k-1], v[p]);

    return k - 1;
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = min + rand()%(max - min + 1);
}

void quickSort(vector<int> &v, int e, int d) {
    if(e >= d)
        return;
    
    int p = particionamento(v, e, d);
    quickSort(v, e, p-1);
    quickSort(v, p+1, d);
}

void selectionSort(vector<int> &v) {
    for(int i = 0; i < v.size()-1; i++) {
        int idMenor = i;
        for(int j = i+1; j < v.size(); j++) 
            if(v[idMenor] > v[j])
                idMenor = j;
        swap(v[i], v[idMenor]);
    }
}