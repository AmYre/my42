/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:08:24 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/04 20:28:01 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include "Exceptions.hpp"

class Span
{
private:
	unsigned int nbr;
	std::vector<int> vec;

public:
	Span();
	Span(unsigned int nbr);
	Span(Span const &other);
	Span &operator=(Span const &other);
	~Span();

	void addNumber(int nbr);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
};