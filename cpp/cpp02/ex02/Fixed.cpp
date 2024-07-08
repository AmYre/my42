/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 21:01:21 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/06 18:20:28 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
	: value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(value * (1 << fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Assignation operator called" << std::endl;
	value = fixed.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return (value > fixed.getRawBits());
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return (value < fixed.getRawBits());
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return (value >= fixed.getRawBits());
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return (value <= fixed.getRawBits());
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return (value == fixed.getRawBits());
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return (value != fixed.getRawBits());
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(toFloat() / fixed.toFloat()));
}

Fixed &Fixed::operator++()
{
	value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--()
{
	value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)value / (1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (value >> fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
