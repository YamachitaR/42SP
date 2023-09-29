/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 00:44:27 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/29 17:55:05 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):AForm("Shrubbery", 145, 137), _target("file")
{
	std::cout << "ShrubberyCreationForm: Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm(target, 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm: Constructor with parameter called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):AForm()
{
	std::cout << "ShrubberyCreationForm: Copy constructor called" << std::endl;
	*this =  copy;	
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm: Destructor called" << std::endl;
}


ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
	std::cout << "ShrubberyCreationForm: Copy assignment operator" << std::endl;
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return (*this);
}



int ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::string file;
    std::ofstream ofs;

	this->checkExecute(executor);
	
    file = this->_target + "_shrubbery";
    ofs.open(file.c_str());
	
	if(ofs.fail())
		return (3);
	                                                                                                                                                                                                                                                                   
    ofs << "                                             ....                         \n";                      
    ofs << "                               . ...  ...:...:..: ::::.                   \n";                      
    ofs << "                             ...::::::..:::...:.:.........                \n";                      
    ofs << "                           .:.::.....::. .:::.:.:..:::.......             \n";                      
    ofs << "                        .:..::::..::..::.^::^::::.:::^:::...:. .:.        \n";                      
    ofs << "                       .:..:.:::::^:::^^::::::::.:...:.::.....::...       \n";                      
    ofs << "                        .::^:^:.:^^:::..:^^:.:::::.:.:^:::::^^::..        \n";                      
    ofs << "                        ..:.:::::::::::.....:::^::::..::..:::::..:.       \n";                      
    ofs << "                        :::.::::::::::^:.:.::.:^^::::.::......::::...     \n";                      
    ofs << "             .::::.   ..::^...: .:^^^:...^:...:^^:::.:^^^^^^:..:. .^.     \n";                      
    ofs << "              ......:.....    . .^^..:...   .: .::^:.::::....      .      \n";                      
    ofs << "             .::..::^::.::. . ..^^..:^^^.   .   .^.:...   .:.             \n";                      
    ofs << "         .....:..::::::...:::..::: .:::.                                  \n";                      
    ofs << "     .. .:...:::..:....::::^.:::::.::.:.                                  \n";                      
    ofs << "    .:..::.::::..:::::.:^^:....::.                                        \n";                      
    ofs << "   .:::^..:::::::::::^^^^:. :.:::.         .    .                         \n";                      
    ofs << "   ..:::::.::.::...:::::  : :..:::         :.:.:.   .::                   \n";                      
    ofs << "    ...::..:.:::..::.      ....:..:.      ..:: :.:..:..... ..  .....      \n";                      
    ofs << "        .....:::.   .   . ..::. ::.:... .   ::..::.....:..:......:.:.     \n";                      
    ofs << "            ..      . .:::..:: .:..:.:.         . ...:.:..:.......::.     \n";                      
    ofs << "             ........:..::::^^^..:.::^^^:..         ..::..:::::::.::::.    \n";                     
    ofs << "          ......::...:::::..::::.:......:::..: ::..   ...::...:.....  .   \n";                      
    ofs << "          ..:::..:......:: .....:... .. ...:...:::. .::...........:.      \n";                      
    ofs << "      ......:::::^^:::. .   ...::..........:...:.::^^^^.:..::::::::.....   .   \n";                 
    ofs << "     .:......  .:.            .::::.::....::..::....::^^^:.........::.:....:   \n";                 
    ofs << "           .    .          .:.::::::::..::.:.:.::.   ::^^^:..:.::...:.:.::.. ....       .   \n";    
    ofs << "                           :::.:....::...:.......       .::...  ...::. :.:...::..........   \n";    
    ofs << "                             ...:...........  :         .^::.        :::::.:::::.....:... . \n";    
    ofs << "                             ......::...                :^^^.            ... ..::^:..:.:..   \n";   
    ofs << "                            ...:.:.:.   .            .::::.                     .::..:....   \n";   
    ofs << "                               .::...              .:^^:^.                       .. ..  .  \n";     
    ofs << "                                   .              ::::^.               \n";                         
    ofs << "                                                ::..:                  \n";                         
    ofs << "                                              :.:::                   \n";                          
    ofs << "                                            .:..:.                     \n";                         
    ofs << "                                           .::::.                      \n";                         
    ofs << "                                          .::.:.                       \n";                         
    ofs << "                                         .^:^::                      \n";                           
    ofs << "                                 ....   .::..:. ..                 \n";                             
    ofs << "                    .....  .... ..:^:::::^:..:..:^.  ............. \n";                             
    ofs << "                  ....:.........:...::......:.:...:........:::..... \n";                            
    ofs << "                  ....:...:...:.:..:::.....:.::...::..:....:::.......\n";                           
    ofs << "                  :::::::::..::::.:::::::::::::.:::::::.:::::::::::.:\n";                           
    ofs << "                     ::::::::::::::::::::::::::::::::::::::::::::::\n";                             
    ofs << "                     :...:.::....:::::::::::::::::::::::::....::::\n";                              
    ofs << "                      :..:........::.:::::....:.:::::.::::....:.:.\n";                              
    ofs << "                      .:::::::::::::::::::::::::::::::::::::::::.\n";                               
    ofs << "                       :::::::::::::::::::::::::::::::::::::::::.\n";                               
    ofs << "                       ::::::::::::::::::::::::::::::::::::::::.\n";                                
    ofs << "                       .:::::::::::::::::::::::::::::::::::::::.\n";                                
    ofs << "                        .:::...:................................\n";                                
    ofs << "                           .......:::::::::::::::::::.....::::.\n";
    ofs.close();

	return (1);
}