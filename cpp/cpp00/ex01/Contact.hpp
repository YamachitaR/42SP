/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:20:59 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/05/26 17:08:09 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H 
#include <iostream>

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _phone_numeber;
		std::string _darkest_secret;
		
		void _printDisplay(std::string s);
		
	public:
		void setContact(std::string s[5]);	
		void printContact(void);
		void printSearch(void);
};

#endif