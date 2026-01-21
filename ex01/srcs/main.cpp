/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:50:38 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/21 13:11:27 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main() {
    std::cout << "=== Test 1: Valid bureucrat ===" << std::endl;
    Bureaucrat *levi = NULL;
    try {
        levi = new Bureaucrat("Levi", 42);

        std::cout << *levi << std::endl;
        delete levi;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        delete levi;
    }

    std::cout << "\n=== Test 2: Grade too high ===" << std::endl;
    Bureaucrat *arttu = NULL;
    try {
        arttu = new Bureaucrat("Arttu", 0);

        std::cout << *arttu << std::endl;
        delete arttu;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        delete arttu;
    }

    std::cout << "\n=== Test 3: Grade too low ===" << std::endl;
    Bureaucrat *kevin = NULL;
    try {
        kevin = new Bureaucrat("Kevin", 151);

        std::cout << *kevin << std::endl;
        delete kevin;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        delete kevin;
    }

    std::cout << "\n=== Test 4: Increment boundaries ===" << std::endl;
    Bureaucrat *thomas = NULL;
    try {
        thomas = new Bureaucrat("Thomas", 1);

        std::cout << *thomas << std::endl;
        thomas->incrementGrade();
        std::cout << *thomas << std::endl;
        delete thomas;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        delete thomas;
    }

    std::cout << "\n=== Test 5: Decrement boundaries ===" << std::endl;
    Bureaucrat *Flav = NULL;
    try {
        Flav = new Bureaucrat("Flav", 150);

        std::cout << *Flav << std::endl;
        Flav->decrementGrade();
        std::cout << *Flav << std::endl;
        delete Flav;
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
        delete Flav;
    }

    return 0;
}