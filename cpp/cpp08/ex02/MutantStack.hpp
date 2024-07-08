/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 00:41:17 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/05 01:34:55 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(MutantStack const &other) : std::stack<T>(other) {}
	MutantStack &operator=(MutantStack const &other)
	{
		this->c = other.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename std::deque<T>::iterator iterator;
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};