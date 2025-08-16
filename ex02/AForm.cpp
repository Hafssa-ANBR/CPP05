/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:48:34 by hanebaro          #+#    #+#             */
/*   Updated: 2025/07/16 13:57:34 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _Fname("default"), SigneGrade(42), _signed(false), exec_grade(37)  {}

AForm::AForm(std::string name, int grade, int exec_gd) : _Fname(name), SigneGrade(grade), exec_grade(exec_gd)
{
    if(grade < 1)
        throw AForm::GradeTooHighException();
    if(grade > 150)
        throw AForm::GradeTooLowException();
    _signed = false;
}

AForm::AForm(const AForm &cpy) : _Fname(cpy._Fname), SigneGrade(cpy.SigneGrade), exec_grade(cpy.exec_grade)
{
   _signed = cpy._signed;
}

AForm &AForm::operator=(const AForm &affect)
{
    if(this != &affect)
        _signed = affect._signed;
    return (*this);
}

std::string AForm::getFname() const
{
    return(_Fname);
}

int AForm::getFgrade() const
{
    return(SigneGrade);
}

bool AForm::getsigned() const
{
    return(_signed);
}

int AForm::getExecGrade() const
{
    return(exec_grade);
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat &person)
{
    if (person.getGrade() > SigneGrade)
        throw GradeTooLowException();
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("AForm::GradeTooHighException");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("AForm::GradeTooLowException");
}

const char* AForm::NotSigneFormException::what() const throw()
{
    return("AForm::NotSigneFormException");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
    out << "form name : " << form.getFname() << std::endl;
    out << "signe grade : " << form.getFgrade() << std::endl;
    out << "signed : " << form.getsigned() << std::endl;
    out << "execute grade : " <<  form.getExecGrade()<< std::endl;
    return(out);
}