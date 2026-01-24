/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:39:35 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/24 13:46:18 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _bureaucratName(name), _bureaucratGrade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->_bureaucratGrade = grade;
    std::cout << "Bureaucrat default constructor called!\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy constructor called!\n";
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        _bureaucratName = other._bureaucratName;
        _bureaucratGrade = other._bureaucratGrade;
        std::cout << "Bureaucrat assignment operator called!\n";
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called!\n";
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

void Bureaucrat::incrementGrade()
{
    _bureaucratGrade--;
    if (_bureaucratGrade < 1)
        throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::decrementGrade()
{
    _bureaucratGrade++;
    if (_bureaucratGrade > 150)
        throw Bureaucrat::GradeTooHighException();
}


const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat::GradeTooHighException";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat::GradeTooLowException";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return os;
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << _bureaucratName << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << _bureaucratName << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}