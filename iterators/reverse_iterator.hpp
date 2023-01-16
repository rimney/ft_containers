/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:08:55 by rimney            #+#    #+#             */
/*   Updated: 2023/01/16 13:44:17 by rimney           ###   ########.fr       */
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
    class reverseIterator : ft::iterator<typename IteratorTraits<T>::iterator_category, typename ft::IteratorTraits<T>::value_type>
    {
        public :
            typedef typename ft::IteratorTraits<T>::difference_type difference_type;
            typedef typename ft::IteratorTraits<T>::value_type value_type;
            typedef typename ft::IteratorTraits<T>::iterator_category iterator_category;
            typedef typename ft::IteratorTraits<T>::pointer pointer;
            typedef typename ft::IteratorTraits<T>::reference reference;
        private :
            pointer *p;
        public :
            reverseIterator() : p(NULL) {}
            reverseIterator(pointer const p) : p(p) {}
            reverseIterator(reverseIterator const r)
            {
                *this = r;
            }
            reverseIterator & operator=(reverseIterator & r)
            {
                this->p = r.p;
                return (*this);
            }
            
    };
}

#endif