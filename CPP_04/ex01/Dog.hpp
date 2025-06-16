
#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
		private:
		Brain *_brain;
	public:
		Dog(void);
		Dog(Dog const &src);
		virtual ~Dog(void);

		Dog & operator=(Dog const &rhs);

		virtual void makeSound(void) const;
		Brain	*getBrain(void) const;
};

#endif