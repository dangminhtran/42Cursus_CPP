#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;

    while (true)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::cin >> command;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (command == "ADD")
        {
            phonebook.add_contact();
        }
        else if (command == "SEARCH")
        {
            phonebook.search_contact();
        }
        else if (command == "EXIT")
        {
            phonebook.exit_phone();
            break;
        }
        else
        {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    std::cout << "Exiting phonebook..." << std::endl;
    return 0;
}