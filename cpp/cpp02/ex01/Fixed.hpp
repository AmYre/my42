/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:24 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/06 02:04:29 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
  public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &fixed);
	Fixed &operator=(const Fixed &fixed);
	~Fixed();
	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int value;
	static const int fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);