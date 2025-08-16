/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:06:04 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/16 17:55:46 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("first",2);
        Bureaucrat b2("second",149);
        std::cout << b1 << std::endl;
        std::cout << b2 << std::endl;
        b1.increment();
        // b1.increment();
        std::cout << b1 << std::endl;

        b2.decrement();
        std::cout << b2 << std::endl;
        b2.decrement();
        std::cout << b2 << std::endl;
    }
    
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return(0);
}