#include <iostream>
#include <cmath>

using namespace std;

/* Solução com DIVISÃO E CONQUISTA (Funções)
1) Calcular o resultado de b^e
2) Somar os números naturais menores ou iguais a n
3) Retornar o menor valor em um vetor
4) Exibir o conteúdo de um vetor de inteiros (int* ou vector) do fim ao início
5) Exibir o conteúdo de um vetor de inteiros (int* ou vector) do início ao fim
*/

float pot(int b, int e);
int soma(int *vet, int ini, int fim);
int menor(int *vet, int ini, int fim);
void exibeReverso(int *vet, int ini, int fim);
void exibeNormal(int *vet, int ini, int fim);

int main() {
    /*for(int i = 0; i <= 10; i++) {
        printf("2^%d = %.0f\n", i, pot(2, i));
        printf("2^%d = %.0f\n", i, pow(2, i));
    }*/

    int vet[] = {1,2,3,4,5,6,7,8,9,10};
    // printf("soma: %d\n", soma(vet, 0, sizeof(vet)/sizeof(int) - 1));
    printf("menor: %d\n", menor(vet, 0, sizeof(vet)/sizeof(int) - 1));
    printf("exibe fim ao inicio: ");
    exibeReverso(vet, 0, sizeof(vet)/sizeof(int) - 1);
    printf("\nexibe inicio ao fim: ");
    exibeNormal(vet, 0, sizeof(vet)/sizeof(int) - 1);

    return 0;
}

int soma(int *vet, int ini, int fim) {
    if(fim - ini == 0)
        return vet[fim];

    return soma(vet, ini, floor((fim+ini)/2.)) + soma(vet, 1 + floor((fim+ini)/2.), fim);
}

float pot(int b, int e) {
    if(e == 0)
        return 1;
    else if(e == 1)
        return b;
    
    return pot(b, ceil(e/2.)) * pot(b, floor(e/2.));
}

int menor(int *vet, int ini, int fim) {
    if (ini == fim)
        return vet[ini];
    int meio = (ini + fim) / 2;
    int m1 = menor(vet, ini, meio);
    int m2 = menor(vet, meio + 1, fim);
    return (m1 < m2) ? m1 : m2;
}

void exibeReverso(int *vet, int ini, int fim) {
    if (fim < ini)
        return;
    printf("%d ", vet[fim]);
    exibeReverso(vet, ini, fim - 1);
}

void exibeNormal(int *vet, int ini, int fim) {
    if (fim < ini)
        return;
    printf("%d ", vet[ini]);
    exibeNormal(vet, ini + 1, fim);
}