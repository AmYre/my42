/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 02:04:43 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/10 03:16:54 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
	this->vec = other.vec;
	this->lst = other.lst;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
	if (this == &other)
		return (*this);
	this->vec = other.vec;
	this->lst = other.lst;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::FJMIS_Vec(std::vector<int> &arr)
{
	int n = arr.size();
	if (n <= 1)
		return;

	std::vector<int> S(n / 2);
	std::vector<int> unpaired(n - n / 2);

	for (int i = 0; i < n / 2; ++i)
	{
		if (arr[2 * i] > arr[2 * i + 1])
		{
			S[i] = arr[2 * i];
			unpaired[i] = arr[2 * i + 1];
		}
		else
		{
			S[i] = arr[2 * i + 1];
			unpaired[i] = arr[2 * i];
		}
	}

	if (n % 2 != 0)
		unpaired[n / 2] = arr[n - 1];

	FJMIS_Vec(S);

	std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), unpaired[0]);
	S.insert(it, unpaired[0]);

	for (int i = 1; i < n - n / 2; ++i)
	{
		it = std::lower_bound(S.begin(), S.end(), unpaired[i]);
		S.insert(it, unpaired[i]);
	}
	std::copy(S.begin(), S.end(), arr.begin());
}

void PmergeMe::FJMIS_List(std::list<int> &arr)
{
	int n = arr.size();
	if (n <= 1)
		return;

	std::list<int> S;
	std::list<int> unpaired;

	std::list<int>::iterator it = arr.begin();
	for (int i = 0; i < n / 2; ++i)
	{
		if (*it > *(++it))
		{
			S.push_back(*it);
			unpaired.push_back(*(++it));
		}
		else
		{
			S.push_back(*(++it));
			unpaired.push_back(*it);
		}
	}

	if (n % 2 != 0)
		unpaired.push_back(arr.back());

	FJMIS_List(S);

	std::list<int>::iterator it2 = std::lower_bound(S.begin(), S.end(), unpaired.front());
	S.insert(it2, unpaired.front());

	for (std::list<int>::iterator it3 = unpaired.begin(); it3 != unpaired.end(); ++it3)
	{
		it2 = std::lower_bound(S.begin(), S.end(), *it3);
		S.insert(it2, *it3);
	}
	std::copy(S.begin(), S.end(), arr.begin());
}