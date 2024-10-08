/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/10/08 15:11:51 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MutantStack.hpp"

template < typename T > MutantStack<T>::MutantStack(){}

template < typename T > MutantStack<T>::~MutantStack()
{} 

template < typename T > MutantStack<T>::MutantStack(MutantStack<T> &src) : std::stack<T>(src)
{
    
}

template < typename T > MutantStack<T> & MutantStack<T>::operator= (MutantStack<T> &src)
{
    (void) src;
    return *this;
}

template < typename T >  typename MutantStack<T>::Iterator MutantStack<T>::begin()
{
    Iterator result = Iterator(*this, 0);
    return result;
}

template < typename T >  typename MutantStack<T>::Iterator MutantStack<T>::end()
{
    Iterator result = Iterator(*this);
    return result;

}

template < typename T >  typename MutantStack<T>::ConstIterator MutantStack<T>::begin() const
{
    ConstIterator result = ConstIterator(*this, 0);
    return result;
}

template < typename T >  typename MutantStack<T>::ConstIterator MutantStack<T>::end() const
{
    ConstIterator result = ConstIterator(*this);
    return result;

}

template < typename T >  typename MutantStack<T>::RIterator MutantStack<T>::rbegin()
{
    ConstIterator result = Iterator(*this, this->size() - 1);
    return result;
}

template < typename T >  typename MutantStack<T>::RIterator MutantStack<T>::rend()
{
    ConstIterator result = Iterator(*this);
    return result;

}

template < typename T >  typename MutantStack<T>::ConstRIterator MutantStack<T>::rbegin() const
{
    ConstIterator result = ConstIterator(*this, this->size() - 1);
    return result;
}

template < typename T >  typename MutantStack<T>::ConstRIterator MutantStack<T>::rend() const
{
    ConstIterator result = ConstIterator(*this);
    return result;

}

template < typename T > T&  MutantStack<T>::at(unsigned int index)
{
    if (index >= this->size())
        throw std::out_of_range("Invalid Index");
    return this->c.at(index);
}

//Iterator

template <typename T> MutantStack<T>::Iterator::Iterator(const Iterator& src)
    : stack(src.stack), index(src.index) {}

template < typename T > MutantStack<T>::Iterator::Iterator(MutantStack& stack, unsigned int initial_index ):
stack(stack), index(initial_index), is_valid(true)
{
    if (initial_index >= stack.size())
        is_valid = false;
}
template < typename T > typename MutantStack<T>::Iterator& MutantStack<T>::Iterator::operator=(Iterator &src)
{
    index = src.index;
    is_valid = src.is_valid;
    stack = src.stack;
    return(*this);
}

template < typename T > MutantStack<T>::Iterator::Iterator(MutantStack& stack):
stack(stack), index(0), is_valid(false)
{}

template < typename T > MutantStack<T>::Iterator::~Iterator()
{}

template < typename T > T& MutantStack<T>::Iterator::operator*()
{
    if (!this->is_valid)
        throw std::out_of_range("Dereferencing Invalid Iterator");
    return stack.at(index);
}

template < typename T >  typename MutantStack<T>::Iterator& MutantStack<T>::Iterator::operator++()
{
    if (!this->is_valid)
        return *this;
    ++index;
    if (index >= stack.size())
        is_valid = false;
    return *this;
}

template < typename T >  typename MutantStack<T>::Iterator& MutantStack<T>::Iterator::operator--()
{
    if (!this->is_valid)
        return *this;
    --index;
    if (index >= stack.size())
        is_valid = false;
    return *this;
}

template < typename T >  typename MutantStack<T>::Iterator& MutantStack<T>::Iterator::operator++( int )
{
    if (!this->is_valid)
        return *this;
    MutantStack<T>::Iterator& temp = *this;
    ++index;
    if (index >= stack.size())
        is_valid = false;
    return temp;
}

template < typename T >  typename MutantStack<T>::Iterator& MutantStack<T>::Iterator::operator--( int )
{
    if (!this->is_valid)
        return *this;
    MutantStack<T>::Iterator& temp = *this;
    --index;
    if (index >= stack.size())
        is_valid = false;
    return temp;
}

template < typename T >  bool MutantStack<T>::Iterator::operator==(MutantStack<T>::Iterator const & src)
{
    if ((this->is_valid == true && src.is_valid == true && this->stack == src.stack && this->index == src.index ) || (src.is_valid == false && this->is_valid == false))
        return true;
    return false;
}

template < typename T >  bool MutantStack<T>::Iterator::operator!=(MutantStack<T>::Iterator const & src)
{
    return !(*this == src);
}

