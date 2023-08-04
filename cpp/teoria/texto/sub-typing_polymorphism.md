"Sub-typing polymorphism" (polimorfismo de subtipos) é um tipo de polimorfismo presente em linguagens de programação orientadas a objetos que permite que um objeto de um tipo específico possa ser tratado como um objeto de um de seus subtipos. Em outras palavras, um objeto de uma classe base pode ser usado onde um objeto de uma classe derivada é esperado.

O polimorfismo de subtipos é uma das formas de alcançar a "substituição de Liskov", um conceito importante em programação orientada a objetos que estabelece que um objeto de uma classe derivada deve ser capaz de ser substituído por um objeto da classe base sem afetar a corretude do programa.

Isso significa que, quando o polimorfismo de subtipos está presente, um objeto de uma classe derivada pode ser atribuído a um ponteiro ou referência da classe base, e as funções virtuais definidas na classe base podem ser invocadas com o objeto derivado.

Aqui está um exemplo em C++ que ilustra o polimorfismo de subtipos:

```cpp
#include <iostream>

class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() {
    Circle circle;
    Square square;

    Shape* shapePtr = &circle; // Ponteiro para a classe base apontando para objeto derivado
    shapePtr->draw(); // Output: "Drawing a circle."

    shapePtr = &square; // Ponteiro para a classe base apontando para outro objeto derivado
    shapePtr->draw(); // Output: "Drawing a square."

    return 0;
}
```

Neste exemplo, temos uma classe base `Shape` com uma função virtual `draw()`. Em seguida, temos duas classes derivadas `Circle` e `Square`, ambas com suas próprias implementações da função `draw()`.

No `main()`, criamos objetos `circle` e `square` das classes derivadas. Em seguida, criamos um ponteiro `shapePtr` da classe base `Shape`, que inicialmente aponta para o objeto `circle` (objeto da classe derivada). Quando chamamos `shapePtr->draw()`, a função `draw()` do objeto `circle` é executada, mostrando "Drawing a circle.".

Em seguida, atribuímos o ponteiro `shapePtr` para o objeto `square` (outra classe derivada). Quando chamamos `shapePtr->draw()` novamente, a função `draw()` do objeto `square` é executada, mostrando "Drawing a square.".

Isso é possível graças ao polimorfismo de subtipos, onde os objetos de classes derivadas podem ser tratados como objetos da classe base, permitindo a flexibilidade e a extensibilidade do código orientado a objetos.