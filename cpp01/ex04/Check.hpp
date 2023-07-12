/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:44:24 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/06 02:04:17 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_HPP
#define CHECK_HPP

#include <iostream> 
#include <fstream>

class Check
{
	private:
		void _checkArgc(int argc);
		void _fileExist(char *file);
		
	public:
		Check(int  argc, char **argv);
		~Check(void);
};

#endif