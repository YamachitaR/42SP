/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:20:57 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/04 21:43:51 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef whatever_HPP
# define whatever_HPP

template <typename T>
void swap(T &a, T &b)
{
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T const &min(T const &a, T const &b)
{
	if(a < b)
		return(a);
	return (b);
}

template <typename T>
T const &max(T const &a, T const &b)
{
	if(a > b)
		return(a);
	return (b);
}

#endif