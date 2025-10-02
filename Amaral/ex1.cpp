#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int TAM = 10;

using namespace std;

void exibir(vector<int> &v);
void ordenacao(vector<int> &v);
void preencher(vector<int> &v, int min, int max);

int main() {
    srand(time(NULL));
    vector<int> v(TAM);

    preencher(v, 1, 100);

    exibir(v);

    cout << endl;

    ordenacao(v);

    exibir(v);

    cout << endl;

    return 0;
}

void exibir(vector<int> &v) {
    for(auto a : v)
        cout << a << " ";
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

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = (rand() % (max - min + 1)) + min;
}