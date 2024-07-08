/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 19:55:00 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/29 22:10:10 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
	Serializer();

public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};