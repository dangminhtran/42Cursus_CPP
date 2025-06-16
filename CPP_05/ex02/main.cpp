/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:57:43 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/29 16:54:35 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
    try
    {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);
        
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Robot");
        PresidentialPardonForm pardon("Criminal");

        bob.signForm(shrubbery);
        bob.executeForm(shrubbery);

        alice.signForm(robotomy);
        alice.executeForm(robotomy);

        bob.signForm(pardon);
        bob.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
    
}