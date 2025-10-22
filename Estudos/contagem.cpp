#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const int TAM = 100;

void contagem(vector<int> &v);
void exibir(vector<int> &v);
void preencher(vector<int> &v, int min, int max);

int main() {
    srand(time(NULL));
    vector<int> v(TAM);

    preencher(v, 1, 20);

    exibir(v);
    cout << endl;

    contagem(v);

    cout << endl;
    exibir(v);
    cout << endl;

    return 0;
}
    /*
        v = {1, 5, 2, 1, 3}
        aux = {0, 2, 1, 1, 0, 5}
    */
void contagem(vector<int> &v) {
    int max = v[0], min = v[0];
    for(int i = 1; i < v.size(); i++) {
        if(min > v[i])
            min = v[i];
        if(max < v[i])
            max = v[i];
    }

    vector<int> aux(max - min + 1);

    for(int i = 0; i < aux.size(); i++) 
        aux[v[i]-min]++;
    
    for(int i = 1; i < v.size(); i++)
        aux[i] += aux[i-1];

    vector<int> ord(v.size());
    for(int i = v.size()-1; i >= 0; i--) {
        int idx = v[i] - min, val = aux[idx];
        ord[val-1] = v[i];
        aux[idx]--;
    }
}

void exibir(vector<int> &v) {
    for(auto i : v)
        cout << i << " ";
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = min + rand() % (min + max + 1);
}