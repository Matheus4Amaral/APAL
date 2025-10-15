#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

/* Solução com DIVISÃO E CONQUISTA (Funções)
1) Calcular o resultado de b^e
2) Somar os números naturais menores ou iguais a n
3) Retornar o menor valor em um vetor
4) Exibir o conteúdo de um vetor de inteiros (int* ou vector) do fim ao início
5) Exibir o conteúdo de um vetor de inteiros (int* ou vector) do início ao fim
*/

const int TAM = 5;

void exibeReverso(int *vet, int ini, int fim);
void exibeNormal(int *vet, int ini, int fim);
int menor(int *vet, int ini, int fim);
float pot(int b, int e);
void preenche(int *vet, int TAM, int min, int max);
int soma(int *vet, int ini, int fim);

int main() {
    /*for(int i = 0; i <= 10; i++) {
        printf("2^%d = %.0f\n", i, pot(2, i));
        printf("2^%d = %.0f\n", i, pow(2, i));
    }*/
    srand(time(NULL));
    int vet[TAM];
    preenche(vet, TAM, 1, 100);

    printf("soma: %d\n", soma(vet, 0, sizeof(vet)/sizeof(int) - 1));
    printf("menor: %d\n", menor(vet, 0, sizeof(vet)/sizeof(int) - 1));
    printf("exibe fim ao inicio: ");
    exibeReverso(vet, 0, sizeof(vet)/sizeof(int) - 1);
    printf("\nexibe inicio ao fim: ");
    exibeNormal(vet, 0, sizeof(vet)/sizeof(int) - 1);

    cout << endl;

    return 0;
}

void exibeNormal(int *vet, int ini, int fim) {
    if (fim < ini)
        return;

    cout << vet[ini] << " ";
    exibeNormal(vet, ini + 1, fim);
}

void exibeReverso(int *vet, int ini, int fim) {
    if (fim < ini)
        return;

    cout << vet[fim] << " ";
    exibeReverso(vet, ini, fim - 1);
}

int menor(int *vet, int ini, int fim) {
    if (ini == fim)
        return vet[ini];
    int meio = (ini + fim) / 2;
    int m1 = menor(vet, ini, meio);
    int m2 = menor(vet, meio + 1, fim);
    return (m1 < m2) ? m1 : m2;
}

float pot(int b, int e) {
    if(e == 0)
        return 1;
    else if(e == 1)
        return b;
    
    return pot(b, ceil(e/2.)) * pot(b, floor(e/2.));
}

void preenche(int *vet, int TAM, int min, int max) {
    for(int i = 0; i < TAM; i++)
        vet[i] = min + rand() % (max - min + 1);
}

int soma(int *vet, int ini, int fim) {
    if(fim == ini)
        return vet[fim];

    return soma(vet, ini, floor((fim+ini)/2.)) + soma(vet, 1 + floor((fim+ini)/2.), fim);
}