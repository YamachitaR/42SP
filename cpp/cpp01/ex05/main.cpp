/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:42:40 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/11 20:45:00 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main(void)
{
	Harl harl;

	std::cout << "===|Debug|===" << std::endl;
	harl.complain("debug");

	std::cout << std::endl << "===|Info|===" << std::endl;
	harl.complain("info");

	std::cout << std::endl << "===|Warning|===" << std::endl;
	harl.complain("warning");

	std::cout << std::endl << "===|Error|===" << std::endl;
	harl.complain("error");

	std::cout << std::endl << "===|It is not exist|===" << std::endl;
	harl.complain("danger");
}
