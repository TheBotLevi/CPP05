/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levi_jeri <levi_jeri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:24:16 by levi_jeri         #+#    #+#             */
/*   Updated: 2026/01/29 11:55:04 by levi_jeri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : _target(target), AForm("ShrubberyCreationForm", 145, 137) {
    std::cout << "ShrubberyCreationForm default constructor called!\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : _target(other._target), AForm("ShrubberyCreationForm", 145, 137) {
    std::cout << "ShrubberyCreationForm copy constructor called!\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm assignment operator called!\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called!\n";
}

void ShrubberyCreationForm::executeAction() {
    //creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it
    
}