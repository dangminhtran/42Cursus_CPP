#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;
class Form
{
  private:
	std::string const _name;
	bool _is_signed;
	int const _gradeToSign;
	int const _gradeToExecute;

  public:
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form &operator=(Form const &rhs);
	Form(Form const &src);
	~Form(void);

    int getGradeToSign();
    int getGradeToExecute() ;
    std::string getName() const;
    bool getIsSignedTag() const;
    void beSigned(Bureaucrat Bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
		virtual const char *what() const throw();
	};
};

#endif