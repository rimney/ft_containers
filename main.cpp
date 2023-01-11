/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney <rimney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:13:59 by rimney            #+#    #+#             */
/*   Updated: 2023/01/12 00:05:16 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector/vector.hpp"

int main()
{
    ft::vector <int> B(5, 10);
    for(int i = 0; (size_t)i < B.size(); i++)
    {
        std::cout << B[i] << std::endl;
    }
    // system("leaks a.out");
    // ft::vector<int> A(B.begin(), B.end());
    // for (int i = 0; i < A.size(); ++i)
    //   A[i] = i + 1;
    // // ft::vector<int> B(A.begin(), A.end());
}