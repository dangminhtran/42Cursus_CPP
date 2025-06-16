/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:51:38 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/18 12:31:13 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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