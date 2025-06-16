/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:57:43 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/30 12:10:36 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat *BernardBrct = new Bureaucrat("Bernard", 150);
    
    try {
        BernardBrct->incrementGrade(); // ne fonctionnera pas
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    delete BernardBrct;
    
    Bureaucrat *KarenBrct = new Bureaucrat("Karen", 1);
    
    try {
        KarenBrct->decrementGrade(); // ne fonctionnera pas
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    delete KarenBrct;

    return (0);
    
}