/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levi_jeri <levi_jeri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:25:13 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/25 21:20:25 by levi_jeri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        unsigned const int _gradeToSign;
        unsigned const int _gradeToExecute;
    public:
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        std::string getName();
        bool isSigned();
        int getGradeToSign();
        int getGradeToExecute();
        
        AForm& beSigned(const Bureaucrat &other); //when this function is called, the "bureaucrat" signs the "form"

        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
    	    public:
			    const char* what() const throw();
	    };

	    class GradeTooLowException : public std::exception {
		    public:
			    const char* what() const throw();
	    };
};

std::ostream& operator<<(std::ostream& os, AForm& form);