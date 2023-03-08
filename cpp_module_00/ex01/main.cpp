/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:59:40 by sehjung           #+#    #+#             */
/*   Updated: 2023/03/08 21:00:35 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
	PhoneBook mybook;
	std::string input;
	
	while (1){
		std::cout << "Press Enter Your Command   (Hint : ADD, SEARCH, EXIT)" << std::endl;
		std::cin >> input;
		if (input == "ADD")
			mybook.Addarray();
		else if (input == "SEARCH")
		{

		}
		else if (input == "EXIT")
			break;
		else
		{
			
		}
	}
	
	return 0;
}