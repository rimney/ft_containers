/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:37:08 by rimney            #+#    #+#             */
/*   Updated: 2023/01/17 22:01:00 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <vector>
#include <iostream>
#include <memory>
#include <iterator>
#include "../iterators/randomAccessIterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft
{
    template<class T, class Alloc = std::allocator<T> >
    class vector
    {
        public :
            typedef T value_type;
            typedef  Alloc  allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef size_t size_type;
            typedef randomAccessIterator<value_type> iterator;
            typedef randomAccessIterator<const value_type> const_iterator;
            typedef reverseIterator<iterator> reverse_iterator;
            typedef reverseIterator<const_iterator> const_reverse_iterator;
            typedef typename ft::IteratorTraits<iterator>::difference_type difference_type; 
            
            
        private :
            pointer V;
            size_type _size;
            size_type _capacity;
            allocator_type alloc;
        public:
            explicit vector (const allocator_type& alloc = allocator_type())
            {
                std::cout << "Vector Default Constructor Called\n";
                V = NULL;
                this->_size = 0;
                this->_capacity = 0;
                this->alloc = alloc;
            }
            explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())            {
                std::cout << "Vector Paramitarized Constructor Called\n";
                this->alloc = alloc;
                V = this->alloc.allocate(n);
                for(size_type i = 0; i < n; i++)
                {
                    
                    this->alloc.construct(&V[i], val + i);
                }
                this->_size = n;
                this->_capacity = n;
            }
            //
            template <class inputIterator>
            explicit vector (inputIterator first, inputIterator last, const allocator_type& alloc = allocator_type()) : alloc(alloc)
            {
                while(first != last)
                {
                    std::cout << *first << " <<<<\n";
                    push_back(*first);
                    first++;
                }
            }
            vector(vector const &vec)
            {
                *this = vec;
                std::cout << "Vector copy constructor Called\n";
            }
            vector & operator=(vector const  & vec)
            {
                this->alloc = vec.alloc;
                this->_size = vec._size;
                this->_capacity = vec.capacity;
                V = this->alloc.allocate(this->_size);
                for(size_t i = 0; (size_t)i < this->_size;i++)
                    this->alloc.construct(&this->V[i], vec.V[i]);
                std::cout << "Vector Copy Assignment Overload Called\n";
                return (*this);
            }
            ~vector()
            {
                std::cout << "Vector Distructor Called\n";
            }
            reference & operator[](size_type index)
            {
                // if(index > this->_size | (int)index < 0)
                //     return (0);
                return (this->V[index]);
            }
            const_reference & operator[](size_type index) const
            {
                return (this->V[index]);
            }
            // void assign(size_type count, const T& value );
            allocator_type get_allocator() const
            {
                return (this->alloc);
            }
            reference at( size_type pos )
            {
                if(pos >= this->_size)
                    throw("access error");
                return (V[pos]);
            }
            // reference back();
            // T* data();
             iterator begin()
             {
                return (iterator(V));
             }
            // const_iterator begin() const;
            iterator end()
            {
                return (iterator(V + _size - 1));
            }
            const_iterator end() const
            {
                return (const_iterator(V + _size - 1));
            }
            reverse_iterator rbegin()
            {
                return (reverse_iterator(this->V + _size));
            }
            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(this->V + _size));
            }
            reverse_iterator rend()
            {
                return (reverse_iterator(V));
            }
            const_reverse_iterator rend() const
            {
                return (const_reverse_iterator((V)));
            }
            bool empty() const
            {
                return (this->_size == 0 ? true : false);
            }
             size_type size() const
             {
                return (this->_size);
             }
            size_type max_size() const;
            // void reserve(size_type new_cap);
            size_type capacity() const
            {
                return (this->_capacity);
            }
            // void clear();
            iterator insert( const_iterator pos, const T& value )
            {
                return (iterator(value) + pos);
            }
            // iterator erase( iterator pos );
            void push_back( const T& value )
            {
                if(_size == 0)
                {
                    _size += 1;
                    this->V = alloc.allocate(_size);
                    alloc.construct(&V[0], value);
                    return ;
                }
                else if(_size == _capacity)
                {
                    this->_size += 1;
                    this->_capacity *= 2; 
                    pointer temp;
                    temp = this->V;
                    this->V = alloc.allocate(_capacity);
                    for(size_type i = 0; i < _size; i++)
                    {
                        alloc.construct(&V[i], temp[i]);
                        if(i + 1 == _size)
                        {
                            alloc.construct(&V[i], value);
                            for(size_type i = 0; i < _size - 1; i++)
                                alloc.destroy(temp + i);
                            alloc.deallocate(temp, _size - 1);
                            return ;
                        }
                    }
                    return ;
                }
                else
                {
                    this->_size += 1;
                    pointer temp;
                    temp = this->V;
                    this->V = alloc.allocate(_size);
                    for(size_type i = 0; i < _size; i++)
                    {
                        alloc.construct(&V[i], temp[i]);
                        if(i + 1 == _size)
                        {
                            alloc.construct(&V[i], value);
                            for(size_type i = 0; i < _size - 1; i++)
                                alloc.destroy(temp + i);
                            alloc.deallocate(temp, _size - 1);
                            return ;
                        }
                        
                    }
                    return ;
                }
            }
            // void pop_back();
            // void resize( size_type count );
            // void resize( size_type count, T value = T() );
            // void swap( vector & other );
            // void swap(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2); // std::swap
            // bool   operator>=(ft::vectorr<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator==(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator<=(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator!=(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator>(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator<(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            
        
    };
  
};

#endif