/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:57:23 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 18:52:19 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
        p = dynamic_cast<A*>(p);
        std::cout <<"type: A" << std::endl;
        return;
    }
    else if (dynamic_cast<B*>(p))
    {
        p = dynamic_cast<B*>(p);
        std::cout <<"type: B" << std::endl;
        return;
    }
    else if(dynamic_cast<C*>(p) != 0 )
    {
        p = dynamic_cast<C*>(p);
        std::cout <<"type: C" << std::endl;
        return;
    }
    else
        std::cout << "Error: no type defined" << std::endl;
}

void identify(Base& p)
{
    try
    {
        dynamic_cast <A&> (p);
        std::cout <<"type: A" << std::endl;
        return;
    }
    catch (std::exception &e)
    {}
    try
    {
        dynamic_cast <B&> (p);
        std::cout <<"type: B" << std::endl;
        return;
    }
    catch (std::exception &e)
    {}
    try
    {
        dynamic_cast <C&> (p);
        std::cout <<"type: C" << std::endl;
        return;
    }
    catch (std::exception &e)
    {
        std::cout << "Error: no type defined" << std::endl;
    } 
}