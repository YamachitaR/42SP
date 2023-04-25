/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exemplo1.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:48:25 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/04/25 18:48:58 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace exemplo {
    int a = 5;
    void foo() {
        std::cout << "Olá do namespace exemplo!" << std::endl;
    }
}

int main() {
    exemplo::foo();
    std::cout << "Valor de a: " << exemplo::a << std::endl;
    return 0;
}