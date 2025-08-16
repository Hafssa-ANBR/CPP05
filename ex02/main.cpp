/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:06:04 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/16 20:05:17 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat bob("Bob", 1);
        Bureaucrat jim("Jim", 140);

        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robo("Bender");
        PresidentialPardonForm pardon("Alice");

        std::cout << "\n-- Trying to execute unsigned forms --\n";
        bob.executeForm(shrub);
        bob.executeForm(robo);
        bob.executeForm(pardon);

        std::cout << "\n-- Signing the forms --\n";
        bob.signForm(shrub);
        bob.signForm(robo);
        bob.signForm(pardon);

        std::cout << "\n-- Jim trying to execute forms (should fail for some) --\n";
        jim.executeForm(shrub);
        jim.executeForm(robo);
        jim.executeForm(pardon);

        std::cout << "\n-- Bob executing all forms --\n";
        bob.executeForm(shrub);
        bob.executeForm(robo);
        bob.executeForm(pardon);

    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return (0);
}
