/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levi_jeri <levi_jeri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:16:22 by levi_jeri         #+#    #+#             */
/*   Updated: 2026/01/30 15:09:02 by levi_jeri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm default constructor called!\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called!\n";
    *this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        this->_target = other._target;
        std::cout << "RobotomyRequestForm operator assignment called!\n";
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called!\n";
}

void RobotomyRequestForm::executeAction() const {
    std::cout << "*drilling noises*" << std::endl;
    if (rand() % 2) {
        std::cout << _target << " has been robotomized successfully!\n";
    }
    else {
        std::cout << _target << " robotomy failed!\n";
    }
}