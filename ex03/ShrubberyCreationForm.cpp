/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:07:20 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/16 20:05:11 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
    this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &affect)
{
    if (this != &affect)
    {
        _target = affect._target;
        _signed = affect._signed;
    }
    return(*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::fstream MyFile(_target + "_shrubbery", std::ios::out | std::ios::trunc);

    if(executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    else if(this->getsigned() == false)
        throw NotSigneFormException();
    std::cout << _target << "_shrubbery in the working directory " << std::endl;
    MyFile <<
        "                              'b      *\n"
        "                               '$    #.\n"
        "                                $:   #:\n"
        "                                *#  @):\n"
        "                                :@,@):   ,.**:'\n"
        "                      ,         :@@*: ..**'\n"
        "                       '#o.    .:(@'.@**'\n"
        "                          'bq,..:,@@*'   ,*\n"
        "                          ,p$q8,:@)'  .p*'\n"
        "                         '    '@@Pp@@*'\n"
        "                               Y7'.'\n"
        "                              :@):.\n"
        "                             .:@:'.\n"
        "                           .::(@:.\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
