/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:59:55 by sehjung           #+#    #+#             */
/*   Updated: 2023/03/09 16:03:35 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact array[8];
		int	idx;
	
	public:
		PhoneBook();
		void Addarray();
		void Search_contact();
		void print_all(int idx);
		std::string	print_wide(std::string str);
};

# endif
