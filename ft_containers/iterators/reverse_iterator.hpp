/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:08:55 by rimney            #+#    #+#             */
/*   Updated: 2023/01/16 17:19:08 by rimney           ###   ########.fr       */
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
    class reverseIterator : ft::Iterator<typename ft::IteratorTraits<T>::iterator_category, typename ft::IteratorTraits<T>::value_type>
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
            template <class V>
            reverseIterator(const reverseIterator<V> & r)
            {
                this->i = r.i;
            }
            T base() const
            {
                return (this->i);
            }
            reference  & operator*() const
            {
                T tmp = this->i;
                --tmp;
                return (*tmp);
            }
            pointer operator->() const
            {
                return (this->i);
            }
            reverseIterator operator+(difference_type n)
            {
                return (reverseIterator(this->i - n));
            }
            reverseIterator operator-(difference_type n)
            {
                return (reverseIterator(this->i + n));
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
            reverseIterator & operator[](difference_type n)
            {
                return (this->i[i + n - 1]);
            }
            
   };
        template <class T>
        bool operator<(const reverseIterator<T>& a, const reverseIterator<T> & b)
        {
            return (a.base() > b.base());
        }
        template <class T>
        bool operator>(const reverseIterator<T>& a, const reverseIterator<T> & b)
        {
            return (a.base() < b.base());
        }
        template <class T>
        bool operator<=(const reverseIterator<T>& a, const reverseIterator<T> & b)
        {
            return (a.base() >= b.base());
        }
        template <class T>
        bool operator>=(const reverseIterator<T>& a, const reverseIterator<T> & b)
        {
            return (a.base() <= b.base());
        }
        template <class T>
        bool operator==(const reverseIterator<T>& a, const reverseIterator<T> & b)
        {
            return (a.base() == b.base());
        }
        template <class T>
        bool operator!=(const reverseIterator<T>& a, const reverseIterator<T> & b)
        {
            return (a.base() != b.base());
        }
        
}

#endif