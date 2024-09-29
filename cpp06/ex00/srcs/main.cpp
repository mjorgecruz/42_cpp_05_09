
#include "ScalarConverter.hpp"

int main ( int ac, char **av )
{
	if (ac != 2)
		return ;
	(void) av;
	(void) ac;
	ScalarConverter::convert(av[1]);
}