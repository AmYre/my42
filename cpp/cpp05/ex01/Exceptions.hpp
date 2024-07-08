/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:00:19 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 20:49:20 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class GradeTooHighException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Grade is too high, has to be between 1 and 150 included";
	}
};

class GradeTooLowException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Grade is too low, has to be between 1 and 150 included";
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