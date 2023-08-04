Em C++, a palavra-chave `const` é usada para declarar uma variável, parâmetro de função ou membro de classe como uma entidade constante, ou seja, seu valor não pode ser modificado após a sua inicialização. A utilização do `const` ajuda a garantir a imutabilidade de certos elementos do programa e a prevenir erros de modificação acidental.

Aqui estão alguns exemplos de uso do `const` em C++:

1. Declaração de uma variável constante:
```cpp
const int valor = 10;
```
Nesse exemplo, a variável `valor` é declarada como constante e recebe o valor inicial de 10. Qualquer tentativa de modificar o valor de `valor` resultará em um erro de compilação.

2. Parâmetro de função constante:
```cpp
void imprimirValor(const int valor) {
  std::cout << "Valor: " << valor << std::endl;
}
```
Nesse exemplo, o parâmetro `valor` da função `imprimirValor` é declarado como constante. Isso significa que a função não pode modificar o valor do parâmetro. Essa é uma forma de garantir que a função não altere acidentalmente o valor do argumento passado.

3. Membro de classe constante:
```cpp
class Exemplo {
private:
  const int valor;

public:
  Exemplo(int v) : valor(v) {}
  int getValor() const {
    return valor;
  }
};
```
Nesse exemplo, o membro `valor` da classe `Exemplo` é declarado como constante. Isso significa que, uma vez inicializado no construtor, o valor não pode ser alterado. O método `getValor()` é declarado como constante, o que indica que ele não modifica o estado interno do objeto.

O `const` também pode ser usado em outros contextos, como ponteiros, referências e funções membros de classes. Em geral, seu objetivo é indicar que uma entidade não deve ser modificada após a sua inicialização.

É importante notar que o `const` é uma garantia do programador e uma dica para o compilador, mas não impede a modificação direta de uma variável por meio de ponteiros ou outras técnicas avançadas. No entanto, seu uso adequado ajuda a manter a integridade e a legibilidade do código.