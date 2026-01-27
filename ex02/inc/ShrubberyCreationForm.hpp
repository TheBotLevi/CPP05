/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levi_jeri <levi_jeri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 20:37:21 by levi_jeri         #+#    #+#             */
/*   Updated: 2026/01/25 22:37:50 by levi_jeri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class SCF : public AForm {
    protected:
    public:
        SCF(const std::string &target);
        SCF(const SCF& other);
        SCF& operator=(const SCF& other);
        ~SCF();

        void execute(Bureaucrat const & executor) {
            std::cout << "Overriding execute function here!\n";
        }

};