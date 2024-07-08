/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:02:30 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/29 22:03:12 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.num = 42;
	data.str = "Hello, World!";

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized: " << serialized << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Data: " << deserialized->num << std::endl;
	if (deserialized == &data)
	{
		std::cout << "The deserialized pointer is equal to the original pointer." << std::endl;
	}
	else
	{
		std::cout << "The deserialized pointer is not equal to the original pointer." << std::endl;
	}

	return (0);
}