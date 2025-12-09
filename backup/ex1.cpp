#include <iostream>
#include <map>
using namespace std;

// -----------------------------
// ESTRUTURA DA TRIE
// -----------------------------
struct TrieNode {
    bool fim;
    map<char, TrieNode*> filhos;
};

TrieNode* criarNo() {
    TrieNode* no = new TrieNode();
    no->fim = false;
    return no;
}

// -----------------------------
// INSERIR
// -----------------------------
void inserir(TrieNode* raiz, const string &palavra) {
    TrieNode* atual = raiz;
    for (char c : palavra) {
        if (!atual->filhos[c])
            atual->filhos[c] = criarNo();
        atual = atual->filhos[c];
    }
    atual->fim = true;
}

// -----------------------------
// ENCONTRAR PREFIXO
// -----------------------------
TrieNode* encontrarPrefixo(TrieNode* raiz, const string &prefixo) {
    TrieNode* atual = raiz;
    for (char c : prefixo) {
        if (!atual->filhos.count(c))
            return nullptr;
        atual = atual->filhos[c];
    }
    return atual;
}

// -----------------------------
// IMPRESSÃO
// -----------------------------
void imprimirTrie(TrieNode* no, string prefixo) {
    if (no->fim)
        cout << prefixo << " (fim)" << endl;

    for (auto &p : no->filhos)
        imprimirTrie(p.second, prefixo + p.first);
}

// -----------------------------
// EXERCÍCIO 2 — AUTOCOMPLETE
// -----------------------------
int main() {
    TrieNode* raiz = criarNo();

    string produtos[] = {"camisa", "camisola", "camiseta", "cama", "caneca", "canoeiro"};
    for (auto &p : produtos)
        inserir(raiz, p);

    string prefixo = "cam";

    cout << "Palavras que comecam por '" << prefixo << "':\n";
    TrieNode* sub = encontrarPrefixo(raiz, prefixo);

    if (!sub)
        cout << "Nenhuma encontrada\n";
    else
        imprimirTrie(sub, prefixo);

    return 0;
}