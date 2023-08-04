#  Compartarisons


Seria sobre comparação entre dois objetos.

``` C++
#include <iostream> 
#include <typeinfo>


class Exemplo {
private:
  int valor;

public:
  Exemplo(int v) : valor(v) {}

    //vamos comparar atributo
  bool compare(const Exemplo& outro) const 
  {
    return valor == outro.valor;
  }
};

class Exemplo1 {
};



int main() {
  Exemplo obj1(10);
  Exemplo obj2(20);
  Exemplo obj3(10);
  Exemplo1 obj4;

  //comparando se o atributo tem mesmo valor, para isso criamos o metodo compare
  if (obj1.compare(obj2)) {
    std::cout << "obj1 tem mesmo valor obj2" << std::endl;
  }

  if (obj1.compare(obj3)) {
    std::cout << "obj1 tem mesmo valor  obj3" << std::endl;
  }

// comparando  endereço 
  if (&obj1 == &obj3) {
    std::cout << "obj1 e obj3 tem mesmo endereco" << std::endl;
  }
  if (&obj1 == &obj1) {
    std::cout << "obj1 e obj1 tem mesmo endereco" << std::endl;
  }

  // comparando objeto 
  if (typeid(obj1) == typeid(obj2)) {
    std::cout << "Os objetos são do mesmo tipo." << std::endl;
  } else {
    std::cout << "Os objetos são de tipos diferentes." << std::endl;
  }

  if (typeid(obj1) == typeid(obj4)) {
    std::cout << "Os objetos são do mesmo tipo." << std::endl;
  } else {
    std::cout << "Os objetos são de tipos diferentes." << std::endl;
  }

  return 0;
}


```


A saída será:

```
obj1 tem mesmo valor  obj3
obj1 e obj1 tem mesmo endereco
Os objetos são do mesmo tipo.
Os objetos são de tipos diferentes.
```

