/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dangtran <dangtran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 20:57:43 by dangtran          #+#    #+#             */
/*   Updated: 2025/05/30 12:07:32 by dangtran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
    Bureaucrat *BernardBrct = new Bureaucrat("Bernard", 123);
    Form *Formulaire = new Form("Formulaire B2", 150, 5);
    
    try {
        BernardBrct->signForm(*Formulaire);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    delete BernardBrct;
    delete Formulaire;
    
    Bureaucrat *KarenBrct = new Bureaucrat("Karen", 2);
    Form *Formulaire2 = new Form("Formulaire B3", 1, 1);
    try {
        KarenBrct->signForm(*Formulaire2); // ne fonctionnera pas !
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    delete Formulaire2;
    delete KarenBrct;

    return (0);
    
}