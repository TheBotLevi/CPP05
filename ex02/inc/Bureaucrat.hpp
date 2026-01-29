/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levi_jeri <levi_jeri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:38:56 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/27 17:17:28 by levi_jeri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat {
    private:
        std::string _bureaucratName;
		unsigned int _bureaucratGrade;
    public:
        Bureaucrat(const std::string& name, unsigned int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

    	std::string getName() const;
		void setName(const std::string name);
    	unsigned int getGrade() const;
		void setGrade(unsigned int grade);

		void incrementGrade();
		void decrementGrade();

		void signForm(AForm &form);

		void executeForm(const AForm &form);

		class GradeTooHighException : public std::exception {
    		public:
				const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);