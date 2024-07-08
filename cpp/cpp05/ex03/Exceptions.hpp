/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:00:19 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 21:05:29 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class GradeTooHighException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Grade is too high, has to be between 1 and 150";
	}
};

class GradeTooLowException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Grade is too low, has to be between 1 and 150";
	}
};

class GradeTooLowForSignException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Grade is too low to sign the form";
	}
};

class AlreadySignedException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Form is already signed";
	}
};

class FormNotSignedException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Form is not signed";
	}
};

class FormNotExecutedException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Form is not executed";
	}
};

class FileErrorException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "File error";
	}
};

class FormNotFoundException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Form not found";
	}
};