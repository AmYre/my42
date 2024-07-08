/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:57:36 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/12 19:51:10 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
private:
	std::string ideas[100];
	int length;

public:
	Brain();
	Brain(const Brain &brain);
	Brain &operator=(const Brain &brain);
	~Brain();

	std::string getIdea(int index) const;
	void setIdea(int index, std::string idea);
};