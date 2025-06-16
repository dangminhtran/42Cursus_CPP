
#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define BRAIN_SIZE 100

class Brain
{
	private:
		std::string	_ideas[BRAIN_SIZE];
	public:
		Brain(void);
		Brain(Brain const &src);
		virtual ~Brain(void);

		Brain & operator=(Brain const &rhs);

		const std::string			getIdea(int i) const;
		const std::string			*getIdeas(void) const;
		void				setIdea(int i, std::string idea);
		void				setIdeas(const std::string *ideas);
};

#endif 