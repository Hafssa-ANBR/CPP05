/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 10:57:52 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/08 13:10:49 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &cpy)
{
    (void)cpy;
}

Intern &Intern::operator=(const Intern &affect)
{
    (void)affect;
    return (*this);
}

Intern::~Intern() {}

AForm *Intern::makeForm(std::string name, std::string target)
{
    std::string table[] = {"shrubbery creation", "robotomy request", "• presidential pardon"};
    int i = 0;
    AForm *form = NULL;
    while (i < 3)
    {
        if (name == table[i])
            break;
        i++;
    }
    switch (i)
    {
        case 0:
            form = new ShrubberyCreationForm(target);
            std::cout << "Intern creates " << name << std::endl;
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            std::cout << "Intern creates " << name << std::endl;
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            std::cout << "Intern creates " << name << std::endl;
            break;
        default:
            std::cout << "Error: Form name " << name << " is unknown." << std::endl;
    }
    return(form);
}