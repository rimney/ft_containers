/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:13:59 by rimney            #+#    #+#             */
/*   Updated: 2023/01/18 03:09:11 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"

void ftft()
{
    ft::vector<int> A;
    // for(ft::vector<int>::iterator i = A.begin();i < A.end(); i++)
    // {
    //     // std::cout << i[index] << "<<<< \n"; ?? 
    //     std::cout << *i << "<< \n";
    // }

    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);
    
    // ft::vector<int> C(A.begin(), A.end());
    A.assign(5, 5);
    for(ft::vector<int>::iterator i = A.begin();i < A.end(); i++)
    {
        // std::cout << i[index] << "<<<< \n"; ?? 
        std::cout << *i << "<< \n";
    }
    // system("leaks containers");
}

int main()
{
    ftft();
    system("leaks containers");
    return (0);
}