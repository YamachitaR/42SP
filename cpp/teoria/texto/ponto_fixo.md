# Do que se trata  valor correspondente em ponto fixo?

O valor correspondente em ponto fixo se refere a uma representação numérica de um valor em ponto flutuante usando um formato de ponto fixo. Em programação, os valores de ponto flutuante são representados por números binários com uma parte inteira e uma parte fracionária, enquanto os valores de ponto fixo são representados apenas por números inteiros, em que a posição decimal é fixa.

Para obter o valor correspondente em ponto fixo a partir de um valor em ponto flutuante, é necessário escolher a escala adequada e aplicar a conversão. A escala determina a posição do ponto decimal fixo e a resolução do valor fracionário. Por exemplo, se você escolher uma escala de 2^16 (65536) para representar valores em ponto fixo, significa que você está dividindo o intervalo entre os números inteiros em 65536 partes iguais e usando essas partes para representar valores fracionários.

A conversão em si envolve multiplicar o valor em ponto flutuante pela escala escolhida e, em seguida, arredondar o resultado para o inteiro mais próximo ou truncá-lo para obter o valor correspondente em ponto fixo. Por exemplo, se o valor em ponto flutuante for 3.14 e você escolher uma escala de 2^16, a conversão seria: valorPontoFixo = 3.14 * 65536 = 205887.04, que pode ser arredondado ou truncado, dependendo das necessidades do seu caso específico.

A escolha da escala adequada depende das necessidades da aplicação e do valor máximo que você deseja representar em ponto fixo. É importante considerar a faixa de valores, a resolução desejada e a precisão necessária para determinar a escala apropriada.

O uso de valores em ponto fixo pode ser útil em várias situações, como quando a representação em ponto flutuante é excessivamente complexa ou requer muitos recursos computacionais, ou quando a precisão decimal exata não é necessária e a eficiência de espaço e desempenho são importantes.

No entanto, é importante ter em mente que a representação em ponto fixo envolve uma perda de precisão, uma vez que os valores fracionários são arredondados ou truncados. Portanto, é necessário avaliar cuidadosamente as necessidades do seu aplicativo e os compromissos entre precisão e eficiência ao optar pelo uso de valores em ponto fixo.


# Converter 

## Inteiro para ponto fixo

Para converter um valor inteiro para o valor correspondente em ponto fixo, você precisa realizar duas etapas principais: escolher a escala apropriada e aplicar a conversão. 

A escala determina a posição do ponto decimal fixo na representação do valor em ponto fixo. Por exemplo, se você deseja ter 2 bits fracionários, a escala será 2 elevado à potência do número de bits fracionários (nesse caso, 2² = 4). Isso significa que você está dividindo o intervalo entre os números inteiros por 4 e representando valores fracionários com precisão de 1/4.

A conversão envolve a multiplicação do valor inteiro pela escala escolhida. Por exemplo, se você tem um valor inteiro de 10 e deseja representá-lo em ponto fixo com 2 bits fracionários, você multiplica 10 por 4 (escala) para obter o valor correspondente em ponto fixo.

Aqui está um exemplo de código em C++ para converter um valor inteiro para ponto fixo:

```cpp
#include <iostream>

int main() {
    int valorInteiro = 10;
    int bitsFracionarios = 2;
    int escala = 1 << bitsFracionarios;  // Calcula a escala como 2^bitsFracionarios

    int valorPontoFixo = valorInteiro * escala;

    std::cout << "Valor Inteiro: " << valorInteiro << std::endl;
    std::cout << "Valor Ponto Fixo: " << valorPontoFixo << std::endl;

    return 0;
}
```

Neste exemplo, definimos um `valorInteiro` de 10 e `bitsFracionarios` como 2 para representar 2 bits fracionários. Calculamos a `escala` como 2 elevado à potência dos `bitsFracionarios`. Em seguida, multiplicamos o `valorInteiro` pela `escala` para obter o `valorPontoFixo`.

Ao imprimir o `valorInteiro` e o `valorPontoFixo`, você verá o resultado da conversão do valor inteiro para o valor correspondente em ponto fixo.

Lembre-se de que a escolha adequada da escala depende das necessidades específicas do seu caso de uso. É importante considerar a faixa de valores que você deseja representar e a precisão necessária na parte fracionária.


## fixo para inteiro 

Para converter um valor correspondente em ponto fixo de volta para um valor inteiro, você precisa inverter o processo de conversão. Isso envolve dividir o valor correspondente em ponto fixo pela escala utilizada na conversão original.

Vamos supor que você tenha um valor correspondente em ponto fixo armazenado na variável `valorFixo` e a escala utilizada na conversão esteja na variável `escala`. Para converter de volta para um valor inteiro, você pode usar a seguinte fórmula:

```cpp
int valorInteiro = valorFixo / escala;
```

O operador de divisão (`/`) é usado para realizar a divisão do `valorFixo` pela `escala`. O resultado é armazenado na variável `valorInteiro`, que será o valor inteiro correspondente ao valor em ponto fixo original.

Aqui está um exemplo de código em C++:

```cpp
#include <iostream>

int main() {
    int valorFixo = 205887;  // Exemplo de valor correspondente em ponto fixo
    int escala = 65536;  // Exemplo de escala utilizada na conversão original

    int valorInteiro = valorFixo / escala;

    std::cout << "Valor Fixo: " << valorFixo << std::endl;
    std::cout << "Valor Inteiro: " << valorInteiro << std::endl;

    return 0;
}
```

Neste exemplo, supomos que `valorFixo` seja 205887, que é um valor correspondente em ponto fixo. A `escala` utilizada na conversão original é 65536. Ao dividir `valorFixo` por `escala`, obtemos o valor inteiro correspondente, que será 3.

Ao executar o código, você verá o `valorFixo` e o `valorInteiro` exibidos.

Certifique-se de que a escala utilizada na conversão seja a mesma usada anteriormente para obter o valor correspondente em ponto fixo. Caso contrário, a conversão de volta para o valor inteiro não será precisa.