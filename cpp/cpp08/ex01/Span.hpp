/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 06:10:46 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/13 19:49:38 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_hpp
#define Span_hpp

# include <iostream>
# include <algorithm>
# include <vector>

class Span{
	private:
		unsigned int		_max;
		std::vector<int>	_v;

	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &copy);
		~Span(void);

		Span &operator=(Span const &rhs);

		void addNumber(int value); 
		void addMoreNumber(std::vector<int> value);
		int longestSpan(void);
		int shortestSpan(void);
		
};

#endif