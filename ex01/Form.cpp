/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:48:34 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/16 19:03:18 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _Fname("default"), SigneGrade(42), _signed(false), exec_grade(37)  {}

Form::Form(std::string name, int grade, int exec_gd) : _Fname(name), SigneGrade(grade), exec_grade(exec_gd)
{
    if(grade < 1)
        throw Form::GradeTooHighException();
    if(grade > 150)
        throw Form::GradeTooLowException();
    _signed = false;
}

Form::Form(const Form &cpy) : _Fname(cpy._Fname), SigneGrade(cpy.SigneGrade), exec_grade(cpy.exec_grade)
{
   _signed = cpy._signed;
}

Form &Form::operator=(const Form &affect)
{
    if(this != &affect)
        _signed = affect._signed;
    return (*this);
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

void Form::beSigned(const Bureaucrat &person)
{
    if (person.getGrade() > SigneGrade)
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