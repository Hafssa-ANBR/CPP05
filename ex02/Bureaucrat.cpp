/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:06:12 by hanebaro          #+#    #+#             */
/*   Updated: 2025/07/26 12:37:10 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrate"),grade(42) {}

Bureaucrat::Bureaucrat(std::string name,int ngrade) : _name(name)
{
    if(ngrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(ngrade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade = ngrade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
{
    *this = cpy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &affect)
{
    if(this != &affect)
    {
        _name = affect._name;
        grade = affect.grade;
    }
    return(*this);
}

std::string Bureaucrat::getName() const
{
    return(_name);
}

int Bureaucrat::getGrade() const
{
    return(grade);
}

void Bureaucrat::increment()
{
    if(--grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrement()
{
    if(++grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(AForm existForm)
{
    if(existForm.getsigned())
        std::cout << _name << " signed " << existForm.getFname() << std::endl;
}
Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Bureaucrat::GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bureaucrat::GradeTooLowException");
}