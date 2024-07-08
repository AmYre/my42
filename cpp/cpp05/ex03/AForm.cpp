/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 22:09:00 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 21:02:07 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), SignerGrade(150), ExecutorGrade(150)
{
	std::cout << "Form Default constructor called" << std::endl;
};

AForm::AForm(std::string const &name, int signer, int executor) : name(name), isSigned(false), SignerGrade(signer), ExecutorGrade(executor)
{
	std::cout << "Form Parametric constructor called" << std::endl;
	if (signer < 1 || executor < 1)
		throw GradeTooHighException();
	if (signer > 150 || executor > 150)
		throw GradeTooLowException();
};

AForm::AForm(AForm const &cpy) : name(cpy.name), SignerGrade(cpy.SignerGrade), ExecutorGrade(cpy.ExecutorGrade)
{
	std::cout << "Form Copy constructor called" << std::endl;
	*this = cpy;
};

AForm &AForm::operator=(AForm const &cpy)
{
	if (this != &cpy)
	{
		std::cout << "Form Assignation operator called" << std::endl;
		this->isSigned = cpy.isSigned;
	}
	return *this;
};

AForm::~AForm()
{
	std::cout << "Form Destructor called" << std::endl;
};

std::string const &AForm::getName() const
{
	return this->name;
};

bool AForm::getIsSigned() const
{
	return this->isSigned;
};

void AForm::setIsSigned()
{
	this->isSigned = true;
};

int AForm::getSigner() const
{
	return this->SignerGrade;
};

int AForm::getExecutor() const
{
	return this->ExecutorGrade;
};

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		bureaucrat.signForm(*this);
	}
	catch (AlreadySignedException &err)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->name << " because " << err.what() << std::endl;
	}
	catch (GradeTooLowForSignException &err)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << this->name << " because " << err.what() << std::endl;
	}
};

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << "Form: " << form.getName() << " | is signed: " << form.getIsSigned() << " | Signer grade: " << form.getSigner() << " | Executor grade: " << form.getExecutor();
	return out;
};
