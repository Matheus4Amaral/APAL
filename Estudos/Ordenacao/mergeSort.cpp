#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void exibir(vector<int> &vet);
void merge(vector<int> &v1, vector<int> &v2);
void merge(vector<int> &v, int e, int m, int d);
void mergeSort(vector<int> &vet, int e, int d);
bool ordenado(vector<int> &v);

int main() {
    srand(time(NULL));
    vector<int> v1 = {1,3,5,7,9,15,19,22};
    vector<int> v2 = {0,2,4,6,8,10,11,12,13,14,15};
    vector<int> v3 = {1,3,5,7,9,15,19,-22,0,2,4,6,8,10,11,12,13,14,15};

    /*merge(v1, v2);
    exibir(v3);
    cout << endl;*/
    
    /*merge(v3, 4, 6, 10);
    exibir(v3);
    cout << endl;*/

    int n;
    cin >> n;

    cout << n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        v[i] = 1 + rand()%100;

    cout << "\nOrdenado? " << (ordenado(v) ? "Sim" : "Nao") << endl;
    mergeSort(v, 0, v.size()-1);
    cout << "Ordenado? " << (ordenado(v) ? "Sim" : "Nao") << endl;

    return 0;
}

void exibir(vector<int> &vet) {
    for(auto v : vet)
        cout << v << " ";
}

/*
Função para união de dois vetores ordenados
Entrada: vetores 'v1' e 'v2'
Saída: Não tem
*/
void merge(vector<int> &v1, vector<int> &v2) {
    vector<int> vet(v1.size() + v2.size());
    int id_v1 = 0, id_v2 = 0, id_vet = 0;

    while(id_v1 < v1.size() && id_v2 < v2.size())
        if(v1[id_v1] <= v2[id_v2])
            vet[id_vet++] = v1[id_v1++];
        else
            vet[id_vet++] = v2[id_v2++];
    
    while(id_v1 < v1.size())
        vet[id_vet++] = v1[id_v1++];
    while(id_v2 < v2.size())
        vet[id_vet++] = v2[id_v2++];

    //exibir(vet);
}

/*
Função para união de dois subvetores ordenados
Entrada: vetor 'v1' e índices e, m, d
Saída: Não tem
*/
void merge(vector<int> &v, int e, int m, int d) {
    vector<int> vet(d - e + 1);

    int ide = e, idm = m+1, id = 0;
    while(ide <= m && idm <= d)
        if(v[ide] <= v[idm])
            vet[id++] = v[ide++];
        else
            vet[id++] = v[idm++];

    while(ide <= m)
        vet[id++] = v[ide++];
    while(idm <= d)
        vet[id++] = v[idm++];

    id = 0;
    for(int i = e; i <= d; i++)
        v[i] = vet[id++];
}

void mergeSort(vector<int> &v, int e, int d) {
    if(e >= d)
        return;
    
    int m = e + (d-e)/2;
    mergeSort(v, e, m);
    mergeSort(v, m+1, d);
    merge(v, e, m, d);
}

bool ordenado(vector<int> &v) {
    for(int i = 1; i < v.size(); i++)
        if(v[i] < v[i-1])
            return false;

    return true;
}