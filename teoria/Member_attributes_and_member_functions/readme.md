# Introdução

Aborda classe, construtor, destrutor

## Criando uma classe

O nome da classe tem que ser  UpperCamelCase 

```c++
class Nome
```

## Modificador de acesso

```c++
class Nome
    private
```

Em C++, private é um modificador de acesso que pode ser usado dentro de uma classe. Ele indica que os membros ou funções declarados como private só podem ser acessados dentro da própria classe, ou seja, eles são privados e não podem ser acessados de fora da classe.

Por exemplo, se uma classe Carro tiver um membro velocidade definido como private, esse membro só pode ser acessado dentro da própria classe Carro e não pode ser acessado diretamente de fora da classe. Em vez disso, uma função membro setVelocidade() ou getVelocidade() pode ser definida dentro da classe para permitir que outros objetos interajam com o membro velocidade de maneira controlada.

A ideia por trás do uso de membros private é proteger os dados da classe de modificações ou acesso não autorizados de fora da classe.

## Construtor e destrutor

Em C++, construtor e destrutor são dois tipos especiais de métodos usados em classes para inicializar e destruir objetos, respectivamente.

Um construtor é um método especial que é chamado automaticamente quando um objeto é criado. Ele é responsável por inicializar o objeto, definindo valores para suas variáveis ​​de instância e executando outras tarefas de inicialização, se necessário. O construtor tem o mesmo nome da classe e não tem um tipo de retorno explícito.

Aqui está um exemplo simples de um construtor em C++:

```c++
class Pessoa {
public:
  Pessoa() {
    nome = "John Doe";
    idade = 30;
  }
  std::string nome;
  int idade;
};

int main() {
  Pessoa pessoa1;
  std::cout << pessoa1.nome << " tem " << pessoa1.idade << " anos." << std::endl;
  return 0;
}
```

O construtor padrão para a classe Pessoa define o nome como "John Doe" e a idade como 30. Quando um objeto Pessoa é criado, o construtor é chamado automaticamente e inicializa os valores.

Um destrutor é outro método especial em uma classe que é chamado automaticamente quando um objeto é destruído. Ele é responsável por liberar recursos alocados pelo objeto, como memória ou arquivos abertos. O destrutor tem o mesmo nome da classe, precedido por um til (~), e não tem um tipo de retorno explícito.

Aqui está um exemplo simples de um destrutor em C++:

```c++
class Arquivo {
public:
  Arquivo(std::string nomeArquivo) {
    arquivo = fopen(nomeArquivo.c_str(), "r");
  }
  ~Arquivo() {
    fclose(arquivo);
  }
  FILE* arquivo;
};

int main() {
  Arquivo arquivo1("arquivo.txt");
  // Faz alguma coisa com o arquivo
  return 0;
}
```

O destrutor para a classe Arquivo fecha o arquivo aberto pelo construtor, garantindo que não haja vazamento de recursos quando o objeto é destruído.

Note que, em ambos os exemplos, não foi necessário chamar explicitamente o construtor ou o destrutor. Eles são chamados automaticamente pelo sistema em momentos apropriados.