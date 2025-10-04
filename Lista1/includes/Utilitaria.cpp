#include <iostream>
#include <cstdlib>
#include "Utilitaria.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void Utilitaria::aguardar(int milisegundos) {
    #ifdef _WIN32
        Sleep(milisegundos);
    #else
        usleep(1000*milisegundos);
    #endif
}

void Utilitaria::colorir(Utilitaria::Efeito e, Utilitaria::Cor c) {
    std::cout << "\033[" << int(e) << ";" << int(c) << "m";
}

void Utilitaria::limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Utilitaria::resetarCor() {
    std::cout << "\033[0;0m";
}