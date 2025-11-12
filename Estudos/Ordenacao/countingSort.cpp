#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void countingSort(vector<int> &v);
void exibir(vector<int> &v);
void preencher(vector<int> &v, int min, int max);

const int TAM = 30; // #define TAM 30

int main() {
    srand(time(NULL));
    vector<int> v(TAM);
    
    preencher(v, 1, 100);
    exibir(v);
    cout << endl;

    countingSort(v);
    exibir(v);
    cout << endl;

    return 0;
}

void countingSort(vector<int> &v) {
    int menor = v[0], maior = v[0];
    for(int i = 1; i < v.size(); i++) {
        if(menor > v[i])
            menor = v[i];
        if(maior < v[i])
            maior = v[i];
    }

    vector<int> freq(maior - menor + 1);

    for(int i = 0; i < v.size(); i++)
        freq[v[i] - menor]++;
    
    for(int i = 1; i < freq.size(); i++)
        freq[i] += freq[i - 1];

    vector<int> ord(v.size());

    for(int i = v.size()-1; i >= 0; i--) {
        int idx = v[i] - menor;
        int val = freq[idx];
        ord[val - 1] = v[i];
        freq[idx]--;
    }

    for(int i = 0; i < v.size(); i++)
        v[i] = ord[i];
}

void exibir(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        int a = v[i];
        cout << a << " ";
    }
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = min + rand()%(max - min + 1);
}