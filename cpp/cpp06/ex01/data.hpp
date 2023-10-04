/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:53:29 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 23:02:35 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef data_HPP
#define data_HPP

#include <iostream>

struct Data{
	std::string name;
	
	Data(std::string str): name(str){}
};

#endif