/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 19:28:39 by amben-ha          #+#    #+#             */
/*   Updated: 2024/06/10 03:05:03 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string csvFile) : filename(csvFile)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::mapExchange()
{
	std::ifstream file(this->filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	while (std::getline(file, line))
	{
		std::string date = line.substr(0, line.find_first_of(','));
		std::string value = line.substr(line.find_first_of(',') + 1);
		this->exchange.insert(std::make_pair(date, atof(value.c_str())));
	}
	file.close();
}

void BitcoinExchange::mapValues(std::string inputFile)
{
	std::ifstream file(inputFile.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	std::string line;
	while (std::getline(file, line))
	{
		if (line.find_first_of('|') == std::string::npos)
		{
			std::cerr << "Error - Invalid line: " << line << std::endl;
			continue;
		}
		std::string date = trim(line.substr(0, line.find_first_of('|')));
		std::string value = trim(line.substr(line.find_first_of('|') + 1));
		if (!isValidDate(date))
		{
			std::cerr << "Error - Invalid date: " << date << std::endl;
			continue;
		}
		std::istringstream iss(value);
		float fvalue;
		iss >> fvalue;
		if (iss.fail() || fvalue < 1 || fvalue > 999)
		{
			std::cerr << "Error - Invalid value: " << value << std::endl;
			continue;
		}
		this->values.insert(std::make_pair(date, fvalue));
	}
}

void BitcoinExchange::displayResults()
{
	for (std::multimap<std::string, float>::iterator it = this->values.begin(); it != this->values.end(); ++it)
	{
		std::string date = it->first;
		float value = it->second;

		std::multimap<std::string, float>::iterator exchangeIt = this->exchange.lower_bound(date);
		if (exchangeIt != this->exchange.begin())
			--exchangeIt;
		if (exchangeIt != this->exchange.end())
		{
			float exchangeRate = exchangeIt->second;
			std::cout << date << " => " << value << " = " << value * exchangeRate << std::endl;
		}
		else
			std::cout << "No exchange rate found for this date" << date << std::endl;
	}
}

std::string BitcoinExchange::trim(const std::string &str)
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
		return str;
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::isValidDate(const std::string &str)
{
	int month;
	int day;

	if (str.length() != 10)
		return false;
	if (str[4] != '-' || str[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (str[i] < '0' || str[i] > '9')
			return false;
	}

	std::istringstream monthStream(str.substr(5, 2));
	std::istringstream dayStream(str.substr(8, 2));
	monthStream >> month;
	dayStream >> day;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	return true;
}
