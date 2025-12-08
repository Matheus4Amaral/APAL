#include <iostream>
#include <map>
using namespace std;

struct PNode {
    bool fim = false;
    map<string, PNode*> filhos;
};

PNode* criarNoP() { return new PNode(); }

int prefixoComum(const string& a, const string& b) {
    int i = 0;
    while (i < a.size() && i < b.size() && a[i] == b[i]) i++;
    return i;
}

void imprimirPatricia(PNode* node, string prefixo) {
    if (node->fim)
        cout << prefixo << " (fim)" << endl;

    for (auto& par : node->filhos) {
        const string& edge = par.first;
        PNode* filho = par.second;
        imprimirPatricia(filho, prefixo + edge);
    }
}

void inserirP(PNode* node, const string& palavra) {
    for (auto it = node->filhos.begin(); it != node->filhos.end(); ++it) {
        const string& aresta = it->first;
        PNode* filho = it->second;
        int k = prefixoComum(aresta, palavra);

        if (k == 0) continue;

        if (k == aresta.size() && k < palavra.size()) {
            inserirP(filho, palavra.substr(k));
            return;
        }

        if (k == palavra.size() && k < aresta.size()) {
            string resto = aresta.substr(k);
            PNode* novo = criarNoP();
            novo->fim = true;
            novo->filhos[resto] = filho;

            node->filhos.erase(aresta);
            node->filhos[palavra] = novo;
            return;
        }

        if (k < aresta.size() && k < palavra.size()) {
            string restoA = aresta.substr(k);
            string restoP = palavra.substr(k);

            PNode* novo = criarNoP();
            novo->filhos[restoA] = filho;

            node->filhos.erase(aresta);
            node->filhos[aresta.substr(0, k)] = novo;

            inserirP(novo, restoP);
            return;
        }

        if (k == aresta.size() && k == palavra.size()) {
            filho->fim = true;
            return;
        }
    }

    PNode* novo = criarNoP();
    novo->fim = true;
    node->filhos[palavra] = novo;
}

// ---------------- Procura ----------------

bool procurarP(PNode* node, const string& palavra) {
    for (auto& par : node->filhos) {
        const string& aresta = par.first;
        PNode* filho = par.second;
        int k = prefixoComum(aresta, palavra);

        if (k == aresta.size() && k == palavra.size())
            return filho->fim;

        if (k == aresta.size() && k < palavra.size())
            return procurarP(filho, palavra.substr(k));
    }
    return false;
}

// ---------------- Remoção ----------------

bool removerRecP(PNode* node, const string& palavra) {
    for (auto it = node->filhos.begin(); it != node->filhos.end(); ++it) {

        string aresta = it->first;
        PNode* filho = it->second;

        int k = prefixoComum(aresta, palavra);
        if (k != aresta.size()) continue;

        if (k == palavra.size()) {
            if (!filho->fim) return false;
            filho->fim = false;

        } else {
            if (!removerRecP(filho, palavra.substr(k)))
                return false;
        }

        if (!filho->fim && filho->filhos.empty()) {
            node->filhos.erase(aresta);
            delete filho;
            return true;
        }

        if (!filho->fim && filho->filhos.size() == 1) {
            auto unico = filho->filhos.begin();
            string novaAresta = aresta + unico->first;

            node->filhos.erase(aresta);
            node->filhos[novaAresta] = unico->second;

            delete filho;
        }

        return true;
    }
    return false;
}

void removerP(PNode* raiz, const string& palavra) {
    removerRecP(raiz, palavra);
}

int main() {
    PNode* raiz = criarNoP();

    inserirP(raiz, "casa");
    inserirP(raiz, "caso");
    inserirP(raiz, "cara");

    //removerP(raiz, "casa");

    cout << procurarP(raiz, "casa") << endl; // 0
    cout << procurarP(raiz, "caso") << endl; // 1
    cout << procurarP(raiz, "cara") << endl; // 1

    imprimirPatricia(raiz, "");
}