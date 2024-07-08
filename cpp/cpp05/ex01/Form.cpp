/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:09:15 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/16 21:06:05 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Exceptions.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), isSigned(false), SignerGrade(150), ExecutorGrade(150)
{
	std::cout << "Form Default constructor called" << std::endl;
};

Form::Form(std::string const &name, int signer, int executor) : name(name), isSigned(false), SignerGrade(signer), ExecutorGrade(executor)
{
	std::cout << "Form Parametric constructor called" << std::endl;
	if (signer < 1 || executor < 1)
		throw GradeTooHighException();
	if (signer > 150 || executor > 150)
		throw GradeTooLowException();
};

Form::Form(Form const &cpy) : name(cpy.name), SignerGrade(cpy.SignerGrade), ExecutorGrade(cpy.ExecutorGrade)
{
	std::cout << "Form Copy constructor called" << std::endl;
	*this = cpy;
};

Form &Form::operator=(Form const &cpy)
{
	if (this != &cpy)
	{
		std::cout << "Form Assignation operator called" << std::endl;
		this->isSigned = cpy.isSigned;
	}
	return *this;
};

Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
};

std::string const &Form::getName() const
{
	return this->name;
};

bool Form::getIsSigned() const
{
	return this->isSigned;
};

void Form::setIsSigned()
{
	this->isSigned = true;
};

int Form::getSigner() const
{
	return this->SignerGrade;
};

int Form::getExecutor() const
{
	return this->ExecutorGrade;
};

void Form::beSigned(Bureaucrat &bureaucrat)
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

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << " is signed: " << form.getIsSigned() << " Signer grade: " << form.getSigner() << " Executor grade: " << form.getExecutor();
	return out;
};
