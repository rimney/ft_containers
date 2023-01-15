/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:50:51 by rimney            #+#    #+#             */
/*   Updated: 2023/01/15 17:10:28 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <iterator>

int main()
{
    std::vector<int> A(10, 15);
    for(std::vector<int>::iterator i = A.begin();i < A.end(); i++)
    {
        // std::cout << i[index] << "<<<< \n"; ?? 
        std::cout << *i << "<< \n";
    }
}