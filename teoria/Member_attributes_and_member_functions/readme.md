# Introdução 

Aborda classe, construtor, destrutor

##  Criando uma classe

O nome da classe tem que ser  UpperCamelCase 
~~~ c++
class Nome

~~~

## Modificador de acesso 

~~~ c++
class Nome
    private
~~~

Em C++, private é um modificador de acesso que pode ser usado dentro de uma classe. Ele indica que os membros ou funções declarados como private só podem ser acessados dentro da própria classe, ou seja, eles são privados e não podem ser acessados de fora da classe.

Por exemplo, se uma classe Carro tiver um membro velocidade definido como private, esse membro só pode ser acessado dentro da própria classe Carro e não pode ser acessado diretamente de fora da classe. Em vez disso, uma função membro setVelocidade() ou getVelocidade() pode ser definida dentro da classe para permitir que outros objetos interajam com o membro velocidade de maneira controlada.

A ideia por trás do uso de membros private é proteger os dados da classe de modificações ou acesso não autorizados de fora da classe.

## Construtor

