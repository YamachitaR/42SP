Em C++, a palavra-chave `virtual` é usada antes da declaração de uma função membro na classe base para criar uma função virtual. Uma função virtual permite alcançar o polimorfismo de tempo de execução, também conhecido como polimorfismo dinâmico.

Quando uma função é declarada como virtual na classe base, ela pode ser substituída por uma implementação diferente nas classes derivadas. Isso significa que, quando você chama uma função virtual através de um ponteiro ou referência da classe base, o comportamento do programa dependerá do tipo real do objeto apontado ou referenciado.

Aqui está um exemplo que ilustra a utilização de uma função virtual:

```cpp
#include <iostream>

class Animal {
public:
    virtual void makeSound() const {
        std::cout << "Animal makes a generic sound." << std::endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const override {
        std::cout << "Dog barks: Woof! Woof!" << std::endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const override {
        std::cout << "Cat meows: Meow! Meow!" << std::endl;
    }
};

int main() {
    Animal* animalPtr = new Dog(); // Ponteiro para a classe base apontando para objeto derivado (Dog)
    animalPtr->makeSound(); // Output: "Dog barks: Woof! Woof!"

    animalPtr = new Cat(); // Ponteiro para a classe base apontando para outro objeto derivado (Cat)
    animalPtr->makeSound(); // Output: "Cat meows: Meow! Meow!"

    delete animalPtr;
    return 0;
}
```

Neste exemplo, temos uma classe base `Animal` com a função virtual `makeSound()`. Em seguida, temos duas classes derivadas `Dog` e `Cat`, ambas com suas próprias implementações da função `makeSound()`.

No `main()`, criamos um ponteiro `animalPtr` da classe base `Animal`, que inicialmente aponta para o objeto `Dog` (objeto da classe derivada). Quando chamamos `animalPtr->makeSound()`, a função `makeSound()` do objeto `Dog` é executada, mostrando "Dog barks: Woof! Woof!".

Em seguida, atribuímos o ponteiro `animalPtr` para o objeto `Cat` (outra classe derivada). Quando chamamos `animalPtr->makeSound()` novamente, a função `makeSound()` do objeto `Cat` é executada, mostrando "Cat meows: Meow! Meow!".

Isso é possível graças à função virtual, que permite que o método a ser chamado seja determinado em tempo de execução, dependendo do tipo real do objeto apontado ou referenciado. Sem a função virtual, o comportamento seria estático, e somente a implementação da classe base seria chamada, mesmo que o objeto apontado ou referenciado fosse uma classe derivada.