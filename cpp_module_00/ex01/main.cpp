/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:59:40 by sehjung           #+#    #+#             */
/*   Updated: 2023/03/08 22:44:31 by sehjung          ###   ########.fr       */
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
		std::cout << GREEN "Press enter your command   (Hint : ADD, SEARCH, EXIT)" BLUE << std::endl;
		std::cin >> input;
		if (input == "ADD")
			mybook.Addarray();
		else if (input == "SEARCH")
			mybook.Search_contact();
		else if (input == "EXIT")
			break;
		else
			std::cout << RED << input << RED " is not command" NC << std::endl;
	}
	
	return 0;
}