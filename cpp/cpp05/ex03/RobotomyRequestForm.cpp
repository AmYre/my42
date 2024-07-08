/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 20:20:47 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 21:09:27 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyForm", 72, 45)
{
	std::cout << "RobotomyForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyForm", 72, 45), target(target)
{
	std::cout << "RobotomyForm parametric constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other)
{
	std::cout << "RobotomyForm copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	std::cout << "RobotomyForm assignation operator called" << std::endl;
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyForm destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getExecutor())
		throw GradeTooLowException();
	std::cout << "BrrrzzzzBBrrrrrr RRRrrrrr!!!" << std::endl;
	srand(std::time(0));
	if (rand() % 2)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->target << " robotomization failed" << std::endl;
}
