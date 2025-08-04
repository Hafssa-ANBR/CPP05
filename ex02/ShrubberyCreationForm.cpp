/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanebaro <hanebaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:07:20 by hanebaro          #+#    #+#             */
/*   Updated: 2025/08/04 14:32:33 by hanebaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("default")
{
    this->SigneGrade = 145;
    this->exec_grade = 137;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
    this->_target = target;
    this->SigneGrade = 145;
    this->exec_grade = 137;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy)
{
    *this = cpy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &affect)
{
    if (this != &affect)
    {
        _target = affect._target;
        _Fname = affect._Fname;
        SigneGrade = affect.SigneGrade;
        _signed = affect._signed;
        exec_grade = affect.exec_grade;
    }
    return(*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::fstream MyFile("shrubberyTree.txt");

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

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}
