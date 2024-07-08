/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:00:19 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/17 19:26:38 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>

class GradeTooHighException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Grade is too high";
	}
};

class GradeTooLowException : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Grade is too low";
	}
};