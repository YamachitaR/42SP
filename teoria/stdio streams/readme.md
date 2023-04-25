
# Sdio Streams

~~~ c++
#include <iostream>

int main (void)
{
	char	buff[512];

	std::cout << "Hello, world !"  << std::endl;

	std::cout << "Entre com uma palavra: ";
	std::cin >> buff;
	std::cout << "Sua entrada foi:[" << buff << "]" << std::endl;

	return (0);
}
~~~

# Notação 

- cout seria um "printf"
- cin seria um "read" que ler as coisas do terminal
- Os operadores << e >> são operadores de fluxos 
- endl funciona como '\n'
