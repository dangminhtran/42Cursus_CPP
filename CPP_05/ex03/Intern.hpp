#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <algorithm>

class AForm;

class Intern
{
public:
    Intern();
    Intern(Intern const &src);
    ~Intern();
    Intern &operator=(Intern const &rhs);

    AForm *makeForm(std::string name, std::string const &target) const;

    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif