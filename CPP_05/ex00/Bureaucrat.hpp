#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat 
{
    private:
        std::string const _name;
        int _grade;

    public : 
    Bureaucrat(std::string const name, int grade);
    Bureaucrat &operator=(Bureaucrat const &rhs);
    Bureaucrat(Bureaucrat const &src);
    ~Bureaucrat(void);

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception{
        public:
            virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream & os, Bureaucrat const &other);

#endif