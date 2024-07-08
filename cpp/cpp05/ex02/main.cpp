/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:01:12 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 20:57:15 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		Bureaucrat Tom("Bureaucrat", 10);
		ShrubberyCreationForm shrub("Shrubby");
		Tom.signForm(shrub);
		Tom.executeForm(shrub);

		RobotomyRequestForm robot("Robby");
		Tom.signForm(robot);
		Tom.executeForm(robot);

		PresidentialPardonForm loSiento("Presidente");
		std::cout << loSiento << std::endl;
		Tom.signForm(loSiento);
		Tom.executeForm(loSiento);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}