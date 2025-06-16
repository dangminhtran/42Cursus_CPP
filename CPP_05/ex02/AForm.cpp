/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:10:49 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/29 11:56:37 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Forme Canonique
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    this->_is_signed = false;
    std::cout << "AForm Constructor called with the name " << this->_name << " with the grade to sign " << 
        this->_gradeToSign << " and the grade to execute " << this->_gradeToExecute << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
    if (this == &rhs)
        return *this;
    std::cout << "AForm assignation operator called" << std::endl;
    this->_is_signed = rhs.getIsSignedTag();
    return (*this);
};

AForm::AForm(AForm const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    *this = src;
    std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
    std::cout << "AForm deconstructor called" << std::endl;
}

// Getters
int AForm::getGradeToExecute()
{
    return this->_gradeToExecute;
}

int AForm::getGradeToSign()
{
    return this->_gradeToSign;
}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getIsSignedTag() const
{
    return this->_is_signed;
}

// Fonctions membres
void AForm::beSigned(Bureaucrat Bureaucrat)
{
    if (this->_is_signed)
    {
        std::cout << "AForm " << this->_name << " is already signed." << std::endl;
        return;
    }
    if (Bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    if (Bureaucrat.getGrade() < HIGHEST_GRADE)
        throw GradeTooHighException();
    this->_is_signed = true;
}

 void	AForm::execute(const Bureaucrat & executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	else if (!this->_is_signed)
		throw AForm::FormException();
	else
		this->beExecuted();
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Highest grade already !");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Lowest grade !");
}

const char *AForm::FormException::what() const throw()
{
    return ("Form exception occurred");
}