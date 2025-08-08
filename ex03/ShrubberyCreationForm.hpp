/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:08:11 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/08 13:17:25 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private :
        std::string _target;
        ShrubberyCreationForm();
    public :
        ShrubberyCreationForm(std::string _target);
        ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &affect);
        void execute(Bureaucrat const & executor) const;
        ~ShrubberyCreationForm();
};