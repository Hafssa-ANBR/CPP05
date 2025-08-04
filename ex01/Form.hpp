/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:48:38 by hanebaro          #+#    #+#             */
/*   Updated: 2025/07/26 12:54:20 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
class Bureaucrat;


class Form 
{
    private:
        std::string _Fname;
        int SigneGrade;//signe grade
        bool _signed;
        int exec_grade;
        
    public:
        Form();
        Form(std::string name, int grade, int exec_gd);
        Form(const Form &cpy);
        Form &operator=(const Form &affect);
        std::string getFname() const;
        int getFgrade() const;
        bool getsigned() const;
        int getExecGrade() const;
        
        ~Form();
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
};

std::ostream &operator<<(std::ostream &out, const Form &form);