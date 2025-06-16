/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:49:38 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/29 16:52:33 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Forme canonique
ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShruberryCreationForm",
	145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
	: AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this == &rhs)
		return (*this);
	(void)rhs;
	return (*this);
}

// Exceptions
const char *ShrubberyCreationForm::FileException::what() const throw()
{
	return ("Can't open the file");
}

// Fonctions membres
void ShrubberyCreationForm::beExecuted(void) const
{
	std::string fileName = this->_target + "_shrubbery";
	std::ofstream file;

	file.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!file.is_open())
		throw FileException();
	file << "           ,@@@@@@@,           " << std::endl;
	file << "   ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	file << ",&%%&%&&%,@@@@@/@@@@@@,8888888/8o" << std::endl;
	file << ",%&&%&&%&&%,@@@@@@@/@@@88888888/88'" << std::endl;
	file << "%&&%&%&/%&&%@@@@@/ /@@@88888888888'" << std::endl;
	file << "%&&%/ %&%%&&@@@ V /@@' `8888 `/88'" << std::endl;
	file << "`&%% ` /%&'    |.|        | '|8'" << std::endl;
	file << "    |o|        | |        | |" << std::endl;
	file << "    |.|        | |        | |" << std::endl;
	file << "\\/ ._|//_/__/  ,|_//__\\/. |_//__/_" << std::endl;
	file.close();
}