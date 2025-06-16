/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:56:24 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/30 11:56:16 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
  //  std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
    *this = src;
  //  std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &rhs)
{
    if (this == &rhs)
        return (*this);
    (void)rhs;
	return (*this);
}

Intern::~Intern()
{
 //   std::cout << "Intern destructor called" << std::endl;
}

static AForm	*createShrubberyCreationForm(std::string const & target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*createRobotomyRequestForm(std::string const & target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*createPresidentialPardonForm(std::string const & target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string name, std::string const &target) const
{
   AForm	*newForm = NULL;
	const	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(*formCreators[])(std::string const & target) = {&createShrubberyCreationForm, &createRobotomyRequestForm, &createPresidentialPardonForm};

	std::transform(name.begin(), name.end(), name.begin(), ::tolower);
	for (size_t i = 0; i < (sizeof(forms) / sizeof(forms[0])); i++)
	{
		if (name == forms[i])
		{
			newForm = formCreators[i](target);
			break;
		}
	}
	if (!newForm)
		std::cout << "Form with name " << name << " not found." << std::endl;
	else
		std::cout << "Intern creates " << newForm->getName() << std::endl;
	return (newForm);
}

