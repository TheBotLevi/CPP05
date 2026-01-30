/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levi_jeri <levi_jeri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:18:43 by levi_jeri         #+#    #+#             */
/*   Updated: 2026/01/30 15:31:12 by levi_jeri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

void PresidentialPardonForm::executeAction() const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm default constructor called!\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PresidentialPardonForm", 25, 5), _target(other._target) {
    std::cout << "PresidentialPardonForm copy constructor called!\n";
    *this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        this->_target = other._target;
        std::cout << "PresidentialPardonForm assignment operator called!\n";
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called!\n";
}