/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:23:49 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/24 18:47:16 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
# include <iostream>

class Contact
{
public:
	Contact();
	Contact(std::string input_first_name, std::string input_last_name, std::string input_nickname, std::string input_phone_number, std::string input_darkest_secret);
	~Contact();

	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nickname();
	std::string	get_phone_number();
	std::string	get_darkest_secret();

private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif