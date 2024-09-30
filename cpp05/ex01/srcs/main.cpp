
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat b4("b4", 1);
	Bureaucrat b5("b5", 15);
	Bureaucrat b6("b6", 10);

	try
	{
		Form f1;
	}
	catch (Form::UnnamedFormException &e){
		std::cerr << e.what() << std::endl;
	}
	Form f2("f2", 10, 150);

	b5.signForm(f2);
	b6.signForm(f2);
	b4.signForm(f2);

}