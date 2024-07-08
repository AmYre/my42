/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 22:18:51 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/11 22:18:59 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(const WrongCat &wrongCat);
	WrongCat &operator=(const WrongCat &wrongCat);
	virtual ~WrongCat();
	void makeSound() const;
};