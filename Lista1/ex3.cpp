#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

void preencher(vector<int> &v, int min, int max);
void ordenacaoPorInsercaoParcial(vector<int> &v, int tam);

int main() { // quadratico (método omega n ou método O quadratico). o tempo de execução cresce quadraticamente em relação ao tamanho da parte ordenada
	srand(time(NULL)); // constante (notação mais restrita 1)

	int N = 1000000, passo = 1000; // constante (notação mais restrita 1)
	vector<int> v(N), original(N); // constante (notação mais restrita 1)

	preencher(v, 1, N); // linear (notação mais restrita n)

	original = v; // constante (notação mais restrita 1)

	ofstream fout("dados.txt"); // constante (notação mais restrita 1)
	if (!fout) { // constante (notação mais restrita 1)
		cerr << "Erro ao abrir dados.txt" << endl; // 0 ou constante (notação mais restrita 1)

		return 1; // 0 ou constante (notação mais restrita 1)
	}

	// para rodar em baixo, nao pode executar o escopo do if. caso rode, td o restante é 0. para análise, consideraremos que nao tenha executado o escopo da estrutura condicional
	for (int tam = passo; tam <= N; tam += passo) { // linear (notação mais restrita n)
		v = original; // constante * linear (notação mais restrita n)

		auto inicio = high_resolution_clock::now(); // constante * linear (notação mais restrita n)
		ordenacaoPorInsercaoParcial(v, tam); // quadratico (notação mais restrita n^2)
		auto fim = high_resolution_clock::now(); // constante * linear (notação mais restrita n)

		auto duracao = duration_cast<seconds>(fim - inicio).count(); // constante * linear (notação mais restrita n)
		fout << tam << " " << duracao << endl; // constante * linear (notação mais restrita n)
	}

	fout.close(); // constante (notação mais restrita 1)

	return 0; // constante (notação mais restrita 1)
}

void preencher(vector<int> &v, int min, int max) { // linear (notação mais restrita n)
	for (int i = 0; i < v.size(); i++) // linear (notação mais restrita n)
		v[i] = (rand() % (max - min + 1)) + min; // constante * linear (notação mais restrita n)
}

void ordenacaoPorInsercaoParcial(vector<int> &v, int tam) { // quadratico (notação mais restrita n^2)
	for (int i = 1; i <= tam - 1; i++) { // quadratico (notação mais restrita n^2)
		int chave = v[i]; // constante (notação mais restrita 1)
		int j = i - 1; // constante (notação mais restrita 1)
		while (j >= 0 && v[j] > chave) { // linear * linear (notação mais restrita n^2)
			v[j + 1] = v[j]; // constante * linear (notação mais restrita n)
			j = j - 1; // constante * linear (notação mais restrita n)
		}
		v[j + 1] = chave; // constante * linear (notação mais restrita n)
	}
}