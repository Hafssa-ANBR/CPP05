/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:06:20 by hanebaro          #+#    #+#             */
/*   Updated: 2025/07/15 16:15:24 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat
{
    private:
        std::string _name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name,int ngrade);
        Bureaucrat(const Bureaucrat &cpy);
        Bureaucrat &operator=(const Bureaucrat &affect);
        std::string getName();
        int getGrade();
        void increment();
        void decrement();
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