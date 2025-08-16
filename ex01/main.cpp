/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:06:04 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/16 19:09:16 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat bob("Bob", 50);
        Form form1("Form A", 75, 25);

        std::cout << bob << std::endl;
        std::cout << form1 << std::endl;

        form1.beSigned(bob);
        bob.signForm(form1);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- Testing error case ---\n" << std::endl;

    try {
        Bureaucrat alice("Alice", 150);
        Form form2("Form B", 50, 25);

        std::cout << alice << std::endl;
        std::cout << form2 << std::endl;

        alice.signForm(form2);
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}