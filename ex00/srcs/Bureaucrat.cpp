/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:39:35 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/17 13:31:58 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name) : _name(name) {
        std::cout << "Default constructor called!\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
        std::cout << "Copy constructor called!\n";
        *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
        if (this != &other) {
                _name = other._name;
                std::cout << "Assignment operator called!\n";
        }
        return *this;
}

Bureaucrat::~Bureaucrat() {
        std::cout << "Destructor called!\n";
}