/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:15:59 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/06 14:46:33 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->contact_count = 0;
    this->oldest_contact = 0;
}

PhoneBook::~PhoneBook()
{
    return;
}

void PhoneBook::add_contact()
{
    Contact new_contact;
    std::string input;
    
    std::cout << "Enter first name: ";
    std::getline(std::cin, input);
    new_contact.set_first_name(input);

    std::cout << "Enter last name: ";
    std::getline(std::cin, input);
    new_contact.set_last_name(input);

    std::cout << "Enter nickname: ";

    std::getline(std::cin, input);
    new_contact.set_nickname(input);

    std::cout << "Enter phone number: ";
    std::getline(std::cin, input);
    new_contact.set_phone_number(input);

    std::cout << "Enter darkest secret: ";
    std::getline(std::cin, input);
    new_contact.set_darkest_secret(input);

    if (this->contact_count < 8)
    {
        this->contacts[this->contact_count] = new_contact;
        this->contact_count++;
    }
    else
    {
        std::cout << "Phone book is full, replacing oldest contact at index " << this->oldest_contact << std::endl;
        this->contacts[this->oldest_contact] = new_contact;
        this->oldest_contact = (this->oldest_contact + 1) % 8;
    }
}

void PhoneBook::search_contact()
{
    if (this->contact_count == 0)
    {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;
    std::cout << std::string(44, '-') << std::endl;

    for (int i = 0; i < this->contact_count; i++)
    {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << format_string(this->contacts[i].get_first_name()) << "|"
                  << std::setw(10) << format_string(this->contacts[i].get_last_name()) << "|"
                  << std::setw(10) << format_string(this->contacts[i].get_nickname()) << std::endl;
    }

    int index;
    std::cout << "Enter index: ";
    
    if (!(std::cin >> index) || index < 0 || index >= this->contact_count)
    {
        std::cout << "Invalid index" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }

    this->print_contact(index);
}

void PhoneBook::print_contact(int index)
{
    std::cout << "First name: " << this->contacts[index].get_first_name() << std::endl;
    std::cout << "Last name: " << this->contacts[index].get_last_name() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].get_nickname() << std::endl;
    std::cout << "Phone number: " << this->contacts[index].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << this->contacts[index].get_darkest_secret() << std::endl;
}

void PhoneBook::exit_phone()
{
    std::cout << "Exiting phone book. All contacts will be lost forever!" << std::endl;
    std::exit(0);
}

std::string PhoneBook::format_string(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}