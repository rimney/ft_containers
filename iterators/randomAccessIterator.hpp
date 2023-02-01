/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:02:44 by rimney            #+#    #+#             */
/*   Updated: 2023/02/01 19:19:26 by rimney           ###   ########.fr       */
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
    class randomAccessIterator : ft::Iterator<T>
    {

        public :
            typedef typename ft::Iterator<T>::Category iterator_category;
            typedef typename ft::Iterator<T>::value_type value_type;
            typedef typename ft::Iterator<T>::difference_type difference_type;
            typedef typename ft::Iterator<T>::pointer pointer;
            typedef typename ft::Iterator<T>::reference reference;
            randomAccessIterator() : _pointer(NULL){}
            randomAccessIterator(const pointer ptr) : _pointer(ptr) {}
            operator randomAccessIterator<T> () {
            return randomAccessIterator< T>(_pointer);
            }
            randomAccessIterator  Iterator(randomAccessIterator & R) const
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
            reference operator*() const
            {
                return (*_pointer);
            }
            pointer operator->() const
            {
                return (this->_pointer);
            }
            difference_type operator-(randomAccessIterator const & diff) const
            {

                return (this->_pointer - diff);
            }
            difference_type  operator+(randomAccessIterator const & diff) const 
            {
                return (this->_pointer + diff);
            }

            randomAccessIterator operator-(difference_type diff) const
            {
                randomAccessIterator it = *this;
                it._pointer -= diff;
                return (it);
            }
            randomAccessIterator operator+(difference_type diff) const 
            {
                randomAccessIterator it = *this;
                it._pointer += diff;
                return (it);
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
                return (_pointer[index]);
            }
            bool operator>(const randomAccessIterator & r) const
            {
                return (this->_pointer > r._pointer);
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
                return(--this->_pointer);
                
            }
            randomAccessIterator operator+(difference_type diff)
            {
                return randomAccessIterator(diff + this->_pointer);
            }
            randomAccessIterator operator-(randomAccessIterator diff)
            {
                return randomAccessIterator(diff - this->_pointer);
            }
            template <class df>
            randomAccessIterator<df> operator+(difference_type diff)           
            {
                return (this->_pointer + diff);
            }
            template <class fd>
            randomAccessIterator<fd> operator-(difference_type diff)           
            {
                return this->_pointer - diff;
            }
            template <class re>
            bool operator==(const re *temp)
            {
                return (this->pointer == temp->pointer);
            }
            bool operator!=(const T *temp)
            {
                return (this->_pointer != temp->_pointer);
            }
        private :
            T *_pointer;
        };
    }

    #endif