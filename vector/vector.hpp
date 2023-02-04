/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:37:08 by rimney            #+#    #+#             */
/*   Updated: 2023/02/04 23:28:03 by rimney           ###   ########.fr       */
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
#include "enable_if.hpp"
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
                V = NULL;
                this->_size = 0;
                this->_capacity = 0;
                this->alloc = alloc;
            }
            explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
            {
                this->alloc = alloc;
                V = this->alloc.allocate(n);
                for(size_type i = 0; i < n; i++)
                {
                    this->alloc.construct(&V[i], val);
                }
                this->_size = n;
                this->_capacity = n;
            }
            template <class inputIterator>
            vector (inputIterator first, inputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<inputIterator>::value,inputIterator>::type* = 0)
            {
                this->alloc = alloc;
                this->_size = last - first;
                this->_capacity = last - first;
                this->V = this->alloc.allocate(last - first);
                for(int i = 0; first < last; first++)
                {
                    this->alloc.construct(V + i, *first);
                    i++;
                }
            }
            vector(vector const &vec)
            {
                *this = vec;
            }
            vector & operator=(vector const  & vec)
            {
                this->alloc = vec.alloc;
                this->_size = vec._size;
                this->_capacity = vec._capacity;
                V = this->alloc.allocate(this->_size);
                for(size_t i = 0; (size_t)i < this->_size;i++)
                    this->alloc.construct(&this->V[i], vec.V[i]);
                return (*this);
            }
            ~vector()
            {
                    clear();
                    if (this->V)
                        this->alloc.deallocate(this->V, _capacity);
            }
            void assign(size_type n, const T& value )
            {
                for (size_type i = 0; i < this->_size; i++)
                    this->alloc.destroy(this->V + i);
                if(this->_size > 0 || this->V)
                    this->alloc.deallocate(this->V, _capacity);
                this->_size = n;
                this->_capacity = _size;
                this->V = this->alloc.allocate(_size);
                for (size_type i = 0; i < _size; i++)
                    this->alloc.construct(this->V + i, value);
                
            }
            allocator_type get_allocator() const
            {
                return (this->alloc);
            }
            reference at( size_type pos )
            {
                if(pos >= this->_size)
                    throw std::out_of_range("out of range a zbi");
                return (V[pos]);
            }
            const_reference at(size_type const pos) const
            {
                if(pos >= this->_size)
                    throw std::out_of_range("out of range a zbi");
                return (V[pos]);
            }
            reference &  operator[](size_type index)
            {
                return (this->V[index]);
            }
            const_reference & operator[](size_type index) const
            {
                return (this->V[index]);
            }
            reference front()
            {
                return (this->V[0]);
            }
            const_reference front() const
            {
                return (this->V[0]);
            }
            reference back()
            {
                return (this->V[_size - 1]);
            }
            const_reference back() const
            {
                return (this->V[_size - 1]);
            }
            T* data()
            {
                return (this->V);
            }
            iterator begin() const
            {
                return (iterator(V));
            }
            const_iterator cbegin() const
            {
                return (const_iterator(V));
            }
            iterator end() const
            {
                return (iterator(V + _size));
            }
            const_iterator cend() const
            {
                return (const_iterator(V + _size - 1));
            }
            reverse_iterator rbegin()
            {
                return (reverse_iterator(this->V + _size));
            }
            const_reverse_iterator crbegin() const
            {
                return (const_reverse_iterator(this->V + _size));
            }
            reverse_iterator rend()
            {
                return (reverse_iterator(V));
            }
            const_reverse_iterator crend() const
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
            size_type max_size() const
            {
                return (this->alloc.max_size());
            }
		void reserve(size_type n) {
			if (n > max_size()) 
            {
				throw (std::length_error("ft::vector::reserve"));
			}
            else if (n >= _capacity)
            {
				pointer new_ptr = alloc.allocate(n);
				for (size_type i = 0; i < _size; i++)
                {
				    alloc.construct(new_ptr + i, V[i]);
                    if(V + i)
                        alloc.destroy(V + i);
                }
                if(this->V)
                    alloc.deallocate(V, _capacity);
				this->V = new_ptr;
				_capacity = n;
			}
		}
            size_type capacity() const
            {
                return (this->_capacity);
            }
            void clear()
            {
                if(!this->V)
                    return ;
                for(size_type i = 0; i < this->_size; i++)
                    this->alloc.destroy(V + i);
                this->_size = 0;
            }
            iterator insert( const_iterator pos, const T& value )
            {
                return (iterator(value) + pos);
            }
            iterator erase( iterator const pos )
            {
                iterator it = pos;
                while(it + 1 != this->end()){
                    *(it) = *(it + 1);
                    it++;
                }
                this->alloc.destroy(V + (_size - 1));
                _size -= 1;
                return (pos);
            }

		    void push_back(const value_type & value)
            {
			    if (this->_size == this->_capacity)
                {
                    if(_size == 0)
                        reserve(1);
                    else
				        reserve(_size * 2);
                }
			    this->alloc.construct(this->V + this->_size, value);
			    this->_size += 1;
		    }
            
            void pop_back()
            {
                if(_size > 0)
                {
                    this->_size -= 1;
                    this->alloc.destroy(V + _size);
                }
            }
			void resize (size_type n, value_type val = value_type())
			{
				if (n == this->_size)
					return ;
				if (n < this->_size)
					for (size_type i = n; i < this->_size; i++)
                    {
                        if(V + i)
						    this->alloc.destroy(V + i);
                    }
				else
				{
					reserve(n);
					for (size_type i = this->_size; i < n; i++)
						this->alloc.construct(&this->V[i], val);
				}
				this->_size = n;
			}
            
            void swap( vector & other )
            {
                vector temp;
                temp = *this;
                *this = other;
                other = temp;
            }
            
            
            // bool   operator>=(ft::vectorr<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator==(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator<=(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator!=(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator>(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            // bool   operator<(ft::vector<T, Alloc> & V, ft::vector<T, Alloc> & V2);
            
        
    };
  
};

#endif