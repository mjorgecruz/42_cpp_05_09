
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main ( void )
{
	try
	{
		Bureaucrat b1("b1", 0);
		std::cout << b1;
		Bureaucrat b2(b1);
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b3("b3", 151);
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cout << e.what() << std::endl;
	}

	Bureaucrat b4("b4", 1);
	Bureaucrat b5("b5", 15);
	Bureaucrat b6("b6", 10);

	try
	{
		PresidentialPardonForm f1;
	}
	catch (AForm::UnnamedAFormException &e){
		std::cout << e.what() << std::endl;
	}

	Intern i1;
	Intern i2;

	AForm *f2 = i1.makeForm("PresidentialPardonForm", "lelz");
	AForm *f3 = i1.makeForm("ShrubberyCreationForm", "lelz");


	b5.signAForm(*f2);
	b6.signAForm(*f3);
	b4.signAForm(*f2);

	b5.executeForm(*f3);

}