/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:11:04 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/24 13:58:04 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form default constructor called!\n";
}

Form::Form(const Form& other) : _name(other._name),
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Form copy constructor called!\n";
    *this = other;
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called!\n";
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form::GradeTooHighException";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form::GradeTooLowException";
}

std::string Form::getName() {
    return _name;
}

bool Form::isSigned() {
    return _signed;
}

int Form::getGradeToSign() {
    return _gradeToSign;
}

int Form::getGradeToExecute() {
    return _gradeToExecute;
}

Form& Form::beSigned(const Bureaucrat &other) {
    if (other.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
    return *this;
}

std::ostream& operator<<(std::ostream& os, Form& form) {
    os << "Form " << form.getName() << ", signed: " << form.isSigned() << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
    return os;
}