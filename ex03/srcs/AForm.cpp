/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levi_jeri <levi_jeri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:11:04 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/25 20:16:25 by levi_jeri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form default constructor called!\n";
}

AForm::AForm(const AForm& other) : _name(other._name),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "AForm copy constructor called!\n";
    *this = other;
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called!\n";
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm::GradeTooHighException";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm::GradeTooLowException";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm::FormNotSignedException";
}

std::string AForm::getName() {
    return _name;
}

bool AForm::isSigned() {
    return _signed;
}

int AForm::getGradeToSign() {
    return _gradeToSign;
}

int AForm::getGradeToExecute() {
    return _gradeToExecute;
}

AForm& AForm::beSigned(const Bureaucrat &other) {
    if (other.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
    return *this;
}

std::ostream& operator<<(std::ostream& os, AForm& form) {
    os << "AForm " << form.getName() << ", signed: " << form.isSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
    return os;
}

void AForm::execute(Bureaucrat const & executor) {
    //try and catch all the executeForm functions
    if(!_signed)
        throw FormNotSignedException();
    if (executor.getGrade() > this->_gradeToExecute)
        throw GradeTooLowException();
    this->executeAction();
}