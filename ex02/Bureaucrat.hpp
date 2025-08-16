/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:06:20 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/16 18:14:16 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string _name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name,int ngrade);
        Bureaucrat(const Bureaucrat &cpy);
        Bureaucrat &operator=(const Bureaucrat &affect);
        std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        void signForm(AForm &existForm);
        void executeForm(AForm &existForm);
        ~Bureaucrat();
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
std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);