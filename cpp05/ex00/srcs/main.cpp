
#include "Bureaucrat.hpp"

int main ( void )
{
    try
    {
        Bureaucrat b2("b2", 0);
        std::cout << b2;
        Bureaucrat b5(b2);
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

    Bureaucrat b1("b1", 1);
    Bureaucrat b4("b4", 150);

    b1.decrement();
    std::cout << b1;

    b4.increment();
    std::cout << b4;

}