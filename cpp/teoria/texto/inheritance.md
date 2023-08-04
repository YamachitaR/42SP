Herança é um conceito fundamental na programação orientada a objetos (POO) que permite criar uma hierarquia de classes, onde as classes derivadas herdam propriedades e comportamentos das classes base.

A herança promove a reutilização de código e permite a criação de classes especializadas que herdam e estendem a funcionalidade de classes mais gerais. Ela permite que você defina uma classe base com atributos e métodos comuns e, em seguida, crie classes derivadas que herdam esses atributos e métodos, adicionando suas próprias características exclusivas.

Em C++, a herança é implementada usando a palavra-chave `class` seguida de dois pontos (`:`) e o especificador de acesso (`public`, `private` ou `protected`), seguido pelo nome da classe base. Existem três tipos de herança em C++:

1. Herança pública: Os membros públicos da classe base são acessíveis como membros públicos da classe derivada. Os membros protegidos da classe base são acessíveis como membros protegidos da classe derivada. Os membros privados da classe base não são acessíveis diretamente pela classe derivada.

2. Herança privada: Todos os membros da classe base são herdados como membros privados pela classe derivada. Isso significa que eles não são acessíveis diretamente pela classe derivada, mas ainda podem ser usados dentro do escopo da classe derivada.

3. Herança protegida: Todos os membros da classe base são herdados como membros protegidos pela classe derivada. Isso significa que eles não são acessíveis diretamente pela classe derivada, mas ainda podem ser usados dentro do escopo da classe derivada e de suas classes derivadas.

Para derivar uma classe a partir de uma classe base em C++, usa-se a seguinte sintaxe:

```cpp
class ClasseDerivada : especificador-de-acesso ClasseBase {
    // Membros e funções adicionais específicos da classe derivada
};
```

Dentro da classe derivada, você tem acesso aos membros (variáveis e funções) herdados da classe base. Você também pode adicionar novos membros ou substituir os existentes para modificar o comportamento da classe derivada.

A herança permite a reutilização de código, extensibilidade e polimorfismo. O polimorfismo permite que objetos das classes derivadas sejam tratados como objetos da classe base, fornecendo flexibilidade e permitindo a implementação de funcionalidades comuns para a classe base, compartilhadas por todas as classes derivadas.

Em resumo, a herança em C++ permite criar uma hierarquia de classes onde as classes derivadas herdam propriedades e comportamentos das classes base. É um recurso importante da POO que promove a reutilização de código, extensibilidade e polimorfismo.