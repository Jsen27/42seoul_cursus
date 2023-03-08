/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:02:18 by sehjung           #+#    #+#             */
/*   Updated: 2023/03/08 21:06:58 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef _CONTACT_HPP_
# define _CONTACT_HPP_

# include "utils.h"

class Contact
{
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string number;
	
	public:
		Contact();
		void Addcontact();
};

# include "PhoneBook.hpp"

# endif