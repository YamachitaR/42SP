#include <iostream>

int main() {
    float valorInteiro = 3.14f;
    int bitsFracionarios = 8;
    int escala = 1 << bitsFracionarios;  // Calcula a escala como 2^bitsFracionarios

    int valorPontoFixo = valorInteiro * escala;

    std::cout << "Valor Inteiro: " << valorInteiro << std::endl;
    std::cout << "Valor Ponto Fixo: " << valorPontoFixo << std::endl;
	 std::cout << "Revetendo: " << float(valorPontoFixo)/ float(escala) << std::endl;
    return 0;
}

