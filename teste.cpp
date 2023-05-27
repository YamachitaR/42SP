#include <string>
#include <iostream>

class Arvore
{
	private:
		std::string _nome;

	public:
		Arvore(std::string nome) :_nome(nome)  //construtor
		{
			std::cout << "Arvore de" << this->_nome << " nasceu" << std::endl;
		}

		~Arvore() //Destrutor
		{
			std::cout << "Arvore de" << this->_nome << " morreu" << std::endl;
		}
};

int main()
{
	Arvore		bob = Arvore("Araucaria");
	Arvore*	    jim = new Arvore("Jatoba");


	delete jim; // jim is destroyed

	return (0); // bob is destroyed
}