/* 
Writing an Iterator
https://www.youtube.com/watch?v=fCNR9a_Vmls

typedef typename std::stack<T>::container_type::iterator iterator;

#include <stack>
#include <deque>
#include <iostream>

template <typename T>
class MyStack : public std::stack<T> {
public:
    // Define an iterator alias using the underlying container's iterator
    typedef typename std::stack<T>::container_type::iterator iterator;

    // Return the iterator to the beginning of the stack
    iterator begin() { return this->c.begin(); }
    // Return the iterator to the end of the stack
    iterator end() { return this->c.end(); }
};

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

*/


//ConstIterator

template <typename T> MutantStack<T>::ConstIterator::ConstIterator(const ConstIterator& src)
    : stack(src.stack), index(src.index) {}

template < typename T > MutantStack<T>::ConstIterator::ConstIterator(const MutantStack& stack, unsigned int initial_index ):
stack(stack), index(initial_index), is_valid(true)
{
    if (initial_index >= stack.size())
        is_valid = false;
}

template < typename T > MutantStack<T>::ConstIterator::ConstIterator(const MutantStack& stack):
stack(stack), index(0), is_valid(false)
{}

template < typename T > MutantStack<T>::ConstIterator::~ConstIterator()
{}

template < typename T > typename MutantStack<T>::ConstIterator& MutantStack<T>::ConstIterator::operator=(ConstIterator &src)
{
    index = src.index;
    is_valid = src.is_valid;
    return(*this);
}

template < typename T > const T& MutantStack<T>::ConstIterator::operator*() const
{
    if (!this->is_valid)
        throw std::out_of_range("Dereferencing Invalid ConstIterator");
    return stack.at(index);
}

template < typename T >  typename MutantStack<T>::ConstIterator& MutantStack<T>::ConstIterator::operator++()
{
    if (!this->is_valid)
        return *this;
    ++index;
    if (index >= stack.size())
        is_valid = false;
    return *this;
}

template < typename T >  typename MutantStack<T>::ConstIterator& MutantStack<T>::ConstIterator::operator--() 
{
    if (!this->is_valid)
        return *this;
    --index;
    if (index >= stack.size())
        is_valid = false;
    return *this;
}

template < typename T >  typename MutantStack<T>::ConstIterator& MutantStack<T>::ConstIterator::operator++( int )
{
    if (!this->is_valid)
        return *this;
    MutantStack<T>::ConstIterator& temp = *this;
    ++index;
    if (index >= stack.size())
        is_valid = false;
    return temp;
}

template < typename T >  typename MutantStack<T>::ConstIterator& MutantStack<T>::ConstIterator::operator--( int )
{
    if (!this->is_valid)
        return *this;
    MutantStack<T>::ConstIterator& temp = *this;
    --index;
    if (index >= stack.size())
        is_valid = false;
    return temp;
}

template < typename T >  bool MutantStack<T>::ConstIterator::operator==(MutantStack<T>::ConstIterator const & src) const
{
    if ((this->is_valid == true && src.is_valid == true && this->stack == src.stack && this->index == src.index ) || (src.is_valid == false && this->is_valid == false))
        return true;
    return false;
}

template < typename T >  bool MutantStack<T>::ConstIterator::operator!=(const MutantStack<T>::ConstIterator & src) const
{
    return !(*this == src);
}

/*In C++, member functions can be marked as const by appending the const keyword at the end of the function signature.
 This indicates that the function does not modify the internal state of the object and can be called on const instances of the class.
 
 The const at the end of a member function declaration applies to the implicit this pointer, making this a pointer to a constant
instance of the class. Therefore, in a const member function:

    You cannot modify member variables.
    You cannot call non-const member functions on this.
    You can only call other const member functions of the class.

Why Some Functions Should Be const Member Functions
The operator==, operator!=, and operator* functions should be const member functions because they only read the internal state
of the iterator without modifying it. These functions are inherently read-only and should therefore be marked const to enforce 
const-correctness.

Why Increment and Decrement Operators Are Usually Not const
The increment (++) and decrement (--) operators, on the other hand, modify the internal state of the iterator, typically by
changing the index or pointer to the current position in the container. Since these functions alter the state of the iterator,
they cannot be const member functions.
 
 */

//RIterator

template <typename T> MutantStack<T>::RIterator::RIterator(const RIterator& src)
    : stack(src.stack), index(src.index) {}

template < typename T > MutantStack<T>::RIterator::RIterator(MutantStack& stack, unsigned int initial_index ):
stack(stack), index(initial_index), is_valid(true)
{
    if (initial_index >= stack.size())
        is_valid = false;
}
template < typename T > typename MutantStack<T>::RIterator& MutantStack<T>::RIterator::operator=(RIterator &src)
{
    index = src.index;
    is_valid = src.is_valid;
    stack = src.stack;
    return(*this);
}

