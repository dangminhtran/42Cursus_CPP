#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class	Bureaucrat;

class AForm
{
  private:
	std::string const _name;
	bool _is_signed;
	int const _gradeToSign;
	int const _gradeToExecute;

	virtual void		beExecuted(void) const = 0;

  public:
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	AForm &operator=(AForm const &rhs);
	AForm(AForm const &src);
	virtual ~AForm(void);

	int getGradeToSign();
	int getGradeToExecute();
	std::string getName() const;
	bool getIsSignedTag() const;
	virtual void beSigned(Bureaucrat Bureaucrat);
	void execute(Bureaucrat const &executor) const;

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

	class FormException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif