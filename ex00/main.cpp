/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:06:04 by hanebaro          #+#    #+#             */
/*   Updated: 2025/07/15 16:25:32 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("first",2);
        Bureaucrat b2("second",149);
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