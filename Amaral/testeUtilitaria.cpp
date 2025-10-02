#include <iostream>
#include "../includes/Utilitaria.h"

using namespace std;

int main() {
    Utilitaria::limparTela();
    Utilitaria::colorir(Utilitaria::BOLD, Utilitaria::RED);
    cout << "Teste de cor e efeito..." << endl;

    Utilitaria::aguardar(2000);
    Utilitaria::limparTela();

    Utilitaria::resetarCor();
    cout << "Teste de cor e efeito..." << endl;
    
    Utilitaria::aguardar(2000);
    Utilitaria::limparTela();
    
    Utilitaria::colorir(Utilitaria::ITALIC, Utilitaria::GREEN);
    cout << "Teste de cor e efeito..." << endl;
    Utilitaria::aguardar(2000);

    return 0;
}