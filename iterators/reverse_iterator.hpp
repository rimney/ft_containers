/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:08:55 by rimney            #+#    #+#             */
/*   Updated: 2023/02/16 04:32:57 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERETOR_HPP
#define REVERSEITERETOR_HPP
#include <iterator>
#include "iterators.hpp"
#include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class reverseIterator : ft::Iterator<typename T::value_type>
    {
       public :
            typedef typename ft::IteratorTraits<T>::difference_type difference_type;
            typedef typename ft::IteratorTraits<T>::value_type value_type;
            typedef typename ft::IteratorTraits<T>::iterator_category iterator_category;
            typedef typename ft::IteratorTraits<T>::pointer pointer;
            typedef typename ft::IteratorTraits<T>::reference reference;
        private :
            T i;
            public : 
    reverseIterator() : i(nullptr) {}
            explicit reverseIterator(T p) : i(p) {}
            operator reverseIterator<const T>   () 
            {
                return reverseIterator<const T> (i);
            }
	template <class Iter>
		reverseIterator(const reverseIterator<Iter> &other): i(other.base()) {};
            T base() const
            {
                return (this->i);
            }
            reference  & operator*() const
            {
                T tmp = this->i;
                tmp -= 1;
                return (*tmp);
            }
            pointer operator->() const
            {
               return &(operator*());
            }
            reverseIterator operator-(difference_type n) const {
                return reverseIterator(i + n);
            }          
            reverseIterator operator+(difference_type n) const {
                return reverseIterator(i - n);
            }

            reverseIterator & operator++()
            {
                this->i -= 1;
                return (*this);
            }
            reverseIterator & operator--()
            {
                this->i += 1;
                return (*this);
            }
            reverseIterator operator++(int)
            {
                reverseIterator temp = *this;
                this->i -= 1;
                return (temp);
            }
            reverseIterator operator--(int)
            {
                reverseIterator temp = *this;
                this->i += 1;
                return (temp);
            }
            reverseIterator & operator+=(difference_type n)
            {
                this->i -= n;
                return (*this);
            }
            reverseIterator & operator-=(difference_type n)
            {
                this->i += n;
                return (*this);
            }
            reference & operator[](difference_type n) const
            {
                return *(*this + n);
            }
            
   };
	template<typename Iterator1, typename Iterator2>
	bool	operator==(reverseIterator<Iterator1> const& it1, reverseIterator<Iterator2> const& it2)
	{
		return (it1.base() == it2.base());
	}

	template<typename Iterator1, typename Iterator2>
	bool	operator!=(reverseIterator<Iterator1> const& it1, reverseIterator<Iterator2> const& it2)
	{
		return (!(it1.base() == it2.base()));
	}

	template<typename Iterator1, typename Iterator2>
	bool	operator<(reverseIterator<Iterator1> const& it1, reverseIterator<Iterator2> const& it2)
	{
		return (it2.base() < it1.base());
	}

	template<typename Iterator1, typename Iterator2>
	bool	operator<=(reverseIterator<Iterator1> const& it1, reverseIterator<Iterator2> const& it2)
	{
		return (!(it2 < it1));
	}

	template<typename Iterator1, typename Iterator2>
	bool	operator>(reverseIterator<Iterator1> const& it1, reverseIterator<Iterator2> const& it2)
	{
		return (it2 < it1);
	}

	template<typename Iterator1, typename Iterator2>
	bool	operator>=(reverseIterator<Iterator1> const& it1, reverseIterator<Iterator2> const& it2)
	{
		return (!(it1 < it2));
	}

        template <class Iter>
        typename reverseIterator<Iter>::difference_type
        operator-(const reverseIterator<Iter>& x, const reverseIterator<Iter>& y) {
            return y.base() - x.base();
        }
        template <class Iterator>
        reverseIterator<Iterator> operator+(typename reverseIterator<Iterator>::difference_type n,
            const reverseIterator<Iterator>& iter
            )
    {   
        return (iter + n);
    }

}	

#endif