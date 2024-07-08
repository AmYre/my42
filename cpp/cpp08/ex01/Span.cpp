/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:08:21 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/05 00:31:38 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : nbr(0), vec(0) {}

Span::Span(unsigned int nbr) : nbr(nbr), vec(0) {}

Span::Span(Span const &other) : nbr(other.nbr), vec(other.vec) {}

Span &Span::operator=(Span const &other)
{
	if (this == &other)
		return *this;
	nbr = other.nbr;
	vec = other.vec;
	return *this;
}

Span::~Span() {}

void Span::addNumber(int nbr)
{
	if (vec.size() >= this->nbr)
		throw Capacity();
	vec.push_back(nbr);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (vec.size() + std::distance(begin, end) > this->nbr)
		throw Capacity();
	vec.insert(vec.end(), begin, end);
}

int Span::shortestSpan()
{
	if (vec.size() <= 1)
		throw NoSpan();
	std::vector<int> tmp(vec);
	std::sort(tmp.begin(), tmp.end());
	int min = tmp[1] - tmp[0];
	for (std::vector<int>::iterator it = tmp.begin() + 2; it != tmp.end(); ++it)
	{
		if (*it - *(it - 1) < min)
			min = *it - *(it - 1);
	}
	return min;
}

int Span::longestSpan()
{
	if (vec.size() <= 1)
		throw NoSpan();
	std::vector<int> tmp(vec);
	std::sort(tmp.begin(), tmp.end());
	return tmp[tmp.size() - 1] - tmp[0];
}
