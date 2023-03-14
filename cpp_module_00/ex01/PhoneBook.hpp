/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:59:55 by sehjung           #+#    #+#             */
/*   Updated: 2023/03/14 16:51:16 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

# include <iomanip>
# include "Contact.hpp"
# include "utils.h"

class PhoneBook
{
	private:
		Contact array[8];
		int	idx;
		int total;
	
	public:
		PhoneBook();
		void Addarray();
		void Search_contact();
		void print_all(int idx);
		void print_wide(std::string str);
};

# endif
