/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:19:30 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/13 03:15:29 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream> 

class Fixed
{
	private:
		int _fixed_point;
		static const int _fractional_bits = 8;
		
	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		~Fixed(void);
		Fixed &operator=(Fixed const &fixed);
		int getRawBits(void)const;
		void setRawBits(int const raw);
};

#endif