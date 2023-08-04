# non member attributes & functions

Em C++, os atributos e funções não membros são aqueles que não pertencem a uma classe específica. Eles são declarados e definidos fora do escopo de qualquer classe, geralmente no escopo global ou em um namespace.

Atributos não membros:
Um atributo não membro em C++ é uma variável que não está associada a nenhuma classe específica. Eles são declarados fora de qualquer classe e podem ser acessados globalmente em um arquivo de código ou em outros arquivos por meio de declarações de inclusão. Por exemplo:

```cpp
#include <iostream>

int valor_global = 10;  // Atributo não membro

int main() {
    std::cout << "Valor global: " << valor_global << std::endl;
    return 0;
}
```

Neste exemplo, `valor_global` é um atributo não membro. Ele é declarado fora de qualquer classe e pode ser acessado globalmente a partir da função `main()`.

Funções não membros:
Uma função não membro em C++ é uma função que não está associada a nenhuma classe específica. Elas são declaradas e definidas fora do escopo de qualquer classe e podem ser acessadas globalmente. Por exemplo:

```cpp
#include <iostream>

void exibirMensagem() {
    std::cout << "Olá, mundo!" << std::endl;
}

int main() {
    exibirMensagem();  // Chamada de função não membro
    return 0;
}
```

Neste exemplo, `exibirMensagem()` é uma função não membro. Ela é declarada e definida fora de qualquer classe e pode ser chamada globalmente a partir da função `main()`.

A utilização de atributos e funções não membros em C++ é útil quando você precisa de variáveis e funcionalidades que não estão diretamente associadas a uma classe específica. Eles podem ser usados para armazenar dados globais, implementar funções utilitárias, definir constantes globais, entre outros casos em que não faz sentido vinculá-los a uma classe específica.