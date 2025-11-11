#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <fstream>

using namespace std;
using namespace chrono;

/*
Entrada: v (vetor de inteiros)
Saída: não tem
Exibe os elementos do vetor
*/
void exibir(vector<int> &v);
/*
Entrada: n (tamanho do heap), idx (índice do nó a ser ajustado)
Saída: não tem
Ajusta o heap para manter a propriedade de max-heap a partir do índice idx
*/
void heapify(vector<int> &v, int n, int idx);
/*
Entrada: v (vetor de inteiros), n (tamanho do vetor)
Saída: não tem
Ordena o vetor usando o algoritmo Heap Sort
*/
void heapSort(vector<int> &v, int n);
/*
Entrada: v (vetor de inteiros)
Saída: não tem
Constrói um max-heap a partir do vetor dado
*/
void maxHeap(vector<int> &v);
/*
Entrada: v (vetor de inteiros), e (índice inicial), m (índice do meio), d (índice final)
Saída: não tem
Mescla duas metades ordenadas do vetor em uma única sequência ordenada
*/
void merge(vector<int> &v, int e, int m, int d);
/*
Entrada: v (vetor de inteiros), e (índice inicial), d (índice final)
Saída: não tem
Ordena o vetor usando o algoritmo Merge Sort
*/
void mergeSort(vector<int> &v, int e, int d);
/*
Entrada: v (vetor de inteiros), min (valor mínimo), max (valor máximo)
Saída: não tem
Preenche o vetor com valores aleatórios entre min e max
*/
int particionamento(vector<int> &v, int e, int d);
/*
Entrada: v (vetor de inteiros), e (índice inicial), d (índice final)
Saída: não tem
Ordena o vetor usando o algoritmo Quick Sort
*/
void preencher(vector<int> &v, int min, int max);
/*
Entrada: v (vetor de inteiros), e (índice inicial), d (índice final)
Saída: não tem
Ordena o vetor usando o algoritmo Quick Sort
*/
void quickSort(vector<int> &v, int e, int d);

int main() {
    srand(time(NULL));

    int N = 1000000, passo = 10000;
    vector<int> v(N), original(N);

    preencher(v, 1, N);

    original = v;

    ofstream fout("dados.txt");
    if(!fout) {
        cerr << "Erro ao abrir dados.txt!" << endl;
        return 1;
    }

    for(int tam = passo; tam <= v.size(); tam += passo) {
        v = original;

        auto inicio = high_resolution_clock::now();
        quickSort(v, 0, tam - 1);
        //mergeSort(v, 0, tam - 1);
        //heapSort(v, tam);
        auto fim = high_resolution_clock::now();

        auto duracao = duration_cast<milliseconds>(fim - inicio).count();
        fout << tam << " " << duracao << endl;
    }

    fout.close();

    cout << "Arquivo dados.txt gerado com sucesso!" << endl;

    return 0;
}

void exibir(vector<int> &v) {
    for(auto i : v)
        cout << i << " ";
}

void heapify(vector<int> &v, int n, int idx) {
    int e, d, pai = idx;
    bool trocou = true;

    while(trocou) {
        trocou = false;
        e = 2 * pai + 1;
        d = 2 * pai + 2;

        if(e < n && v[pai] < v[e])
            pai = e;
        if(d < n && v [pai] < v[d])
            pai = d;
        if(pai != idx) {
            swap(v[pai], v[idx]);
            trocou = true;
            idx = pai;
        }
    }
}

void heapSort(vector<int> &v, int n) {
    maxHeap(v);
    while(n > 0) {
        swap(v[0], v[n - 1]);
        n--;
        heapify(v, n, 0);
    }
}

void maxHeap(vector<int> &v) {
    for(int idx = v.size() / 2 - 1; idx >= 0; idx--)
        heapify(v, v.size(), idx);
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
    if(d <= e)
        return;

    int m = e + (d - e) / 2;
    mergeSort(v, e, m);
    mergeSort(v, m + 1, d);
    merge(v, e, m, d);
}

void preencher(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = min + rand() % (max - min + 1);
}

int particionamento(vector<int> &v, int e, int d) {
    int pivo = e, k, atual;
    k = atual = e + 1;

    while(atual <= d) {
        if(v[atual] <= v[pivo]) 
            swap(v[k++], v[atual]);
        atual++;
    }

    swap(v[k - 1], v[pivo]);
    return k - 1;
}

void quickSort(vector<int> &v, int e, int d) {
    if(d <= e)
        return;
    
    int p = particionamento(v, e, d);
    quickSort(v, e, p - 1);
    quickSort(v, p + 1, d);
}