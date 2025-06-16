/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 11:54:36 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/27 14:07:36 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed ( void );
        Fixed ( Fixed const &src );
        Fixed &operator=( Fixed const &rhs );
        ~Fixed( void );
        int		getRawBits( void ) const;
        void	setRawBits( int const raw );
    private:
        int					_raw;
        static const int	_bits = 8;
};

#endif 