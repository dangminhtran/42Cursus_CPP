/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:02:02 by dangtran          #+#    #+#             */
/*   Updated: 2025/07/06 10:37:37 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream> // pour les exceptions
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int		_nb;
		std::vector<int>	_v;
	public:
		Span(void);
		Span(unsigned int nb);
		Span(Span const &src);
		~Span(void);

		Span &operator=(Span const &src);
		
		void	addNumber(int nb);
		void	addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int		shortestSpan(void);
		int		longestSpan(void);
		
		// Exception
		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
				
};

#endif