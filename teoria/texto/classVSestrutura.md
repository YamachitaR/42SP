# Classe Vs estrutura 

Em C++, classes e estruturas são essencialmente iguais, com uma diferença principal: a visibilidade padrão dos membros.

Na classe, a visibilidade padrão dos membros é privada, enquanto na estrutura, a visibilidade padrão dos membros é pública.

Veja um exemplo de definição de classe e estrutura em C++:

```c++
// classe
class Pessoa {
private:
  int idade;
  std::string nome;

public:
  void setNome(std::string nome) {
    this->nome = nome;
  }

  std::string getNome() {
    return nome;
  }
};

// estrutura
struct Pessoa2 {
  int idade;
  std::string nome;
};
```

Neste exemplo, a classe `Pessoa` e a estrutura `Pessoa2` têm membros semelhantes. A classe `Pessoa` tem membros privados e públicos, enquanto a estrutura `Pessoa2` tem membros públicos.

Em geral, as classes são usadas para definir tipos de dados complexos com comportamentos específicos, enquanto as estruturas são usadas para agrupar dados simples.

Além disso, as classes são frequentemente usadas com herança, polimorfismo e encapsulamento para criar hierarquias de objetos complexas, enquanto as estruturas são usadas principalmente para armazenar dados simples em uma coleção.

Em resumo, as classes e estruturas em C++ são semelhantes, mas com diferenças na visibilidade padrão dos membros. A escolha entre usar uma classe ou estrutura depende da complexidade e comportamento dos dados que você deseja definir e como eles serão usados em seu programa.