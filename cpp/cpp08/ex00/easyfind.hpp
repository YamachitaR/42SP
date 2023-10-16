/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:02:08 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/13 15:14:08 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;

	it =std::find(container.begin(), container.end(), value);

	if(it == container.end())
		throw std::runtime_error("The value was not found!");
	return(it);
}

#endif