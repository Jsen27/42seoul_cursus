/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:02:18 by sehjung           #+#    #+#             */
/*   Updated: 2023/03/08 20:27:42 by sehjung          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

# ifndef _CONTACT_HPP_
# define _CONTACT_HPP_

# include "main.hpp"

class Contact
{
	private:
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string number;
	
	public:
	Contact(){}
	void Addcontact();
};

# endif