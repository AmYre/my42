/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:14:22 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/24 02:23:43 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name );

int main(void)
{
	Zombie *zombies = zombieHorde(5, "Zombie Horde");

	delete [] zombies;
	return (0);
}