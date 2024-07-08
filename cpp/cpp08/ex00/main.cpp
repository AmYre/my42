/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:42:28 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/04 18:06:49 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"

int main()
{
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
		deq.push_back(i);
	}

	try
	{
		std::cout << *easyFind(vec, 5) << std::endl;
		std::cout << *easyFind(lst, 5) << std::endl;
		std::cout << *easyFind(deq, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Value not found" << std::endl;
	}
	return 0;
}