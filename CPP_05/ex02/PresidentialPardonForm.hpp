#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
    private:
		std::string const	_target;
		void				beExecuted(void) const;
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

		class FileException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
