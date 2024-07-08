/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 00:19:51 by amben-ha          #+#    #+#             */
/*   Updated: 2024/04/25 01:31:39 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"
#include <string>

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void	add_contact();
	void	search_contact();
	void	check_contact(std::string str);
	int		get_flag();
	int		get_nbr_of_contacts();

private:
	int 	flag;
	int		nbr_of_contacts;
	Contact	contact[8];
};

#endif