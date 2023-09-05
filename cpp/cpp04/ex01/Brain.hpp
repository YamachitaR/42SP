/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:17:28 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/31 02:09:36 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_HPP
#define Brain_HPP

#include <iostream>

class Brain
{
	private:
		std::string _ideas[100];

	public:
		Brain(void);
		Brain(Brain const &copy);
		Brain(std::string str);
		~Brain(void);

		Brain &operator = (Brain const &rhs);

		std::string getIdeas(int i) const;
		void setIdeas(int i, std::string str);

		void setSameIdeas(std::string str);

		void sayIdeas(void) const;

};

# endif
