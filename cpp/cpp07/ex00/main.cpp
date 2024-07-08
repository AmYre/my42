/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:41:33 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/31 21:58:13 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#include "Person.hpp"

int main(void)
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	// std::string name = "John";
	// std::string name2 = "Jane";
	// Person john(name, 25);
	// Person jane(name2, 30);
	// ::swap(john, jane);
	// std::cout << "john name = " << john.name << ", john age = " << john.age << std::endl;
	// std::cout << "jane name = " << jane.name << ", jane age = " << jane.age << std::endl;
	// std::cout << "min = " << ::min(john, jane) << std::endl;
	// std::cout << "max = " << ::max(john, jane) << std::endl;

	return 0;
}