
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ( void )
{
	try
	{
		Bureaucrat b1("b1", 0);
		std::cout << b1;
		Bureaucrat b2(b1);
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("b3", 151);
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat b4("b4", 1);
	Bureaucrat b5("b5", 15);
	Bureaucrat b6("b6", 10);

	PresidentialPardonForm f1("Very Nice");
	PresidentialPardonForm f2("lelz");
	ShrubberyCreationForm f3("cpp05");

	b5.signAForm(f2);
	b6.signAForm(f3);
	b4.signAForm(f2);

	try
	{
		b5.executeForm(f3);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}

	try
	{
		b5.executeForm(f3);
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
}