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
		std::string secret;
	
	public:
		void Addcontact();
		std::string output(int flag);
};

# endif