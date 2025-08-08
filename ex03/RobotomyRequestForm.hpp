/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:08:05 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/04 14:26:05 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        RobotomyRequestForm();
    public:
        RobotomyRequestForm(std::string _target);
        RobotomyRequestForm(const RobotomyRequestForm &cpy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &affect);
        void execute(Bureaucrat const & executor) const;
        ~RobotomyRequestForm();  
};
