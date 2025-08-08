/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:07:44 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/04 14:26:11 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
    private:
        std::string _target;
        PresidentialPardonForm();
    public:
        PresidentialPardonForm(std::string _target);
        PresidentialPardonForm(const PresidentialPardonForm &cpy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &affect);
        void execute(Bureaucrat const & executor) const;
        ~PresidentialPardonForm();
};