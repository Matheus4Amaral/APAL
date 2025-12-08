#include <iostream>
#include <map>
using namespace std;

struct TrieNode {
    map<char, TrieNode*> filhos;
    bool fim = false;
};

TrieNode* criarNo() { return new TrieNode(); }

void imprimirTrie(TrieNode* node, string prefixo) {
    if (node->fim)
        cout << prefixo << " (fim)" << endl;

    for (auto& par : node->filhos) {
        char c = par.first;
        TrieNode* filho = par.second;
        imprimirTrie(filho, prefixo + c);
    }
}

// Inserir padrão
void inserir(TrieNode* raiz, const string& palavra) {
    TrieNode* atual = raiz;
    for (char c : palavra) {
        if (!atual->filhos.count(c))
            atual->filhos[c] = criarNo();
        atual = atual->filhos[c];
    }
    atual->fim = true;
}

// Procurar padrão
bool procurar(TrieNode* raiz, const string& palavra) {
    TrieNode* atual = raiz;
    for (char c : palavra) {
        if (!atual->filhos.count(c)) return false;
        atual = atual->filhos[c];
    }
    return atual->fim;
}

// Função recursiva para remoção
bool removerRec(TrieNode* node, const string& palavra, int idx) {
    if (idx == palavra.size()) {
        if (!node->fim) return false; // palavra não existe
        node->fim = false;

        return node->filhos.empty();
    }

    char c = palavra[idx];
    if (!node->filhos.count(c))
        return false;

    TrieNode* filho = node->filhos[c];
    bool apagarFilho = removerRec(filho, palavra, idx + 1);

    if (apagarFilho) {
        delete filho;
        node->filhos.erase(c);
    }

    return node->filhos.empty() && !node->fim;
}

void remover(TrieNode* raiz, const string& palavra) {
    removerRec(raiz, palavra, 0);
}

// ----------------------

int main() {
    TrieNode* raiz = criarNo();

    inserir(raiz, "casa");
    inserir(raiz, "caso");

    //remover(raiz, "casa");

    cout << procurar(raiz, "casa") << endl; // 0
    cout << procurar(raiz, "caso") << endl; // 1

    imprimirTrie(raiz, "");
}