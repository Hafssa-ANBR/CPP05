/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:08:00 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/16 19:49:50 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm", 72, 45)
{
    this->_target = _target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &affect)
{
    if(this != &affect)
    {
        _target = affect._target;
        _signed = affect._signed;
    }
    return(*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if(executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    else if(this->getsigned() == false)
        throw NotSigneFormException();
    std::srand(std::time(0));
    if(std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully " << std::endl;
    else
        std::cout << _target << " has not been robotomized successfully" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {}
