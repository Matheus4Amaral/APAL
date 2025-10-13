#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v);
void exibir(vector<int> &v);
void preencher(vector<int> &v, int min, int max);

const int TAM = 30; // #define TAM 30

int main() {
    srand(time(NULL));
    vector<int> v(TAM);
    
    preencher(v, 1, 100);
    exibir(v);
    cout << endl;

    bubbleSort(v);
    exibir(v);
    cout << endl;

    return 0;
}

void bubbleSort(vector<int> &v) {
    bool trocou = true;
    while(trocou) {
        trocou = false;
        for(int i = 1; i < v.size(); i++) {
            if(v[i] < v[i - 1]) {
                int aux = v[i];
                v[i] = v[i - 1];
                v[i - 1] = aux;
                trocou = true;
            }
        }
    }
}

void exibir(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        int a = v[i];
        cout << a << " ";
    }
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = min + rand()%(max - min + 1);      // min + rand()%(qtde) => qtde = max - min + 1
}