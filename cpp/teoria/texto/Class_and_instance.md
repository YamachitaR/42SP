# Class and instance 

## Classe

Uma classe em C++ é uma construção fundamental que permite definir um tipo de dado personalizado com atributos (variáveis) e métodos (funções) relacionados. As classes são usadas para modelar objetos do mundo real ou abstrato, encapsulando dados e comportamentos relacionados em uma única entidade.

Aqui está um exemplo básico de uma classe em C++:

```cpp
class Carro {
private:
  int velocidade;
  std::string modelo;

public:
  // Construtor
  Carro(int v, std::string m) : velocidade(v), modelo(m) {}

  // Método para obter a velocidade
  int getVelocidade() {
    return velocidade;
  }

  // Método para definir a velocidade
  void setVelocidade(int v) {
    velocidade = v;
  }

  // Método para obter o modelo
  std::string getModelo() {
    return modelo;
  }

  // Método para definir o modelo
  void setModelo(std::string m) {
    modelo = m;
  }

  // Outros métodos...
};
```

Neste exemplo, temos a classe `Carro` com dois atributos privados: `velocidade` e `modelo`. Em seguida, temos os métodos públicos (funções) que permitem acessar e modificar esses atributos, usando os métodos `get` e `set`.

Além disso, temos um construtor que é usado para inicializar os atributos do objeto no momento da criação. No caso do exemplo, o construtor recebe a velocidade e o modelo do carro e atribui esses valores aos atributos correspondentes.

Uma vez definida a classe, podemos criar objetos dessa classe no programa principal:

```cpp
int main() {
  // Criando objetos da classe Carro
  Carro carro1(100, "Ferrari");
  Carro carro2(60, "Ford");

  // Acessando e modificando atributos
  int velocidadeCarro1 = carro1.getVelocidade();
  std::cout << "Velocidade do carro 1: " << velocidadeCarro1 << std::endl;

  carro2.setModelo("BMW");
  std::string modeloCarro2 = carro2.getModelo();
  std::cout << "Modelo do carro 2: " << modeloCarro2 << std::endl;

  return 0;
}
```

Neste trecho do código, criamos dois objetos `Carro` usando o construtor da classe. Em seguida, usamos os métodos públicos para acessar e modificar os atributos desses objetos.

As classes em C++ oferecem muitos recursos além do básico apresentado aqui, como herança, polimorfismo, encapsulamento, sobrecarga de operadores e muito mais. Elas fornecem um mecanismo poderoso para organizar e modularizar o código, permitindo a criação de programas orientados a objetos eficientes e fáceis de manter.


## Instancia 
Uma instância de uma classe em C++ é um objeto criado a partir da definição dessa classe. Uma vez que uma classe é definida, podemos criar múltiplas instâncias ou objetos dessa classe no programa.

Para criar uma instância de uma classe, usamos o operador `new` seguido do nome da classe, seguido por parênteses. Aqui está um exemplo:

```cpp
// Definição da classe Carro
class Carro {
  // ...
};

int main() {
  // Criando uma instância da classe Carro
  Carro* meuCarro = new Carro();

  // ...

  // Liberando a memória alocada
  delete meuCarro;

  return 0;
}
```

No exemplo acima, criamos uma instância da classe `Carro` usando o operador `new`. A instância é armazenada em um ponteiro `meuCarro` do tipo `Carro*`. Podemos acessar os membros da instância usando o operador seta `->`.

Depois de usar a instância e não precisar mais dela, é importante liberar a memória alocada por ela usando o operador `delete`. Isso é necessário para evitar vazamentos de memória.

Podemos criar várias instâncias de uma classe, cada uma com seu próprio conjunto de atributos e comportamentos. Cada instância é independente das outras e pode ser acessada e manipulada separadamente.

```cpp
int main() {
  // Criando várias instâncias da classe Carro
  Carro* carro1 = new Carro();
  Carro* carro2 = new Carro();
  Carro* carro3 = new Carro();

  // Acessando e manipulando as instâncias
  carro1->setVelocidade(100);
  int velocidadeCarro2 = carro2->getVelocidade();

  // ...

  // Liberando a memória alocada
  delete carro1;
  delete carro2;
  delete carro3;

  return 0;
}
```

Neste exemplo, criamos três instâncias diferentes da classe `Carro`. Cada instância pode ter seus próprios valores para os atributos e os métodos podem ser chamados individualmente em cada instância.

É importante lembrar de liberar a memória alocada para cada instância usando o `delete` quando não precisarmos mais delas para evitar vazamentos de memória.





## Construtor

Construtor seria uma "metodo especial"  (metodo na POO é função), que é chamado ao criar um objeto (Objeto é nome ao chamar a classe)



## Metodo 

Metodo é como é denominado função na Orietntação Objeto 


## Atributo 

Atributo é a forma que é chamado as variáveis na Orientação Objeto 







