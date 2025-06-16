/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:33:37 by dangtran          #+#    #+#             */
/*   Updated: 2025/04/19 14:32:27 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <cstdlib>

std::string ft_replace(std::string buffer, const std::string search, const std::string replace)
{
	size_t	search_length = search.length();
	size_t	replace_length = replace.length();
	size_t	pos_search = 0;

	pos_search = buffer.find(search);
	while (pos_search != std::string::npos)
	{
		buffer.erase(pos_search, search_length);
		buffer.insert(pos_search, replace);
		pos_search = buffer.find(search, pos_search + replace_length);
	}
	return (buffer);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Error : Wrong number of arguments" << std::endl <<
		"Hint: ./replace <filename> <search> <replace>" << std::endl;
	}
	else
	{
		const std::string	filename = argv[1];
		const std::string	search = argv[2];
		const std::string	replace = argv[3];
		std::string			buffer;
		std::ifstream		infile;
        std::ofstream		outfile;

		infile.open(argv[1]);
		if (infile.is_open() == true)
		{
			outfile.open(filename + ".replace", std::ios::out | std::ios::trunc );
			if (outfile.is_open())
			{
				while (std::getline(infile, buffer))
				{
					buffer = ft_replace(buffer, search, replace);
					// Write the modified line to the outfile
					outfile << buffer;
					// peek() returns the next character in the stream without extracting it
					if (infile.peek() != EOF)
						outfile << std::endl;
				}
				outfile.close();
			}
			else
			{
				std::perror("Outfile Error");
				infile.close();
				return (EXIT_FAILURE);
			}
			infile.close();
		}
		else
		{
			std::perror("Infile Error");
			std::cerr << "Outfile not created or truncated.\n" << std::endl;
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
