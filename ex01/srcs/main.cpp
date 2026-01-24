/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljeribha <ljeribha@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:50:38 by ljeribha          #+#    #+#             */
/*   Updated: 2026/01/24 15:51:54 by ljeribha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat john("John", 50);
        Bureaucrat bob("Bob", 150);
        
        Form taxForm("Tax Form", 100, 50);
        
        std::cout << taxForm << std::endl;  // Should show unsigned
        
        john.signForm(taxForm);  // Should succeed (50 <= 100)
        
        std::cout << taxForm << std::endl;  // Should show signed
        
        bob.signForm(taxForm);   // Should fail (150 > 100)
        
    } catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
