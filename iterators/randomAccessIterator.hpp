/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:02:44 by rimney            #+#    #+#             */
/*   Updated: 2023/01/15 00:33:06 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOMACCESSITERTOR_HPP
# define RANDOMACCESSITERTOR_HPP
#include "iterators.hpp"
#include "iterator_traits.hpp"
#include <iterator>
#include <iostream>

namespace ft
{
    template <class T>
    class randomAccessIterator : ft::iterator<std::random_access_iterator_tag, T>
    {
        private :
            T *_pointer;
        public :
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::Category iterator_category;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type value_type;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type difference_type;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::Pointer pointer;
            typedef typename ft::iterator<std::random_access_iterator_tag, T>::Reference reference;
            randomAccessIterator() : _pointer(NULL){}
            randomAccessIterator(const pointer ptr) : _pointer(ptr) {}
            operator randomAccessIterator<const T> () const{
            return randomAccessIterator<const T>(_pointer);
            }
            randomAccessIterator(randomAccessIterator & R)
            {
                this->_pointer = R._pointer;
            }
            ~randomAccessIterator() {}
            bool operator==(const randomAccessIterator & r) const
            {
                return (this->_pointer == r._pointer);
            }
            bool operator!=(const randomAccessIterator & r) const
            {
                return (this->_pointer != r._pointer);    
            }
            pointer operator*() const
            {
                return (_pointer);
            }
            pointer operator->() const
            {
                return (this->_pointer);
            }
            difference_type operator-(difference_type diff) const
            {
                return (this->_pointer - diff);
            }
            difference_type operator+(difference_type diff) const
            {
                return (this->_pointer - diff);
            }
            
            randomAccessIterator operator+=(difference_type diff)
            {
                this->_pointer += diff;
                return *this;
            }
            randomAccessIterator operator-=(difference_type diff)
            {
                this->_pointer -= diff;
                return *this;
            }
            reference operator[](difference_type index) const
            {
                return (this->_pointer[index]);
            }
            bool operator>(const randomAccessIterator & r) const
            {
                return (this->_pointer > r.pointer);
            }
            bool operator>=(const randomAccessIterator & r) const
            {
                return (this->_pointer >= r._pointer);
            }
            bool operator<(const randomAccessIterator & r) const
            {
                return (this->_pointer < r._pointer);
            }
            bool operator<=(const randomAccessIterator & r) const
            {
                return (this->_pointer <= r._pointer);
            }
            randomAccessIterator operator++()
            {
                this->_pointer += 1;
                return *this;
            }
            randomAccessIterator operator++(int)
            {
                ++this->_pointer;
                return(*this);
            }
            randomAccessIterator operator--()
            {
                this->_pointer -= 1;
                return (*this);
            }
            randomAccessIterator operator--(int)
            {
                --this->_pointer;
                return (*this);
            }
            randomAccessIterator operator+(difference_type diff)
            {
                return randomAccessIterator(diff + this->_pointer);
            }
            randomAccessIterator operator-(difference_type diff)
            {
                return randomAccessIterator(diff - this->_pointer);
            }
            // // template <class T>
            // randomAccessIterator<T> operator+(difference_type diff)           
            // {
            //     return (pointer + diff);
            // }
            // // template <class T>
            // randomAccessIterator<T> operator-(difference_type diff)           
            // {
            //     return (pointer - diff);
            // }
            // // template <class T>
            // bool operator==(const T *temp)
            // {
            //     return (this->pointer == temp->pointer);
            // }
            // bool operator!=(const T *temp)
            // {
            //     return (this->pointer != temp->pointer);
            // }
        };
    }

    #endif