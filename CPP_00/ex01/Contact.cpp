/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:04:01 by dangtran          #+#    #+#             */
/*   Updated: 2025/03/29 18:11:14 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
    this->first_name = "";
    this->last_name = "";
    this->nickname = "";
    this->phone_number = "";
    this->darkest_secret = "";
}

Contact::~Contact()
{
    return;
}

void Contact::set_first_name(std::string first_name)
{
    this->first_name = first_name;
}

void Contact::set_last_name(std::string last_name)
{
    this->last_name = last_name;
}

void Contact::set_nickname(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::set_darkest_secret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

void Contact::set_phone_number(std::string phone_number)
{
    for (size_t i = 0; i < phone_number.length(); i++) {
        if (!isdigit(phone_number[i])) {
            std::cout << "Error: Phone number must contain only digits." << std::endl;
            return;
        }
    }
    this->phone_number = phone_number;
}

std::string Contact::get_first_name()
{
    return this->first_name;
}

std::string Contact::get_last_name()
{
    return this->last_name;
}

std::string Contact::get_nickname()
{
    return this->nickname;
}

std::string Contact::get_phone_number()
{
    return this->phone_number;
}

std::string Contact::get_darkest_secret()
{
    return this->darkest_secret;
}

