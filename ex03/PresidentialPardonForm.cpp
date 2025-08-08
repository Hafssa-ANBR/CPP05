/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:07:34 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/07 14:01:46 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm()
{
    this->SigneGrade = 25;
    this->exec_grade = 5;
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target)
{
    this->_target = _target;
    this->SigneGrade = 25;
    this->exec_grade = 5;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy)
{
    *this = cpy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &affect)
{
    if(this != &affect)
    {
        _target = affect._target;
        _Fname = affect._Fname;
        SigneGrade = affect.SigneGrade;
        _signed = affect._signed;
        exec_grade = affect.exec_grade;
        //a verifier
    }
    if (this != &affect)
    {
        AForm::operator=(affect); // 🔁 Appel à l’opérateur d’affectation de la classe de base
        this->_target = affect._target;
    }///////////////////////////////////////////////////// avoir apres
    return(*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if(executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    else if(this->getsigned() == false)
        throw NotSigneFormException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}