A inicialização de membros por meio de uma lista de inicialização (initialization list) em C++ é uma forma eficiente e recomendada de inicializar os membros de uma classe durante a construção de um objeto.

A lista de inicialização é usada no construtor da classe e segue a declaração do construtor e dois pontos (`:`). Ela permite que você atribua valores aos membros da classe antes que o corpo do construtor seja executado. Isso é especialmente útil para inicializar membros constantes, membros que não possuem um construtor padrão ou membros que são referências ou constantes.

Aqui está um exemplo que demonstra o uso da lista de inicialização em C++:

```cpp
#include <iostream>
#include <string>

class Exemplo {
private:
  int valor;
  std::string nome;

public:
  // Construtor com lista de inicialização
  Exemplo(int v, const std::string& n) : valor(v), nome(n) {
    std::cout << "Construtor executado!" << std::endl;
  }

  void imprimirDados() {
    std::cout << "Valor: " << valor << std::endl;
    std::cout << "Nome: " << nome << std::endl;
  }
};

int main() {
  Exemplo obj(42, "Exemplo");

  obj.imprimirDados();

  return 0;
}
```

Neste exemplo, a classe `Exemplo` possui dois membros privados: `valor` e `nome`. No construtor da classe, usamos a lista de inicialização para atribuir valores aos membros da classe antes que o corpo do construtor seja executado.

Na linha `Exemplo(int v, const std::string& n) : valor(v), nome(n)`, `valor(v)` e `nome(n)` são a lista de inicialização. Eles atribuem os valores `v` e `n` aos membros `valor` e `nome`, respectivamente.

Ao executar o programa, obteremos a saída:

```
Construtor executado!
Valor: 42
Nome: Exemplo
```

O uso da lista de inicialização é preferível porque evita a necessidade de inicializar os membros no corpo do construtor, resultando em um código mais eficiente e legível. Além disso, é especialmente útil para inicializar membros constantes ou membros que não possuem um construtor padrão.