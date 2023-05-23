
#include <iostream> 
#include <typeinfo>

#include <iostream>

class Exemplo {
public:
    void imprimirMensagem() {
        std::cout << "Olá, mundo!" << std::endl;
    }
};

int main() {
    void (Exemplo::*ponteiro_para_membro)();

    Exemplo obj;
    ponteiro_para_membro = &Exemplo::imprimirMensagem;

    (obj.*ponteiro_para_membro)();

    return 0;
}

