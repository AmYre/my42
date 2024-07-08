/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 00:56:10 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/24 02:20:01 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Zombie
{
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void announce(void);

private:
	std::string name;
};