/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:40:00 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/12 19:56:14 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor" << std::endl;
	length = 0;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy constructor" << std::endl;
	if (brain.length > 0)
	{
		for (int i = 0; i < brain.length; ++i)
		{
			ideas[i] = brain.ideas[i];
		}
	}
	this->length = brain.length;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain assignation operator" << std::endl;
	if (this != &brain)
	{
		if (brain.length > 0)
		{
			for (int i = 0; i < brain.length; ++i)
			{
				ideas[i] = brain.ideas[i];
			}
		}
		this->length = brain.length;
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor" << std::endl;
}

void Brain::setIdea(int index, std::string idea)
{
	ideas[index] = idea;
}
std::string Brain::getIdea(int index) const
{
	return (ideas[index]);
}