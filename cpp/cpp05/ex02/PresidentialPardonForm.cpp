/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:27:57 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/16 20:29:28 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Exceptions.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialForm", 25, 5)
{
	std::cout << "PresidentialForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialForm", 25, 5), target(target)
{
	std::cout << "PresidentialForm parametric constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other)
{
	std::cout << "PresidentialForm copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	std::cout << "PresidentialForm assignation operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialForm destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecutor())
		throw GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}