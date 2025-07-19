/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:48:34 by hanebaro          #+#    #+#             */
/*   Updated: 2025/07/16 13:57:34 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
{
    _Fname = "default";
    _Fgrade = 42;
    exec_grade = 37;
}

Form::Form(std::string name, int grade, int exec_gd)
{
    if(grade < 1)
        throw Form::GradeTooHighException();
    if(grade > 150)
        throw Form::GradeTooLowException();
    _Fname = name;
    _Fgrade = grade;
    exec_grade = exec_gd;
}

Form::Form(const Form &cpy)
{
   *this = cpy;
}

Form &Form::operator=(const Form &affect)
{
    if(this != &affect)
    {
        _Fname = affect._Fname;
        _Fgrade = affect._Fgrade;
        _signed = affect._signed;
        exec_grade = affect.exec_grade;
    }
    return(*this);
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "Form \"" << form.getFname() << "\""
        << " [signed: " << (form.getsigned() ? "yes" : "no")
        << ", grade required to sign: " << form.getFgrade()
        << ", grade required to execute: " << form.getExecGrade()
        << "]";
    return out;
}
std::string Form::getFname() const
{
    return(_Fname);
}

int Form::getFgrade() const
{
    return(_Fgrade);
}

bool Form::getsigned() const
{
    return(_signed);
}

int Form::getExecGrade() const
{
    return(exec_grade);
}

Form::~Form() {}

// void Form::beSigned(Bureaucrat person)
// {
//     if(person.getGrade() >= _signed)
//         _signed = true;
// }

void Form::beSigned(const Bureaucrat &person)//why
{
    if (person.getGrade() > _Fgrade) // Si le grade est trop bas
        throw GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("Form::GradeTooHighException");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Form::GradeTooLowException");
}