/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:57:43 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/30 12:05:39 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat bob("Bob", 1);
	Bureaucrat alice("Alice", 150);
	Intern intern;

	try
	{
		AForm *form1 = intern.makeForm("shrubbery creation", "Garden");
		bob.signForm(*form1);
		bob.executeForm(*form1);
		delete form1;

		AForm *form2 = intern.makeForm("robotomy request", "Robot");
		alice.signForm(*form2);
		bob.executeForm(*form2);
		delete form2;

		AForm *form3 = intern.makeForm("presidential pardon", "Criminal");
		bob.signForm(*form3);
		bob.executeForm(*form3);
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}