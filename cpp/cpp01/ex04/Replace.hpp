/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 02:24:52 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/11 23:26:33 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream> 
#include <fstream>
#include <string.h>


class Replace
{
	private:
		std::string _readAll(char *file);
		void _newFile(std::string s, std::string name);
		void _replace(std::string &text, std::string old_str, std::string new_str);
		
	public:
		Replace(char *s, char *s1, char *s2);
		~Replace(void);
};

#endif