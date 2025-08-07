/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:06:04 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/07 13:28:21 by hanebaro         ###   ########.fr       */
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

        b2.decrement();
        b2.decrement();
    }
    
    catch(const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return(0);
}