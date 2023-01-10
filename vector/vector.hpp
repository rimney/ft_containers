/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:37:08 by rimney            #+#    #+#             */
/*   Updated: 2023/01/10 16:33:49 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <vector>

namespace ft
{
    template<class T, class Alloc = std::allocator<T>>
    class vector
    {
        private :
            ///
        public :
            vector();
            ~vector();
            vector & operator=(vector & const V);
            void assign(size_type count, const T& value );
            allocator_type get_allocator();
            reference at( size_type pos );
            reference back();
            T* data();
            iterator begin();
            const_iterator begin() const;
            iterator end();
            const_iterator end() const;
            reverse_iterator rbegin();
            const_reverse_iterator rbegin() const;
            reverse_iterator rend();
            const_reverse_iterator rend() const;
            bool empty() const;
            size_type size() const;
            size_type max_size() const;
            void reserve(size_type new_cap);
            size_type capacity() const;
            void clear();
            iterator insert( const_iterator pos, const T& value );
            iterator erase( iterator pos );
            void push_back( const T& value );
            void pop_back();
            void resize( size_type count );
            void resize( size_type count, T value = T() );
            void swap( vector & other );
            void swap(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2); // std::swap
            bool   operator>=(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            bool   operator==(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            bool   operator<=(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            bool   operator!=(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            bool   operator>(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            bool   operator<(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            
    };
  
    
};

#endif