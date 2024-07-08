/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Exceptions.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 20:26:43 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/04 20:40:03 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

class Capacity : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Error: Capacity exceeded";
	}
};

class NoSpan : public std::exception
{
public:
	virtual const char *what() const throw()
	{
		return "Error: No span to find";
	}
};