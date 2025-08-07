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

AForm::AForm()
{
    _Fname = "default";
    SigneGrade = 42;
    exec_grade = 37;
}

AForm::AForm(std::string name, int grade, int exec_gd)
{
    if(grade < 1)
        throw AForm::GradeTooHighException();
    if(grade > 150)
        throw AForm::GradeTooLowException();
    _Fname = name;
    SigneGrade = grade;
    exec_grade = exec_gd;
}

AForm::AForm(const AForm &cpy)
{
   *this = cpy;
}

AForm &AForm::operator=(const AForm &affect)
{
    if(this != &affect)
    {
        _Fname = affect._Fname;
        SigneGrade = affect.SigneGrade;
        _signed = affect._signed;
        exec_grade = affect.exec_grade;
    }
    return(*this);
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

// void AForm::beSigned(Bureaucrat person)
// {
//     if(person.getGrade() >= _signed)
//         _signed = true;
// }

void AForm::beSigned(const Bureaucrat &person)//why
{
    if (person.getGrade() > SigneGrade) // Si le grade est trop bas
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