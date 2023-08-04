# Namespaces

Namespace é um recurso da linguagem C++ que permite definir um escopo de identificadores. O objetivo é evitar conflitos entre nomes, permitindo que sejam criados identificadores com o mesmo nome em diferentes namespaces.

Por exemplo, se tivermos uma classe chamada "Pessoa" em um namespace "Empresa", e outra classe também chamada "Pessoa" em um namespace "Cliente", podemos diferenciar essas duas classes usando a sintaxe "Empresa::Pessoa" e "Cliente::Pessoa", respectivamente.

Os namespaces também podem ser aninhados, permitindo criar hierarquias de escopos, e podem ser definidos em arquivos diferentes, facilitando a modularização de código.

## Exemplo 1

```c++
#include <iostream>

namespace exemplo {
    int a = 5;
    void foo() {
        std::cout << "Olá do namespace exemplo!" << std::endl;
    }
}

int main() {
    exemplo::foo();
    std::cout << "Valor de a: " << exemplo::a << std::endl;
    return 0;
}
```

Neste exemplo, definimos um namespace chamado "exemplo", que contém uma variável inteira "a" e uma  função "foo". Dentro da função principal, podemos acessar os elementos do namespace utilizando o operador de resolução de escopo (::).

Saída: 

```c++
Olá do namespace exemplo!
Valor de a: 5
```

## Exemplo 2

Este exemplo é do video da 42 

```c++
# include <cstdio>

int    g_var = 1;

int    f(void) 
{
    return (2);
}

namespace    Foo 
{
    int    g_var = 3;
    int    f(void) 
    {
        return (4);
    }
}

namespace    Bar 
{
    int    g_var = 5;
    int    f(void) 
    {
        return (6);
    }
}

namespace     Muf = Bar;

int    main(void)
{
    // olhe cada um bloco e e imagine cada resultado de cada um 
    printf("g_var:            [%d]\n", g_var);
    printf("f():            [%d]\n\n", f());


    printf("::g_var:        [%d]\n", ::g_var);
    printf("::f():            [%d]\n\n", ::f());

    printf("Foo::g_var:        [%d]\n", Foo::g_var);
    printf("Foo::f():        [%d]\n\n", Foo::f());

    printf("Bar::g_var:        [%d]\n", Bar::g_var);
    printf("Bar::f():        [%d]\n\n", Bar::f());

    printf("Muf::g_var:        [%d]\n", Muf::g_var);
    printf("Muf::f():        [%d]\n\n", Muf::f());

    return (0);
}
```

Tente adivinha a saída, depois confira a abaixo 

```bash
g_var:            [1]
f():            [2]

::g_var:        [1]
::f():            [2]

Foo::g_var:        [3]
Foo::f():        [4]

Bar::g_var:        [5]
Bar::f():        [6]

Muf::g_var:        [5]
Muf::f():        [6]
```
