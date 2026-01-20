/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:39:35 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/20 14:05:52 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _bureaucratName(name), _bureaucratGrade(grade) {
        if (grade < 1)
                throw GradeTooHighException();
        else if (grade > 150)
                throw GradeTooLowException();
        this->_bureaucratGrade = grade;
        std::cout << "Default constructor called!\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
        std::cout << "Copy constructor called!\n";
        *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
        if (this != &other) {
                _bureaucratName = other._bureaucratName;
                _bureaucratGrade = other._bureaucratGrade;
                std::cout << "Assignment operator called!\n";
        }
        return *this;
}

Bureaucrat::~Bureaucrat() {
        std::cout << "Destructor called!\n";
}

std::string Bureaucrat::getName() const {
        return _bureaucratName;
}

void Bureaucrat::setName(const std::string name) {
        _bureaucratName = name;
}

unsigned int Bureaucrat::getGrade() const {
        return _bureaucratGrade;
}

void Bureaucrat::setGrade(unsigned int grade) {
        _bureaucratGrade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
        return "overriden GradeTooHighException what() function";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
        return "overriden GradeTooLowException what() function";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
        os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".\n";
        return os;
}