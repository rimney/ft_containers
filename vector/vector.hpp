/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:37:08 by rimney            #+#    #+#             */
/*   Updated: 2023/01/10 20:51:00 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <vector>
#include <vector>
#include <iostream>
#include <memory>

namespace ft
{
    template<class T, class Alloc = std::allocator<T> >
    class vector
    {
        public :
            typedef T value_type;
            typedef  Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef size_t size_type;
            typedef typename std::vector<T>::iterator iterator;
            explicit vector (const allocator_type& alloc = allocator_type())
            {
                std::cout << "Vector Default Constructor Called\n";
                V = NULL;
                this->size = 0;
                this->capacity = 0;
            }
            vector(size_type n)
            {
                std::cout << "Vector Paramitarized Constructor Called\n";
                V = alloc.allocate(n);
                for(int i = 0; i < n; i++)
                    V[i] = n;
                this->size = n;
                this->capacity = n;
            }
            
            ~vector()
            {
                for(int i = 0; i < this->size; i++)
                    std::cout << V[i] << '\n';
                std::cout << "Vector Distructor Called\n";
            }
            // vector & operator=(vector & const V);
            void assign(size_type count, const T& value );
            allocator_type get_allocator();
            reference at( size_type pos );
            reference back();
            T* data();
            iterator begin();
            // const_iterator begin() const;
            iterator end();
            // const_iterator end() const;
            // reverse_iterator rbegin();
            // const_reverse_iterator rbegin() const;
            // reverse_iterator rend();
            // const_reverse_iterator rend() const;
            // bool empty() const;
            // size_type size() const;
            // size_type max_size() const;
            // void reserve(size_type new_cap);
            // size_type capacity() const;
            // void clear();
            // iterator insert( const_iterator pos, const T& value );
            // iterator erase( iterator pos );
            // void push_back( const T& value );
            // void pop_back();
            // void resize( size_type count );
            // void resize( size_type count, T value = T() );
            // void swap( vector & other );
            // void swap(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2); // std::swap
            // bool   operator>=(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator==(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator<=(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator!=(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator>(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator<(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            
        private :
            pointer V;
            size_type size;
            size_type capacity;
            allocator_type alloc;
    };
  
};

#endif