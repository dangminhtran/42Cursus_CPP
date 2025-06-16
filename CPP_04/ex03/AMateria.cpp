/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:18:14 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/17 15:55:50 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria( void ) : _type("default")
{
//    std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
//    std::cout << "AMateria constructor with type " << this->_type << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
//    std::cout << "AMateria copy constructor " << std::endl;
    *this = src;
}

AMateria &AMateria::operator=(AMateria const &other)
{
    if (this == &other)
        return (*this);
//    std::cout << "AMateria assignation operator" << std::endl;
    this->_type = other._type;
    return (*this);
}

AMateria::~AMateria (void)
{
//    std::cout << "AMateria destructor called " << std::endl;
}

const std::string &AMateria::getType() const
{
    return (this->_type);
}

void AMateria::use(ICharacter &target)
{
    (void)target;
    std::cout << "AMateria use function called" << std::endl;
}