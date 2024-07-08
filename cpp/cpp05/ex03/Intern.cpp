/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:50:17 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/16 20:58:01 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Exceptions.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = other;
}

Intern &Intern::operator=(Intern const &other)
{
	std::cout << "Intern assignation operator called" << std::endl;
	if (this != &other)
	{
		(void)other;
	}
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

// You must avoid unreadable and ugly solutions like using a if/elseif/else forest. This
// kind of things won’t be accepted during the evaluation process

AForm *Intern::makeForm(std::string const &formName, std::string const &target)
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*formFunctions[3])(std::string const &target) = {&Intern::makeShrubForm, &Intern::makeRobotForm, &Intern::makePrezForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*formFunctions[i])(target);
		}
	}
	throw FormNotFoundException();
	return NULL;
}

AForm *Intern::makeShrubForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePrezForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}