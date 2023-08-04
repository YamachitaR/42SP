# O que é?

Serve para lidar com leitura e escrita do arquivo;


## Exemplo de leitura 

~~~C
std::string Replace::_readAll(char *file)
{
	std::ifstream fd;
	std::string text;
	std::string line;

	fd.open(file);
	while(std::getline(fd, line))
		text += line + "\n";	
	fd.close();
	if(text.empty())
	{
		std::cout << "The file is empty!" << std::endl;
		exit(1);
	}
	return (text);
}
~~~


## Exemplo de escrita

~~~ C
void Replace:: _newFile(std::string s, std::string name)
{
	std::ofstream fd;
	
	fd.open(name);
	if(fd.fail())
	{
		std::cout << "Error creating file!" << std::endl;
		exit(1);
	}
	fd << s;
	fd.close();
}
~~~