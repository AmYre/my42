/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 02:13:56 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/24 03:05:27 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
public:
	Zombie();
	~Zombie();

	int nbr;
	int nbr_of_zombies;
	void announce(std::string name, int nbr);

private:
	std::string name;
};