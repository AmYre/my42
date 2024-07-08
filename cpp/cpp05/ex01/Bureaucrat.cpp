/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:32:52 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 19:41:10 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name)
{
	std::cout << "Bureaucrat Parametric constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &bureau)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = bureau;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &bureau)
{
	std::cout << "Bureaucrat Assignation operator called" << std::endl;
	if (this != &bureau)
	{
		this->grade = bureau.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

std::string const &Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	this->grade++;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureau)
{
	o << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
	return o;
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned())
	{
		throw AlreadySignedException();
	}
	else if (this->grade > form.getSigner())
	{
		throw GradeTooLowForSignException();
	}
	else
	{
		std::cout << this->name << " signed " << form.getName() << std::endl;
		form.setIsSigned();
	}
}