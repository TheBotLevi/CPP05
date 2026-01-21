/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:25:13 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/21 15:34:28 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        bool _signed;
        unsigned const int _gradeToSign;
        unsigned const int _gradeToExecute;
    public:
        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        void getName();
        bool isSigned();
        int getGradeToSign();
        int getGradeToExecute();
        
        Form& beSigned(Bureaucrat const &); //when this function is called, the bureaucrat signs the form

        class GradeTooHighException : public std::exception {
    	    public:
			    const char* what() const throw();
	    };

	    class GradeTooLowException : public std::exception {
		    public:
			    const char* what() const throw();
	    };
};

std::ostream& operator<<(std::ostream& os, Form& form);