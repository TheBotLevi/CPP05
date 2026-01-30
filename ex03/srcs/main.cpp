/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levi_jeri <levi_jeri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:50:38 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/30 16:44:10 by levi_jeri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Intern.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(std::time(NULL));

    std::cout << RED <<"========================================" << std::endl;
    std::cout << "= ShrubberyCreationForm (ex00 style)   =" << std::endl;
    std::cout << "========================================" << RESET << std::endl;
    {
        Bureaucrat arttu("Arttu", 1);
        Bureaucrat kevin("Kevin", 150);

        ShrubberyCreationForm shrub("garden");

        arttu.signForm(shrub);
        arttu.executeForm(shrub);

        kevin.executeForm(shrub);
    }

    std::cout << RED << "\n========================================" << std::endl;
    std::cout << "= RobotomyRequestForm (ex01 style)     =" << std::endl;
    std::cout << "========================================" << RESET << std::endl;
    {
        Bureaucrat thomas("Thomas", 45);
        Bureaucrat sid("Sid", 100);

        RobotomyRequestForm robotomy("Robot");

        thomas.signForm(robotomy);
        thomas.executeForm(robotomy);

        sid.signForm(robotomy);
        sid.executeForm(robotomy);
    }

    std::cout << RED << "\n========================================" << std::endl;
    std::cout << "= PresidentialPardonForm (ex02 style) =" << std::endl;
    std::cout << "========================================" << RESET << std::endl;
    {
        Bureaucrat yes("Yes", 3);
        Bureaucrat no("No", 67);

        PresidentialPardonForm pardonForm("PardonForm");

        yes.signForm(pardonForm);
        yes.executeForm(pardonForm);

        no.executeForm(pardonForm);
    }

    std::cout << RED << "\n========================================" << std::endl;
    std::cout << "= Intern (ex03 style) =" << std::endl;
    std::cout << "========================================" << RESET << std::endl;
    {
        Intern intern;
        AForm* form = intern.makeForm("shrubbery creation", "home");
    }
    return 0;
}
