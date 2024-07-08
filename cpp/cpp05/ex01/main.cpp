/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:01:12 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 20:50:28 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Exceptions.hpp"

int main()
{
	try
	{
		// Bureaucrat bureau1("Bureaucrat1", 0);
		// Bureaucrat bureau2("Bureaucrat2", 151);
		Bureaucrat bureau3("Bureaucrat3", 150);

		std::cout << bureau3.getName() << " " << bureau3.getGrade() << std::endl;
		bureau3.incrementGrade();
		std::cout << bureau3.getName() << " " << bureau3.getGrade() << std::endl;
		bureau3.decrementGrade();
		std::cout << bureau3.getName() << " " << bureau3.getGrade() << std::endl;

		Bureaucrat bureau4("Bureaucrat4", 140);
		std::cout << bureau4 << std::endl;

		Form form1("Form1", 1, 10);
		form1.beSigned(bureau4);

		std::cout << form1 << std::endl;
	}
	catch (std::exception &err)
	{
		std::cout << err.what() << std::endl;
	}

	return 0;
}