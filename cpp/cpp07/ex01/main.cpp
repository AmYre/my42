/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:50:55 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/31 22:05:28 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
}

int main(void)
{
	int tab[] = {0, 1, 2, 3, 4};
	::iter(tab, 5, print);

	std::string tab2[] = {"Hello", "World", "is", "Bonjour", "Le monde"};
	::iter(tab2, 5, print);
	return 0;
}
