/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:13:59 by rimney            #+#    #+#             */
/*   Updated: 2023/01/17 19:23:59 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"

int main()
{
    ft::vector<int> A(10, 1);
    // for(ft::vector<int>::reverse_iterator i = A.rbegin();i < A.rend(); i++)
    // {
    //     // std::cout << i[index] << "<<<< \n"; ?? 
    //     std::cout << *i << "<< \n";
    // }
    // for(ft::vector<int>::iterator i = A.begin();i < A.end(); i++)
    // {
    //     // std::cout << i[index] << "<<<< \n"; ?? 
    //     std::cout << *i << "<< \n";
    // }

    A.push_back(5);
    
}