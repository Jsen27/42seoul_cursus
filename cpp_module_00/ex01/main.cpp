/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehjung <sehjung@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:59:40 by sehjung           #+#    #+#             */
/*   Updated: 2023/03/10 18:19:05 by sehjung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string ft_getline()
{
	std::string input;

	std::getline(std::cin, input);
	if (std::cin.fail())
	{
		std::cout << "EOF or ERROR !" << std::endl;
		exit(1);
	}
	return input;
}

int main()
{
	PhoneBook mybook;
	std::string input;
	
	while (1){
		std::cout << GREEN "Press enter your command   (Hint : ADD, SEARCH, EXIT)" BLUE << std::endl;
		input = ft_getline();
		if (input == "ADD")
			mybook.Addarray();
		else if (input == "SEARCH")
			mybook.Search_contact();
		else if (input == "EXIT")
			break;
		else
			std::cout << RED << input << RED " is not command" NC << std::endl;
	}
	std::cout << NC;
	return 0;
}