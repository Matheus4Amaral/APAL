void ordenacaoPorInsercaoParcial(vector<int> &v, int tam);
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

void exibir(vector<int> &v);
void ordenacaoPorInsercao(vector<int> &v);
void preencher(vector<int> &v, int min, int max);

int main() {
	srand(time(NULL));

	int n = 1000000, passo = 10000;
	vector<int> v(n), original(n);

	preencher(v, 1, n);
	original = v;

	ofstream fout("dados.txt");
	if (!fout) {
		cerr << "Erro ao abrir dados.txt" << endl;
		return 1;
	}

	for (int i = passo; i <= n; i += passo) {
		v = original;
		auto inicio = high_resolution_clock::now();
		ordenacaoPorInsercaoParcial(v, i);
		auto fim = high_resolution_clock::now();
		auto duracao = duration_cast<milliseconds>(fim - inicio).count();
		fout << i << " " << duracao << endl;
		cout << "Ordenado: " << i << " elementos em " << duracao << " ms" << endl;
	}

	fout.close();
	return 0;
}

void exibir(vector<int> &v) {
    for(auto a : v)
        cout << a << " ";
}

void ordenacaoPorInsercao(vector<int> &v) {
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

// Ordena apenas os primeiros 'tam' elementos do vetor v usando inserção
void ordenacaoPorInsercaoParcial(vector<int> &v, int tam) {
	for (int j = 1; j < tam; j++) {
		int chave = v[j];
		int k = j - 1;
		while (k >= 0 && v[k] > chave) {
			v[k + 1] = v[k];
			k = k - 1;
		}
		v[k + 1] = chave;
	}
}


void preencher(vector<int> &v, int min, int max) {
	for (int i = 0; i < v.size(); i++)
		v[i] = (rand() % (max - min + 1)) + min;
}