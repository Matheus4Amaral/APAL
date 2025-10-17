#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

void preencher(vector<int> &v, int min, int max);
void ordenacaoParcial(vector<int> &v, int tam);

int main() {
    srand(time(NULL));
    int N = 100000, passo = 1000;
    vector<int> v(N), original(N); 

    preencher(v, 1, N);

    original = v;

    ofstream fout("dados.txt");
    if(!fout) {
        cerr << "Erro ao abrir arquivo dados.txt" << endl;
        return 1;
    }

    for(int tam = passo; tam <= N; tam += passo) {
        v = original;

        auto ini = high_resolution_clock::now();
        ordenacaoParcial(v, tam);
        auto fim = high_resolution_clock::now();

        auto duracao = duration_cast<seconds>(fim - ini).count();

        fout << tam << " " << duracao << endl;
    }

    fout.close();

    return 0;
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = min + rand() % (max - min + 1);
}

void ordenacaoParcial(vector <int> &v, int tam) {
    for(int i = 1; i < tam; i++) {
        int chave = v[i], j = i - 1;
        while(j >= 0 && v[j] > chave) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }
}