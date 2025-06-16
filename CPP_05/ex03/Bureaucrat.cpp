/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:25:04 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/30 12:01:38 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Forme canonique
Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
  //  std::cout << "Bureaucrat Constructor called with the name: " << this->getName() << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    *this = src;
 //   std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this == &rhs)
        return (*this);
  //  std::cout << "Bureaucrat assignation operator called" << std::endl;
    this->_grade = rhs.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
 //   std::cout << "Bureaucrat destructor called" << std::endl;
}

// Getters
std::string Bureaucrat::getName() const
{
    return (this->_name);   
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);    
}

// Fonctions membres
void Bureaucrat::incrementGrade()
{
    if (_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
    
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
}

bool Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->getName() << " signs " << form.getName() << std::endl;
        return (true);
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
        return (false);
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
   try
	{
		form.execute(*this);
		std::cout << _name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

// Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Highest grade already !");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Lowest grade already !");
}

// Pourquoi faire ??
std::ostream &operator<<(std::ostream &os, Bureaucrat const &other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade() << std::endl;
	return (os);
}
