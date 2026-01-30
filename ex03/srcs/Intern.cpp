/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levi_jeri <levi_jeri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:34:38 by levi_jeri         #+#    #+#             */
/*   Updated: 2026/01/30 16:57:57 by levi_jeri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor created!\n";
}

Intern::Intern(const Intern &other) {
    std::cout << "Intern copy constructor called!\n";
    *this = other;
}

Intern& Intern::operator=(const Intern &other) {
    if (this != &other) {
        std::cout << "Intern assignment operator called!\n";
    }
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern destructor called!\n";
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    try {
        //...
    }
    catch (std::exception &e) {
        //...
    }
}