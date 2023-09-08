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
