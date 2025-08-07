/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:48:34 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/07 12:37:26 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
{
    _Fname = "default";
    SigneGrade = 42;
    exec_grade = 37;
}

Form::Form(std::string name, int grade, int exec_gd)
{
    if(grade < 1)
        throw Form::GradeTooHighException();
    if(grade > 150)
        throw Form::GradeTooLowException();
    _Fname = name;
    SigneGrade = grade;
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
        SigneGrade = affect.SigneGrade;
        _signed = affect._signed;
        exec_grade = affect.exec_grade;
    }
    return(*this);
}

std::string Form::getFname() const
{
    return (_Fname);
}

int Form::getFgrade() const
{
    return (SigneGrade);
}

bool Form::getsigned() const
{
    return (_signed);
}

int Form::getExecGrade() const
{
    return (exec_grade);
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat &person)//why
{
    if (person.getGrade() > SigneGrade) // Si le grade est trop bas
        throw GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Form::GradeTooHighException");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Form::GradeTooLowException");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << "form name : " << form.getFname() << std::endl;
    out << "signe grade : " << form.getFgrade() << std::endl;
    out << "signed : " << form.getsigned() << std::endl;
    out << "execute grade : " <<  form.getExecGrade()<< std::endl;
    return (out);
}