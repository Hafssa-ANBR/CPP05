/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:08:00 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/04 14:27:49 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

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
    
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}
