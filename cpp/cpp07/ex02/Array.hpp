/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:08:13 by amben-ha          #+#    #+#             */
/*   Updated: 2024/05/31 22:24:46 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array
{
private:
	T *array;
	unsigned int length;

public:
	Array();
	Array(unsigned int n);
	Array(Array const &other);
	~Array();
	Array &operator=(Array const &other);
	T &operator[](unsigned int i);
	unsigned int size() const;
};

template <typename T>
Array<T>::Array() : array(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]()), length(n) {}

template <typename T>
Array<T>::Array(Array const &other) : array(new T[other.length]()), length(other.length)
{
	if (other.length == 0)
		return;
	for (unsigned int i = 0; i < length; i++)
		array[i] = other.array[i];
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this != &other && other.length > 0)
	{
		delete[] array;
		array = new T[other.length]();
		length = other.length;
		for (unsigned int i = 0; i < length; i++)
			array[i] = other.array[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= length)
		throw std::out_of_range("Index out of range");
	return array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return length;
}
