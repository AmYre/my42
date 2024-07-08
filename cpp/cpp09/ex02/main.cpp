/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 02:05:19 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/10 03:11:30 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: need arguments" << std::endl;
		return 1;
	}

	PmergeMe PmergeMe;
	std::vector<int> sorterVec;

	for (int i = 1; i < ac; ++i)
	{
		int num = atoi(av[i]);
		if (num > 0)
		{
			sorterVec.push_back(num);
		}
		else
		{
			std::cout << "Error: must be positive integer" << std::endl;
			return 1;
		}
	}

	std::cout << "Before: ";
	for (std::vector<int>::const_iterator it = sorterVec.begin(); it != sorterVec.end(); ++it)
	{
		std::cout << *it << " ";
	}

	clock_t start = clock();
	PmergeMe.FJMIS_Vec(sorterVec);
	clock_t end = clock();
	double diff = double(end - start) / CLOCKS_PER_SEC * 1000000;
	std::cout << std::endl;
	std::cout << "After: ";
	for (std::vector<int>::const_iterator it = sorterVec.begin(); it != sorterVec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time taken by std::vector: " << diff << "us" << std::endl;

	std::list<int> sorterList(sorterVec.begin(), sorterVec.end());
	start = clock();
	PmergeMe.FJMIS_List(sorterList);
	end = clock();
	diff = double(end - start) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time taken by std::list: " << diff << "us" << std::endl;

	return 0;
}