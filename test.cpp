/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:13:59 by rimney            #+#    #+#             */
/*   Updated: 2023/01/18 00:03:58 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include <iostream>
void ftft()
{
    std::vector<int> A;
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
    
    std::vector<int> C(A.begin(), A.end());
    C.assign(5, 5);
    for(std::vector<int>::reverse_iterator i = C.rbegin();i < C.rend(); i++)
    {
        // std::cout << i[index] << "<<<< \n"; ?? 
        std::cout << *i << "<< \n";
    }
    // system("leaks containers");
}

int main()
{
    ftft();
    return (0);
}