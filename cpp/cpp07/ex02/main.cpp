/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:56:25 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/31 22:26:11 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

int main()
{
	// Test avec un tableau d'entiers
	Array<int> intArray(5);
	for (int i = 0; i < 5; i++)
		intArray[i] = i;
	for (int i = 0; i < 5; i++)
		std::cout << intArray[i] << std::endl;
	std::cout << "Size: " << intArray.size() << std::endl;
	std::cout << "accessing index 3 with subscript operator: " << intArray[3] << std::endl;
	// Test avec un tableau de chaînes de caractères
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";
	for (int i = 0; i < 3; i++)
		std::cout << strArray[i] << std::endl;

	// Test d'accès à un indice en dehors de la plage valide
	try
	{
		std::cout << intArray[10] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}