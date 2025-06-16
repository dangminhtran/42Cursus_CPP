/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 21:10:49 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/29 11:56:37 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Forme Canonique
Form::Form(std::string name, int gradeToSign, int gradeToExecute): _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    this->_is_signed = false;
    std::cout << "Form Constructor called with the name " << this->_name << " with the grade to sign " << 
        this->_gradeToSign << " and the grade to execute " << this->_gradeToExecute << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
    if (this == &rhs)
        return *this;
    std::cout << "Form assignation operator called" << std::endl;
    this->_is_signed = rhs.getIsSignedTag();
    return (*this);
};

Form::Form(Form const &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
    *this = src;
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
    std::cout << "Form deconstructor called" << std::endl;
}

// Getters
int Form::getGradeToExecute()
{
    return this->_gradeToExecute;
}

int Form::getGradeToSign()
{
    return this->_gradeToSign;
}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getIsSignedTag() const
{
    return this->_is_signed;
}

void Form::beSigned(Bureaucrat Bureaucrat)
{
    if (this->_is_signed)
    {
        std::cout << "Form " << this->_name << " is already signed." << std::endl;
        return;
    }
    if (Bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    if (Bureaucrat.getGrade() < HIGHEST_GRADE)
        throw GradeTooHighException();
    this->_is_signed = true;
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
    return ("Highest grade already !");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Lowest grade !");
}