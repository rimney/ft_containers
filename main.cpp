/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:13:59 by rimney            #+#    #+#             */
/*   Updated: 2023/01/18 21:37:06 by rimney           ###   ########.fr       */
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
    for(ft::vector<int>::iterator i = A.begin();i < A.end(); i++)
    {
        std::cout << *i << "<< \n";
    }
    A.erase(A.begin());
    for(ft::vector<int>::iterator i = A.begin();i < A.end(); i++)
    {
        std::cout << *i << "<< \n";
    }

    // system("leaks containers");
}

// void    capacity_test()
// {
//  ft::vector<int>::size_type sz;

//   ft::vector<int> foo;
//   sz = foo.capacity();
//   std::cout << "making foo grow:\n";
//   for (int i=0; i<100; ++i) {
//     foo.push_back(i);
//     if (sz!=foo.capacity()) {
//       sz = foo.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }

//   ft::vector<int> bar;
//   sz = bar.capacity();
//   bar.reserve(100);   // this is the only difference with foo above
//   std::cout << "making bar grow:\n";
//   for (int i=0; i<100; ++i) {
//     bar.push_back(i);
//     if (sz!=bar.capacity()) {
//       sz = bar.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }
// }

int main()
{
    ftft();
    return (0);
}