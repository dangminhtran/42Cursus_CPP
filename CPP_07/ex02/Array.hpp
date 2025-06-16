/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:34:35 by dangtran          #+#    #+#             */
/*   Updated: 2025/06/16 17:02:00 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib>
# include <ctime>
# include <iostream>

template <typename T>

class Array
{
  private:
	T *_array;
	size_t _size;

  public:
	// Construction with no parameter: Creates an empty array.
	Array(void) : _array(NULL), _size(0)
	{
	}

	/* Construction with an unsigned int n as a parameter: Creates an array of n elements
	initialized by default */
	Array(unsigned int n) : _array(new T[n]), _size(n)
	{
		for (size_t i = 0; i < n; i++)
			_array[i] = T();
	}
	/* modifying either the original array or its copy after copying musn’t affect the other array*/
	Array(Array const &src) : _array(new T[src._size]), _size(src._size)
	{
		for (size_t i = 0; i < src._size; i++)
			_array[i] = src._array[i];
	}

	Array &operator=(Array const &src)
	{
		if (this != &src)
		{
			T *tmp = new T[src._size];
			for (size_t i = 0; i < src._size; i++)
				tmp[i] = src._array[i];
			delete[] _array;
			_array = tmp;
			_size = src._size;
		}
		return (*this);
	}

	~Array(void)
	{
		delete[] _array;
	}

	T &operator[](size_t i)
	{
		if (i >= _size)
			throw IndexException();
		return (_array[i]);
	}

	size_t size(void) const
	{
		return (_size);
	}

	class IndexException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("Index out of bounds");
		}
	};
};


#endif