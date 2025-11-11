#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

int main() {
    string file1, file2;
    cout << "Digite o nome do primeiro arquivo: ";
    cin >> file1;
    cout << endl;
    cout << "Digite o nome do segundo arquivo: ";
    cin >> file2;

    ifstream arq1(file1);
    ifstream arq2(file2);
    ofstream arq3("resultado.txt");

    if (!arq1 || !arq2) {
        cerr << "Erro ao abrir arquivos de entrada!" << endl;
        return 1;
    }

    if (!arq3) {
        cerr << "Erro ao criar arquivo de saida!" << endl;
        return 1;
    }

    vector<bool> maiusculas(26, false), minusculas(26, false);
    char c1, c2;

    while (arq1.get(c1)) // O(n), varia de acordo com o tamanho do arquivo
        if (isupper(c1)) 
            maiusculas[c1 - 'A'] = true;
        else if (islower(c1)) 
            minusculas[c1 - 'a'] = true;

    while (arq2.get(c2)) // O(n), varia de acordo com o tamanho do arquivo
        if (isupper(c2)) 
            maiusculas[c2 - 'A'] = true;
        else if (islower(c2)) 
            minusculas[c2 - 'a'] = true;

    // Escreve primeiro as maiusculas e remove suas minusculas correspondentes
    for (int i = 0; i < 26; i++)
        if (maiusculas[i]) {
            arq3.put(i + 'A');
            minusculas[i] = false;
        }
    
    // Escreve as minusculas restantes
    for (int i = 0; i < 26; i++) 
        if (minusculas[i]) 
            arq3.put(i + 'a');
        
    arq1.close();
    arq2.close();
    arq3.close();

    cout << endl << "Arquivo resultado.txt gerado com sucesso!" << endl;

    // Tempo de complexidade: O(n)
    // O restante do codigo onde nao tem comentarios dizendo a complexidade possui complexidade O(1)

    return 0;
}
