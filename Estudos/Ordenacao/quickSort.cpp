#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void exibir(vector<int> &v);
int particionamento(vector<int> &v, int e, int d);
void preencher(vector<int> &v, int min, int max);
void quickSort(vector<int> &v, int e, int d);

const int TAM = 30; // #define TAM 30

int main() {
    srand(time(NULL));
    vector<int> v(TAM);
    
    preencher(v, 1, 100);
    exibir(v);
    cout << endl;

    quickSort(v, 0, v.size());
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

int particionamento(vector<int> &v, int e, int d) {
    int p = e, atual, k;
    atual = k = p + 1;

    while (atual <= d) {
        if(v[atual] < v[p]) {
            swap(v[k], v[atual]);
            k++;
        }
        atual++;
    }
    swap(v[p], v[k-1]);

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