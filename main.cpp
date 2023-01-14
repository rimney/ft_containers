/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:13:59 by rimney            #+#    #+#             */
/*   Updated: 2023/01/14 21:13:04 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"

int main()
{
    ft::vector <int> B(5, 10);
    ft::vector <int> C = B;
    // ft::vector<int>::iterator I = B.begin();
    ft::vector<int>::iterator i = B.begin();
    std::cout << *i  << std::endl;
    // exit(0);
    for(int i = 0; (size_t)i < C.size(); i++)
    {
        std::cout << C[i] << std::endl;
    }
    std::cout << C.at(1) << '\n';
    // system("leaks containers"); 
    // ft::vector<int> A(B.begin(), B.end());
    // for (int i = 0; i < A.size(); ++i)
    //   A[i] = i + 1;
    // // ft::vector<int> B(A.begin(), A.end());
}