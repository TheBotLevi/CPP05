/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levi_jeri <levi_jeri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:24:16 by levi_jeri         #+#    #+#             */
/*   Updated: 2026/01/30 12:08:46 by levi_jeri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm default constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called!\n";
    *this = other;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm assignment operator called!\n";
    if (this != &other) {
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called!\n";
}

void ShrubberyCreationForm::executeAction() const {
    //creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it
    std::ofstream shrubberyCreationFormFile((this->_target + "_shrubbery").c_str());
    
    shrubberyCreationFormFile << 
    "    oxoxoo    ooxoo\n"
    "  ooxoxo oo  oxoxooo\n"
    " oooo xxoxoo ooo ooox\n"
    " oxo o oxoxo  xoxxoxo\n"
    "  oxo xooxoooo o ooo\n"
    "    ooo\\oo\\  /o/o\n"
    "        \\  \\/ /\n"
    "         |   /\n"
    "         |  |\n"
    "         | D|\n"
    "         |  |\n"
    "         |  |\n"
    "  ______/____\\\"____";

    shrubberyCreationFormFile.close();
}