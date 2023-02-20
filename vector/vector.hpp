/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:37:08 by rimney            #+#    #+#             */
/*   Updated: 2023/02/20 23:09:29 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <vector>
#include <iostream>
#include <typeinfo>
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
                vector temp;
                size_type count = 0;
            
                while(first != last)
                {
                    temp.push_back(*first);
                    count++;
                    first++;
                }
                this->alloc = alloc;
                this->_size = count;
                this->_capacity = count;
                this->V = this->alloc.allocate(count);
                for(size_type i = 0; i < count; i++)
                {
                    this->alloc.construct(V + i, temp[i]);
                }
            }
            vector(vector const &vec)
            {
                    this->alloc = vec.alloc;
                    this->_size = vec._size;
                    this->_capacity = vec._capacity;
                    V = this->alloc.allocate(this->_capacity);
                    for(size_t i = 0; (size_t)i < this->_size;i++)
                        this->alloc.construct(&this->V[i], vec.V[i]);
            }
            vector & operator=(vector const  & vec)
            {
                if(this->_size != 0)
                    clear();
                if(this->V)
                    alloc.deallocate(V, this->_capacity);
                this->alloc = vec.alloc;
                this->_size = vec._size;
                this->_capacity = vec._capacity;
                V = this->alloc.allocate(this->_capacity);
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
            template <class InputIterator> 
            void assign (InputIterator first, InputIterator last)
            {
                vector temp;
                size_type count = 0;
                while(first != last)
                {
                    temp.push_back(*first);
                    count++;
                    first++;
                }
                this->clear();
                if(this->_size > 0 || this->V)
                    this->alloc.deallocate(this->V, _capacity);
                this->_size = count;
                this->_capacity = _size;
                this->V = this->alloc.allocate(_size);
                for (size_type i = 0; i < _size; i++)
                    this->alloc.construct(this->V + i, temp[i]);
            }
            void assign(size_type n, const T& value )
            {
                clear();
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
            reverse_iterator rbegin() const
            {
                return (reverse_iterator(this->V + this->_size));
            }
            const_reverse_iterator crbegin() const
            {
                return (const_reverse_iterator(this->V + _size));
            }
            reverse_iterator rend() const
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
                const std::type_info& ti1 = typeid(this->V[0]);
                const char *str = ti1.name();
                if(strcmp(str, "h") == 0 || strcmp(str, "c") == 0)
                    return (this->alloc.max_size() / 2);
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
            iterator insert( iterator pos, const T& value )
            {
                size_type index = pos - begin();

                if(this->_size == 0 || pos == end())
                {
                    push_back(value);
                    return (end() - 1);
                }
                if(this->_capacity < this->_size + 1)
                {
                    reserve(this->_capacity * 2);
                    pos = this->begin() + index;
                }
                size_type i = this->_size;
                if(i != index)
                {
                   this->alloc.construct(this->V + _size, this->V[_size - 1]);
                   i -= 1;
                   while (i > index)
                   {
                        this->V[i] = this->V[i - 1];
                        i--;
                   }
                   this->V[i] = value;
                }
                this->_size += 1;
                return (pos);
                        
            }
            iterator    insert(iterator pos, size_type n, const_reference val)
            {

                if(this->_size + n > this->_capacity)
                {
                    size_type index = pos - begin();
                    if(this->_size * n > this->_capacity * 2)
                        reserve(this->_size + n);
                    else
                        reserve(this->_size * 2);
                    pos = begin() + index;
                }
                for (size_type i = 0; i < n; i++)
                    pos = insert(pos, val) + 1;
                return (pos);
            }
            template <class InputIterator>
		    iterator insert(iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value,InputIterator>::type* = 0)
		    {
                while(first != last)
                {
                    pos = insert(pos, *first) + 1;
                    first++;
                }
                return (pos);
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
            iterator erase(iterator first, iterator last)
            {
                size_type distance = last - first;
                for(size_type i = 0; last + i < this->end(); i++)
                    *(first + i) = *(last + i);
                for(size_type i = 0; i < distance; i++)
                    this->pop_back(); // gotta get rid of this
                return (first);
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
                std::swap(this->V, other.V);
                std::swap(this->alloc, other.alloc);
                std::swap(this->_capacity, other._capacity);
                std::swap(this->_size, other._size);
            }
            
            
            
        
    };
    
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& V1, const vector<T,Alloc>& V2)
    {
        if (V1.size() != V2.size())
            return false;
        for (size_t i = 0; i < V1.size(); i++)
        {
            if (V1[i] != V2[i])
                return false;
        }
        return true;
    }
	template <class T, class Alloc>
	bool operator != (const vector<T,Alloc>& V1, const vector<T,Alloc>& V2)
	{
		return (!(V1 == V2));
	}
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& V1, const vector<T,Alloc>& V2)
    {
        size_t i = 0;
        while (i < V1.size() && i < V2.size())
        {
            if (V1[i] < V2[i])
                return true;
            else if(V1[i] > V2[i])
                return false;
            i++;
        }
        if (i == V1.size() && i != V2.size())
            return true;
        return false;
    }
    template <class T, class Alloc>
    bool operator <= (const vector<T,Alloc>& V1, const vector<T,Alloc>& V2)
    {
        return V1 < V2 || V1 == V2;
    }
    template <class T, class Alloc>
    bool operator> (const vector<T, Alloc> & V1, const vector<T, Alloc> &V2)
    {
        return !(V1 <= V2);
    }
    template<class T, class Alloc>
    bool operator>= (const vector<T, Alloc> & V1, const vector<T, Alloc> &V2)
    {
        return !(V1 < V2);
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& V1, vector<T,Alloc>& V2)
    {
        V1.swap(V2);
    }
  
};

#endif