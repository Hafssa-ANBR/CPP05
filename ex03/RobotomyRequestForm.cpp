/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:08:00 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/07 12:49:40 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("default")
{
    this->SigneGrade = 72;
    this->exec_grade = 45;
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target)
{
    this->_target = _target;
    this->SigneGrade = 72;
    this->exec_grade = 45;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
{
    *this = cpy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &affect)
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