template < typename T > MutantStack<T>::RIterator::RIterator(MutantStack& stack):
stack(stack), index(stack.size() - 1), is_valid(false)
{}

template < typename T > MutantStack<T>::RIterator::~RIterator()
{}

template < typename T > T& MutantStack<T>::RIterator::operator*()
{
    if (!this->is_valid)
        throw std::out_of_range("Dereferencing Invalid RIterator");
    return stack.at(index);
}

template < typename T >  typename MutantStack<T>::RIterator& MutantStack<T>::RIterator::operator++()
{
    if (!this->is_valid)
        return *this;
    --index;
    if (index >= stack.size())
        is_valid = false;
    return *this;
}

template < typename T >  typename MutantStack<T>::RIterator& MutantStack<T>::RIterator::operator--()
{
    if (!this->is_valid)
        return *this;
    ++index;
    if (index >= stack.size())
        is_valid = false;
    return *this;
}

template < typename T >  typename MutantStack<T>::RIterator& MutantStack<T>::RIterator::operator++( int )
{
    if (!this->is_valid)
        return *this;
    MutantStack<T>::RIterator& temp = *this;
    --index;
    if (index >= stack.size())
        is_valid = false;
    return temp;
}

template < typename T >  typename MutantStack<T>::RIterator& MutantStack<T>::RIterator::operator--( int )
{
    if (!this->is_valid)
        return *this;
    MutantStack<T>::RIterator& temp = *this;
    ++index;
    if (index >= stack.size())
        is_valid = false;
    return temp;
}

template < typename T >  bool MutantStack<T>::RIterator::operator==(MutantStack<T>::RIterator const & src)
{
    if ((this->is_valid == true && src.is_valid == true && this->stack == src.stack && this->index == src.index ) || (src.is_valid == false && this->is_valid == false))
        return true;
    return false;
}

template < typename T >  bool MutantStack<T>::RIterator::operator!=(MutantStack<T>::RIterator const & src)
{
    return !(*this == src);
}


//ConstRIterator

template <typename T> MutantStack<T>::ConstRIterator::ConstRIterator(const ConstRIterator& src)
    : stack(src.stack), index(src.index) {}

template < typename T > MutantStack<T>::ConstRIterator::ConstRIterator(const MutantStack& stack, unsigned int initial_index ):
stack(stack), index(initial_index), is_valid(true)
{
    if (initial_index >= stack.size())
        is_valid = false;
}

template < typename T > MutantStack<T>::ConstRIterator::ConstRIterator(const MutantStack& stack):
stack(stack), index(0), is_valid(false)
{}

template < typename T > MutantStack<T>::ConstRIterator::~ConstRIterator()
{}

template < typename T > typename MutantStack<T>::ConstRIterator& MutantStack<T>::ConstRIterator::operator=(ConstRIterator &src)
{
    index = src.index;
    is_valid = src.is_valid;
    return(*this);
}

template < typename T > const T& MutantStack<T>::ConstRIterator::operator*() const
{
    if (!this->is_valid)
        throw std::out_of_range("Dereferencing Invalid ConstRIterator");
    return stack.at(index);
}

template < typename T >  typename MutantStack<T>::ConstRIterator& MutantStack<T>::ConstRIterator::operator++()
{
    if (!this->is_valid)
        return *this;
    --index;
    if (index >= stack.size())
        is_valid = false;
    return *this;
}

template < typename T >  typename MutantStack<T>::ConstRIterator& MutantStack<T>::ConstRIterator::operator--() 
{
    if (!this->is_valid)
        return *this;
    ++index;
    if (index >= stack.size())
        is_valid = false;
    return *this;
}

template < typename T >  typename MutantStack<T>::ConstRIterator& MutantStack<T>::ConstRIterator::operator++( int )
{
    if (!this->is_valid)
        return *this;
    MutantStack<T>::ConstRIterator& temp = *this;
    --index;
    if (index >= stack.size())
        is_valid = false;
    return temp;
}

template < typename T >  typename MutantStack<T>::ConstRIterator& MutantStack<T>::ConstRIterator::operator--( int )
{
    if (!this->is_valid)
        return *this;
    MutantStack<T>::ConstRIterator& temp = *this;
    ++index;
    if (index >= stack.size())
        is_valid = false;
    return temp;
}

template < typename T >  bool MutantStack<T>::ConstRIterator::operator==(MutantStack<T>::ConstRIterator const & src) const
{
    if ((this->is_valid == true && src.is_valid == true && this->stack == src.stack && this->index == src.index ) || (src.is_valid == false && this->is_valid == false))
        return true;
    return false;
}

template < typename T >  bool MutantStack<T>::ConstRIterator::operator!=(const MutantStack<T>::ConstRIterator & src) const
{
    return !(*this == src);
}
