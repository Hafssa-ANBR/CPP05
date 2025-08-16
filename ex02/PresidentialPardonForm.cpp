/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:07:34 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/16 19:47:10 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) : AForm("PresidentialPardonForm", 25, 5)
{
    this->_target = _target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &affect)
{
    if(this != &affect)
    {
        _target = affect._target;
        _signed = affect._signed;
    }
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

PresidentialPardonForm::~PresidentialPardonForm() {}