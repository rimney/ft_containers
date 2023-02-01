/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:25:25 by rimney            #+#    #+#             */
/*   Updated: 2023/02/01 18:53:14 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP
# include "iterator_traits.hpp"
# include <cstddef>
# include <iostream>

namespace ft
{
    template <class T>
    class Iterator
    {
        public :
            typedef typename ft::IteratorTraits<T*>::difference_type difference_type;
            typedef typename ft::IteratorTraits<T*>::value_type value_type;
            typedef typename ft::IteratorTraits<T*>::iterator_category Category;
            typedef typename ft::IteratorTraits<T*>::pointer pointer;
            typedef typename ft::IteratorTraits<T*>::reference reference;
            Iterator() {}
            ~Iterator() {}
    };
}


#endif