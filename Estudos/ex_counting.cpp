#include <iostream>
#include <vector>

using namespace std;

void counting_sort(vector<int> &v);

int main() {
    int n;
    cin >> n;

    vector<int> vet(n);
    for(int i = 0; i < n; i++)
        cin >> vet[i];
    /*for(int i = 0; i < n; i++)
        cout << vet[i] << ' ';
    cout << endl;*/

    /*counting_sort(vet);
    for(int i = 0; i < n; i++)
        cout << vet[i] << ' ';
    cout << endl;*/
    
    
    counting_sort(vet);
    

    return 0;
}

void counting_sort(vector<int> &v) {
    int maior = v[0], menor = v[0];

    // Identificação do tamanho do vetor (faixa de valores)
    for(int i = 1; i < v.size(); i++) {
        if(v[i] < menor)
            menor = v[i];
        if(v[i] > maior)
            maior = v[i];
    }

    vector<int> aux(maior - menor + 1);
    // Contagem (frequência)
    for(int i = 0; i < v.size(); i++)
        aux[v[i]-menor]++;
    
    // Soma de prefixos (frequência acumulada)
    for(int i = 1; i < aux.size(); i++)
        aux[i] += aux[i-1];
    
    // Organiza os dados de forma ordenada usando o vetor de frequência acumulada
    vector <int> vet(v.size());
    for (int i = v.size()-1; i >= 0; i--) {
        int idx = v[i] - menor;
        int val = aux[idx];
        vet[val-1] = v[i];
        aux[idx]--;
    }

    // Escreve os valores ordenados no vetor original
    for (int i = 0; i < v.size(); i++)
        v[i] = vet[i];
}
