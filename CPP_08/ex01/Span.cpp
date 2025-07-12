/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 17:01:49 by dangtran          #+#    #+#             */
/*   Updated: 2025/07/06 10:23:51 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _nb(0) {}

Span::Span(unsigned int nb) : _nb(nb) {}

Span::Span(Span const &src) : _nb(src._nb), _v(src._v) {}

Span::~Span(void) {}

Span	&Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->_nb = src._nb;
		this->_v = src._v;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_v.size() >= this->_nb)
		throw Span::SpanFullException();
	this->_v.push_back(n);
}

void	Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_v.size() + std::distance(begin, end) > this->_nb)
		throw Span::SpanFullException();
	this->_v.insert(this->_v.end(), begin, end);
}

int	Span::shortestSpan(void)
{
	int					span;
	std::vector<int>	tmp;

	if (this->_v.size() < 2)
		throw Span::NoSpanException();
	tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());
	span = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < span)
			span = tmp[i] - tmp[i - 1];
	}
	return (span);
}

int	Span::longestSpan(void)
{
	std::vector<int>	tmp;

	if (this->_v.size() < 2)
		throw Span::NoSpanException();
	tmp = this->_v;
	std::sort(tmp.begin(), tmp.end());
	return (tmp[tmp.size() - 1] - tmp[0]);
}

// Exceptions
const char* Span::NoSpanException::what() const throw()
{
	return ("No span to find");
}

const char* Span::SpanFullException::what() const throw()
{
	return ("Span is full");
}