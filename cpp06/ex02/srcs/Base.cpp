/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:57:23 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 17:57:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(){}

Base * generate(void)
{
    int i = rand() % 3;
    if (i == 0)
        return (new A);
    else if (i == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
            std::cout <<"type: A" << std::endl;
            return;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout <<"type: B" << std::endl;
        return;
    }
    else if(dynamic_cast<C*>(p))
    {
        std::cout <<"type: C" << std::endl;
        return;
    }
    else
        std::cout << "Error: no type defined" << std::endl;
}

void identify(Base& p)
{
    Base& bp = dynamic_cast<Base&>(p);
    try
    {
        dynamic_cast <A&> (bp);
        std::cout <<"type: A" << std::endl;
        return;
    }
    catch (...)
    {}
    try
    {
        dynamic_cast <B&> (bp);
        std::cout <<"type: B" << std::endl;
        return;
    }
    catch (...)
    {}
    try
    {
        dynamic_cast <C&> (bp);
        std::cout <<"type: C" << std::endl;
        return;
    }
    catch (...)
    {
        std::cout << "Error: no type defined" << std::endl;
    }
}