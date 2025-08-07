/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:48:38 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/07 11:46:34 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
class Bureaucrat;


class AForm 
{
    protected:
        std::string _Fname;
        int SigneGrade;//signe grade
        bool _signed;
        int exec_grade;
        
    public:
        AForm();
        AForm(std::string name, int grade, int exec_gd);
        AForm(const AForm &cpy);
        AForm &operator=(const AForm &affect);
        std::string getFname() const;
        int getFgrade() const;
        bool getsigned() const;
        int getExecGrade() const;
        virtual void execute(Bureaucrat const & executor) const = 0;
        virtual ~AForm();
        void beSigned(const Bureaucrat &person);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        class NotSigneFormException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);