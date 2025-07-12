/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:49:51 by dangtran          #+#    #+#             */
/*   Updated: 2025/07/06 10:56:02 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>

class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void) : std::stack<T>() {}
		MutantStack(MutantStack const &src) : std::stack<T>(src) {}
		~MutantStack(void) {}

		MutantStack &operator=(MutantStack const &src)
		{
			if (this != &src)
				std::stack<T>::operator=(src);
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack< T >::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack< T >::container_type::const_reverse_iterator const_reverse_iterator;
	
		iterator	begin(void) { return (std::stack<T>::c.begin()); }
		const_iterator	begin(void) const { return (std::stack<T>::c.begin()); }
		
		iterator	end(void) { return (std::stack<T>::c.end()); }
		const_iterator	end(void) const { return (std::stack<T>::c.end()); }
		
		reverse_iterator rbegin( void ) { return ( this->c.rbegin() ); }
		reverse_iterator rend( void ) { return ( this->c.rend() ); }
		
		const_reverse_iterator rbegin( void ) const { return ( this->c.rbegin() ); }
		const_reverse_iterator rend( void ) const { return ( this->c.rend() ); }	

	};

#endif