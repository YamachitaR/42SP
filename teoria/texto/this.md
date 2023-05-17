
# This
Em C++, a palavra-chave `this` é um ponteiro implícito que aponta para o objeto atual em contexto dentro de uma função membro de uma classe. Ele é usado para referenciar os membros (atributos e métodos) desse objeto.

A utilização de `this` é especialmente útil em situações onde há ambiguidade entre nomes de variáveis locais e membros de um objeto. Ele permite diferenciar claramente o acesso aos membros da classe.

Aqui está um exemplo que ilustra o uso de `this` em C++:

```cpp
#include <iostream>

class Exemplo {
private:
  int valor;

public:
  Exemplo(int valor) : valor(valor) {}

  void imprimirValor() {
    std::cout << "Valor: " << this->valor << std::endl;
  }

  void alterarValor(int novoValor) {
    this->valor = novoValor;
  }
};

int main() {
  Exemplo obj(42);
  obj.imprimirValor();

  obj.alterarValor(99);
  obj.imprimirValor();

  return 0;
}
```

Neste exemplo, temos a classe `Exemplo` com um atributo `valor` e dois métodos: `imprimirValor()` e `alterarValor()`. Dentro desses métodos, usamos `this` para referenciar o atributo `valor` do objeto atual.

No método `imprimirValor()`, usamos `this->valor` para imprimir o valor do atributo `valor` do objeto atual.

No método `alterarValor()`, usamos `this->valor` para atribuir um novo valor ao atributo `valor` do objeto atual.

Ao executar o programa, obteremos a saída:

```
Valor: 42
Valor: 99
```

O uso de `this` ajuda a evitar ambiguidades ao acessar membros da classe e torna o código mais claro e legível. Ele permite que você se refira explicitamente aos membros do objeto atual dentro das funções membro.