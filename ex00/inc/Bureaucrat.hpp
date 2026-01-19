/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:38:56 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/19 11:02:39 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

class Bureaucrat {
    private:
        std::string _name;
    public:
        Bureaucrat(const std::string& name);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

    	void getName(const std::string& name) const;
    	void getGrade(unsigned int grade) const;
};

class MyException : public std::exception {
    public:
		const char* what() const noexcept;
}