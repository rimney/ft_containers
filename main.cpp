/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:13:59 by rimney            #+#    #+#             */
/*   Updated: 2023/01/17 21:43:16 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"

int main()
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
    
    for(ft::vector<int>::reverse_iterator i = A.rbegin();i < A.rend(); i++)
    {
        // std::cout << i[index] << "<<<< \n"; ?? 
        std::cout << *i << "<< \n";
    }
    ft::vector<int> C(A.begin(), A.end());
    system("leaks containers");
}