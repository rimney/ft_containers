/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:04:12 by rimney            #+#    #+#             */
/*   Updated: 2023/02/01 18:56:11 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

#include "vector.hpp"
namespace ft
{
    template <bool b, class T>
    struct enable_if
    {
    
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
    template <class T>
    struct is_integral
    {
      static const bool value = false;  
    };
    template <>
    struct is_integral<int>
    {
      static const bool value = true;     
    };
    // template <>
    // struct is_integral<char>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<char16_t>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<char32_t>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<wchar_t>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<signed char>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<short int>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<long int>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<long long int>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<unsigned char>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<unsigned short int>
    // {
    //   static const bool value = true;     
    // };
    //  template <>
    // struct is_integral<unsigned int>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<unsigned long int>
    // {
    //   static const bool value = true;     
    // };
    // template <>
    // struct is_integral<unsigned long long int>
    // {
    //   static const bool value = true;     
    // };

}

#endif