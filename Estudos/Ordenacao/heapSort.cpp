#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void exibir(vector<int> &v);
void heapify(vector<int> &v, int n, int idx);
void heapSort(vector<int> &v, int n);
void maxheap(vector<int> &v);
void preencher(vector<int> &v, int min, int max);

const int TAM = 10;

int main() {
    srand(time(NULL));
    vector<int> v(TAM);
    
    preencher(v, 1, 100);
    exibir(v);
    cout << endl;

    heapSort(v, v.size());
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

void heapify(vector<int> &v, int n, int idx) {
    int esq, dir, pai = idx;
    bool troca = true;
    while(troca) {
        troca = false;
        esq = 2*pai + 1;
        dir = 2*pai + 2;
        if(esq < n && v[pai] < v[esq])
            pai = esq;
        if(dir < n && v[pai] < v[dir])
            pai = dir;
        if(pai != idx) {
            swap(v[pai], v[idx]);
            troca = true;
            idx = pai;
        }
    }
}

void heapSort(vector<int> &v, int n) {
    maxheap(v);
    while(n > 0) {
        swap(v[0], v[n-1]);
        n--;
        heapify(v, n, 0);
    }
}

void maxheap(vector<int> &v) {
    for(int idx = v.size()/2 - 1; idx >= 0; idx--)
        heapify(v, v.size(), idx);
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = min + rand()%(max - min + 1);
}