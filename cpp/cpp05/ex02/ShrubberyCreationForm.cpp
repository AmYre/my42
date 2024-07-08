/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:54:12 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/16 20:07:23 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyForm", 145, 137), target("default")
{
	std::cout << "ShrubberyForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyForm", 145, 137), target(target)
{
	std::cout << "ShrubberyForm parametric constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other)
{
	std::cout << "ShrubberyForm copy constructor called" << std::endl;
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	std::cout << "ShrubberyForm assignation operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyForm destructor called" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string targetName = this->target + "_shrubbery";
	std::ofstream file(targetName.c_str());
	if (!file.is_open())
		throw FileErrorException();
	file << "      /\\      " << std::endl;
	file << "     /\\*\\     " << std::endl;
	file << "    /\\O\\*\\    " << std::endl;
	file << "   /*/\\/\\/\\   " << std::endl;
	file << "  /\\O\\/\\*\\\\  " << std::endl;
	file << " /\\*\\/\\*\\/\\\\ " << std::endl;
	file << "/\\O\\/\\/*/\\/o\\" << std::endl;
	file << "      ||||      " << std::endl;
	file << "      ||||      " << std::endl;
	file << std::endl;

	file.close();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
};