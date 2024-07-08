/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 02:01:54 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/10 03:18:18 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <vector>
#include <algorithm>
#include <cmath>

class PmergeMe
{
private:
	std::vector<int> vec;
	std::list<int> lst;

public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	void FJMIS_Vec(std::vector<int> &arr);
	void FJMIS_List(std::list<int> &arr);
};