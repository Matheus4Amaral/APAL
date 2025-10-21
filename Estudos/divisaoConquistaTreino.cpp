#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

/* Solução com DIVISÃO E CONQUISTA (Funções)
1) Calcular o resultado de b^e
2) Somar os números naturais menores ou iguais a n
3) Retornar o menor valor em um vetor
4) Exibir o conteúdo de um vetor de inteiros (int* ou vector) do fim ao início
5) Exibir o conteúdo de um vetor de inteiros (int* ou vector) do início ao fim
*/

const int TAM = 5, b = 2, e = 5;

void exibe(vector<int> &v, int ini, int fim);
void exibeReverso(vector<int> &v, int ini, int fim);
int menor(vector<int> &v, int ini, int fim);
int pot(int b, int e);
void preenche(vector<int> &v, int min, int max);
int soma(vector<int> &v, int ini, int fim);

int main() {
    srand(time(NULL));
    vector<int> v(TAM);

    preenche(v, 1, 100);

    cout << "Exibe: ";
    exibe(v, 0, v.size()-1);
    cout << endl;

    cout << "Exibe reverso: ";
    exibeReverso(v, 0, v.size()-1);
    cout << endl;

    cout << "Menor elemento: " << menor(v, 0, v.size()-1) << endl;
    
    cout << "Soma: " << soma(v, 0, v.size()-1) << endl;

    cout << "Potencia de " << b << " elevado a " << e << ": " << pot(b, e) << endl;
    return 0;
}

void exibe(vector<int> &v, int ini, int fim) {
    if(fim < ini)
        return;
    
    cout << v[ini] << " ";
    exibe(v, ini + 1, fim);
}

void exibeReverso(vector<int> &v, int ini, int fim) {
    if(fim < ini)
        return;
    
    cout << v[fim] << " ";
    exibeReverso (v, ini, fim-1);
}

int menor(vector<int> &v, int ini, int fim) {
    if(fim <= ini)
        return v[ini];
    
    int m = ini + (fim-ini)/2;
    int m1 = menor(v, ini, m);
    int m2 = menor(v, m+1, fim);

    return (m1 <= m2) ? m1 : m2;
}

int pot(int b, int e) {
    if(e == 0)
        return 1;
    else if(e == 1)
        return b;
    
    return pot(b, ceil(e/2.)) * pot(b, floor(e/2.));
}

void preenche(vector<int> &v, int min, int max) {
    for(int i = 0; i < v.size(); i++)
        v[i] = min + rand() % (max - min + 1);
}

int soma(vector<int> &v, int ini, int fim) {
    if(fim <= ini)
        return v[fim];
    int m = floor(ini + (fim-ini)/2.);
    return soma(v, ini, m) + soma(v, 1 + m, fim);
}