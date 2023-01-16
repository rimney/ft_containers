/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:06:07 by rimney            #+#    #+#             */
/*   Updated: 2023/01/16 16:52:09 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP
// #include "iterators.hpp"
// class Iterator;
namespace ft
{
    template <class Iterator>
    class IteratorTraits
    {
        public :
            typedef typename Iterator::iterator_category iterator_category;
            typedef typename Iterator::value_type value_type;
            typedef typename Iterator::difference_type difference_type;
            typedef typename Iterator::pointer pointer;
            typedef typename Iterator::reference reference;
            IteratorTraits() {}
            ~IteratorTraits() {}
            

    };
}

#endif