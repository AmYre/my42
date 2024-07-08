/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:01:12 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/16 21:21:06 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Exceptions.hpp"

int main()
{
	try
	{
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		Bureaucrat Bureau("Bureaucrat", 1);
		rrf->beSigned(Bureau);
		rrf->execute(Bureau);
		std::cout << *rrf << std::endl;
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}