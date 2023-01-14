/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:25:25 by rimney            #+#    #+#             */
/*   Updated: 2023/01/14 21:06:11 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATORS_HPP
# define ITERATORS_HPP
# include "iterator_traits.hpp"
# include <cstddef>
# include <iostream>

namespace ft
{
    template < class category, class T, class distance = std::ptrdiff_t, class pointer = T* , class reference = T& >
    class iterator
    {
        public :
            typedef T value_type;
            typedef distance difference_type;
            typedef pointer Pointer;
            typedef reference Reference;
            typedef category Category;
    };
}


#endif