/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:02:44 by rimney            #+#    #+#             */
/*   Updated: 2023/02/16 04:34:28 by rimney           ###   ########.fr       */
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
            operator randomAccessIterator<const T>   () 
            {
                return randomAccessIterator<const T> (_pointer);
            }
            randomAccessIterator  Iterator(randomAccessIterator & R) const
            {
                this->_pointer = R._pointer;
            }
            ~randomAccessIterator() {}
            pointer base() const
            {
                return (this->_pointer);
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
        randomAccessIterator operator+(difference_type const & n) const {
            return randomAccessIterator(this->_pointer + n);
        }
        randomAccessIterator operator-(difference_type const & n)  const {
            return randomAccessIterator(this->_pointer - n);
        }

        difference_type  operator-(const randomAccessIterator &other) const {
            return this->_pointer - other._pointer;
        }
        difference_type  operator+(const randomAccessIterator &other) const {
            return this->_pointer + other._pointer;
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
            randomAccessIterator operator++()
            {
                this->_pointer += 1;
                return *this;
            }
            randomAccessIterator operator++(int)
            {
                pointer tmp = this->_pointer;
                this->_pointer++;
                return(tmp) ;
            }
            randomAccessIterator operator--()
            {
                this->_pointer -= 1;
                return (*this);
            }
            randomAccessIterator operator--(int)
            {
                pointer temp = this->_pointer;
                this->_pointer -= 1;
                return (temp);
                
            }

            difference_type operator-(randomAccessIterator  & diff) const      
            {
                difference_type i = std::distance(diff._pointer, this->_pointer);
                return i;
            }
                    bool operator>(const randomAccessIterator &other) const {
            return _pointer > other._pointer;
        }
        bool operator<(const randomAccessIterator &other) const {
            return _pointer < other._pointer;
        }
        bool operator>=(const randomAccessIterator &other) const {
            return _pointer >= other._pointer;
        }
        bool operator<=(const randomAccessIterator &other) const {
            return _pointer < other._pointer || _pointer == other._pointer;
        }
                bool operator==(const randomAccessIterator &other) const {
            return _pointer == other._pointer;
        }
        private :
            T *_pointer;
        };
	    template<typename T>
    randomAccessIterator<T> operator+(
        typename ft::randomAccessIterator<T>::difference_type n,
        typename ft::randomAccessIterator<T>& rai)
        {
            return (&(*rai) + n);
        }
        template<class T>
        randomAccessIterator<T> operator-(typename randomAccessIterator<T>::difference_type n, randomAccessIterator<T> const &other) {
            return n -  &(*other);
        }
        
        
        template<class T1, class T2>
	    bool	operator==(randomAccessIterator<T1> const& it1, randomAccessIterator<T2> const& it2)
	    {
		    return (it1.base() == it2.base());
	    }
        template<typename T1, typename T2>
	    bool	operator!=(randomAccessIterator<T1> const& it1, randomAccessIterator<T2> const& it2)
	    {
		    return (it1.base() != it2.base());
	    }
        template<typename T1, typename T2>
	    bool	operator<(randomAccessIterator<T1> const& it1, randomAccessIterator<T2> const& it2)
	    {
		    return (it1.base() < it2.base());
	    }
        template<typename T1, typename T2>
	    bool	operator>(randomAccessIterator<T1> const& it1, randomAccessIterator<T2> const& it2)
	    {
		    return (it1.base() > it2.base());
	    }
        template<typename T1, typename T2>
	    bool	operator>=(randomAccessIterator<T1> const& it1, randomAccessIterator<T2> const& it2)
	    {
		    return ((it1 > it2) || (it1 == it2));
	    }
        template<typename T1, typename T2>
	    bool	operator<=(randomAccessIterator<T1> const& it1, randomAccessIterator<T2> const& it2)
	    {
		    return (!(it1 > it2));
	    }
        
    };
    #endif