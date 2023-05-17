# Acessors

Accessors, também conhecidos como getters e setters, são métodos de classe que permitem que o código externo acesse e modifique os membros privados da classe.

Em C++, os accessors são métodos públicos que são usados para acessar membros privados de uma classe, garantindo que a integridade dos dados seja mantida.

Os getters são métodos usados para acessar os valores dos membros privados, enquanto os setters são métodos usados para modificar esses valores.

Veja um exemplo de implementação de getters e setters em C++:

```c++
class Pessoa {
private:
  int idade;
  std::string nome;

public:
  int getIdade() {
    return idade;
  }

  void setIdade(int novaIdade) {
    idade = novaIdade;
  }

  std::string getNome() {
    return nome;
  }

  void setNome(std::string novoNome) {
    nome = novoNome;
  }
};
```

Neste exemplo, a classe `Pessoa` tem dois membros privados, `idade` e `nome`, e quatro métodos públicos, dois getters (`getIdade` e `getNome`) e dois setters (`setIdade` e `setNome`).

Os getters são usados para acessar os valores dos membros privados `idade` e `nome`, enquanto os setters são usados para modificar esses valores. Observe que os setters verificam se o novo valor é válido antes de modificá-lo, garantindo que os dados da classe permaneçam íntegros.

Em resumo, os accessors são métodos de classe usados para acessar e modificar membros privados de uma classe em C++. Eles garantem a integridade dos dados e ajudam a manter a encapsulação da classe.