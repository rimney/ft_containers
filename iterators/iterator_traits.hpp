/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:06:07 by rimney            #+#    #+#             */
/*   Updated: 2023/01/14 21:01:01 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TREATS_HPP
# define ITERATOR_TREATS_HPP

namespace ft
{
    template <class iterator>
    class IteratorTraits
    {
        public :
            typedef typename iterator::iterator_category iterator_category;
            typedef typename iterator::value_type value_type;
            typedef typename iterator::difference_type difference_type;
            typedef typename iterator::Pointer pointer;
            typedef typename iterator::reference reference;
    };
}

#endif