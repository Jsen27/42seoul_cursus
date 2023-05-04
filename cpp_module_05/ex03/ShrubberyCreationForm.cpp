#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137)
{
	std::cout << "Default constructor for ShrubberyCreationForm class has been called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
: AForm(name, 145, 137)
{
	std::cout << "constructor for ShrubberyCreationForm class has been created with " << AForm::getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref) : AForm(ref.getName(), ref.getGradeSign(), ref.getGradeExecute())
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " is being destroyed." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &ref)
		AForm::operator=(ref);
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& ref) const
{
	if (ref.getGrade() > this->getGradeExecute())
	{
		std::cerr << ref.getName() << " couldn't execute " << this->getName() << " because ";
		throw AForm::GradeTooLowException();
	}
	else
	{
		std::string filename = this->getName() + "_shrubbery";
		std::ofstream ofs(filename);

		if (!ofs.is_open()){
			throw std::runtime_error("Failed to open file " + filename);
		}

	ofs << "                 v\n"
        << "                >X<\n"
        << "                 A\n"
        << "                d$b\n"
        << "             .d$$$$$b.\n"
        << "           .d$i$$$$$$b.\n"
        << "              d$$$@b\n"
        << "             d$$$$i$b\n"
        << "           .d$$$$$$$$b\n"
        << "         .d$$@$$$$$$$ib.\n"
        << "             d$$i$$$$b\n"
        << "            d$$$$@$$$$b\n"
        << "         .d$@$$$$$$$$$@b.\n"
        << "   	   .d$$$$i$$$##$$$i$$b.\n"
        << "          d$$$$$$$$$$$b\n"
        << "         A$$$$$$$$$$$$$A\n"
        << "        d$$$$$$$$$$$$$$$b\n"
        << "       d$$$$$$$$$$$$$$$$$b\n"
        << "      d$$$$$$$$$$$$$$$$$$$b\n"
        << "     d$$$$$$$$$$$$$$$$$$$$$b\n"
        << "    d$$$$$$$$$$$$$$$$$$$$$$$b\n"
        << "  .d$$$$$$$$$$$$$$$$$$$$$$$$$ib.\n"
        << " .$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$.\n"
        << "                O\n"
        << "                O\n"
        << "                O\n";


    ofs.close();

    std::cout << "ShrubberyCreationForm: Successfully created file " << filename << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& ref)
{
	os << "Name: " << ref.getName() << ", ";
	os << "Signed: " << std::boolalpha << ref.getSign() << ", ";
	os << "Grade required to sign: " << ref.getGradeSign() << ", ";
    os << "Grade required to execute: " << ref.getGradeExecute();
	return os;
}
