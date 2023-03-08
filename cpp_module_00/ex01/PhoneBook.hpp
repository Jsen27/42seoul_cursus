/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:59:55 by sehjung           #+#    #+#             */
/*   Updated: 2023/03/08 20:28:37 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef _PHONEBOOK_HPP_
# define _PHONEBOOK_HPP_

#include "main.hpp"
#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact array[8];
	int	idx;
	
	public:
	PhoneBook()
	{
		this->idx = 0;
	}
	void Addarray();
	~PhoneBook(){}
};


# endif
