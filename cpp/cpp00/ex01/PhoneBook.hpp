/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:21:17 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/05/26 17:10:23 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		int _new;
		int _amount;
		Contact _contacts[8];
		
		int _check_number(std::string s);
		int _check_string(std::string s);
		int _check(int n, std::string s);
		int	_atoi(std::string s);
		void _message(int n);
		
	public:
		PhoneBook(void);
		~PhoneBook(void);
		
		void search(void);
		void add(void);
};
#endif
