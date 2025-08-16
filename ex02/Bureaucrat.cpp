/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:06:12 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/16 18:15:54 by hanebaro         ###   ########.fr       */
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

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name)
{
    grade = cpy.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &affect)
{
    if(this != &affect)
        grade = affect.grade;
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

void Bureaucrat::signForm(AForm &existForm)
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

std::ostream &operator<<(std::ostream &out, Bureaucrat &bur)
{
    out << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
    return (out);
}

void Bureaucrat::executeForm(AForm &existForm)
{
    try {
        existForm.execute(*this);
        std::cout << this->getName() << " executed " << existForm.getFname() << std::endl;
    } catch (const std::exception &e) {
        std::cout << this->getName() << " couldn't execute " << existForm.getFname()
                  << " because: " << e.what() << std::endl;
    }
}