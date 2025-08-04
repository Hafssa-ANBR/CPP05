/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:07:34 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/04 14:26:59 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

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
    }
    return(*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}
