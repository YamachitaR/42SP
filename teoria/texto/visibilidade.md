# Visibilidade

Visibilidade em programação orientada a objetos se refere às regras que controlam o acesso aos membros de uma classe. Em outras palavras, a visibilidade define quais membros de uma classe podem ser acessados por outras partes do programa.

Em C++, há três níveis de visibilidade: `public`, `private` e `protected`.

- `public`: membros públicos podem ser acessados por qualquer parte do programa. Geralmente, métodos públicos são usados para permitir que outras classes acessem e manipulem os dados de uma classe.

- `private`: membros privados são acessíveis somente dentro da própria classe. Isso significa que outras partes do programa não podem acessar esses membros diretamente. Membros privados são geralmente usados para armazenar dados internos da classe que não devem ser acessados de fora.

- `protected`: membros protegidos são semelhantes aos membros privados, mas podem ser acessados por classes derivadas (herdeiras) da classe que os define.

Aqui está um exemplo de como definir a visibilidade dos membros de uma classe em C++:

```c++
class Exemplo {
public: // membros públicos
  void metodoPublico();
  int atributoPublico;

protected: // membros protegidos
  void metodoProtegido();
  int atributoProtegido;

private: // membros privados
  void metodoPrivado();
  int atributoPrivado;
};
```

Neste exemplo, a classe `Exemplo` tem membros públicos, protegidos e privados. Os métodos e atributos públicos podem ser acessados por qualquer parte do programa, enquanto os membros protegidos e privados só podem ser acessados dentro da própria classe ou por suas classes derivadas.

Em resumo, a visibilidade em C++ é uma ferramenta poderosa para controlar o acesso aos membros de uma classe. Ao definir a visibilidade corretamente, podemos garantir a segurança e a consistência do nosso códig