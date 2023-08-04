
# PIPEX

Este projeto é proposto pela Escola 42SP, tem como objetivo trabalhar com pipe e prepara para o projeto Minishell (criação de shell). Podemos dizer que PIPEX é um microshell.

## 42SP

A Escola Escola 42SP é uma franquia da 42 de Paris, que é considera uma das melhores escola de programação do mundo!
O ensino é diferente de tudo que você já viu na sua vida! o melhor de tudo é de graça. Hoje existe 42 Rio de Janeiro, mas esta em expansão veja se tem um perto da sua casa.
Caso você precisa de ajuda para fazer o projeto, pode contar comigo!
Agradeço a Deus, a Comunidade e o Bocal!

Agrecimento especial aos cadetes: jmilson-, lemarque, lucasmar, rkenji-s e vcastilh


## Como rodar o programa?

Temos duas versões pipex1 e pipex2, sendo o pipex2 um pouco mais complexo do que pipex1

Apos fazer o git clone, entre na pasta (pipex1 ou pepex2) e dÊ um "make". Se dê tudo certo prosseguimos, caso contrario veja se é necessário instalar algum pacote. 


### Pipex1

Para executar basta fazer 
 ```bash
./pipex file1 cmd_1 cmd_2 file2
```
onde:
- /pipex nome do executável;
- file1: Arquivo de entrada;
- file2 : arquivo de saída do resultado;
- cmd_1:  comando e
- cmd_2: comando;

Equivalente fazer < file1 cmd1 | cmd2 > file2  no bash 


**Observações:**

- Necessário que o file1 exista, mesmo que não seja necessário;
- é necessário colocar os 4 argumentos (file1, cmd1, cmd2 e file2) e a ordem importa.
- Caso o comando tem opção manda com aspa dupla;

**Alguns exemplo:** 

1. Vamos gravar a quantidade de linha que tem de resultado o comando 'ls -l' no arquivo 'out.txt'
  ```
  ./pipex main.c "ls -l" "wc -l" out.txt
   ```

Equivalente ao fazer no bash:

```
 < main.c ls -l | wc -l > out.txt
 ```

Apos o comando, para ver o resultado basta ``` cat out.txt``` ou abrir o arquivo out.txt




2. Vamos conta a quantidade de vezes que a letra 'a' aparece no arquivo main.c e gravar o resultado no arquivo out.txt
```  
./pipex main.c "grep a" "wc -w" out.txt
 ```
Equivalente ao fazer no bash:
``` 
 < main.c  grep a | wc -w > out.txt 
 ```
Para ver o resultado é anlogo ao segundo exemplo. 


### Pipex2 

A existe apenas duas diferença entre Pipex1 e Pipex2, a primeira é que Pipex2 recebe mais comando
```bash
./pipex file1 cmd_1 cmd_2 cmd_3 ...  cmd_n file2
```
**Exemplo:**
Crie um arquivo denotado texto.txt, escreva algo dentro (preferencia palavras que contem 'r'), agora vamos criar um arquivo denotado  cebo.txt que vai pegar **somente palavras que contém r** do arquivo.txt e vai trocar r por l. 

```bash
./pipex texto.txt "grep r" "tr 'r' 'l'" "tr -s l"  cebo.txt
```
Vale resaltar que "grep" vai pegar palavras que contém "r", o "tr" que vai fazer substituição, "tr -s" eliminar carácter repetido. 


Segunda diferença, o fato do Pipex2 tem opção do here_doc o comando 

```
./pipex here_doc LIMITER cmd cmd1 file
```

 que seria o mesmo que fazer no bash 
 ```
 cmd << LIMITER | cmd1 >> file
 ```
 onde:

 - here_doc: é opção para digitar no terminal;
 - LIMITER: seria palavra chave para fechar o terminal e executar os comando 
 - cmd1: é o comando, mas poderia ter mais de um.
  -  file: nosso arquivo gravado. 

 **Exemplo 2**
vamos fazer a mesma coisa que no exemplo anterior,só que em vez de criamos um arquivo.txt, vamos digita diretamente no terminal, quando digitamos **Cebolinha** o terminal vai fechar e gerar um arquivo denotado **cebola.txt** 

 ```
./pipex here_doc Cebolinha "grep r" "tr 'r' 'l'" "tr -s l"  cebola.txt
 ```



## Melhoria Futuro 

- Criar um teste automatizado;
- Fazer mais teste, principalmente com aspa;
