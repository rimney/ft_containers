/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimney < rimney@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:13:59 by rimney            #+#    #+#             */
/*   Updated: 2023/01/20 00:59:49 by rimney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"

// void ftft()
// {
//     ft::vector<int> A;
//     // for(ft::vector<int>::iterator i = A.begin();i < A.end(); i++)
//     // {
//     //     // std::cout << i[index] << "<<<< \n"; ?? 
//     //     std::cout << *i << "<< \n";
//     // }

//     A.push_back(1);
//     A.push_back(2);
//     A.push_back(3);
//     A.push_back(4);
//     A.push_back(5);
//     A.push_back(6);
//     ft::vector<int> S(A.begin(), A.end());
//     // for(ft::vector<int>::iterator i = A.begin();i < A.end(); i++)
//     // {
//     //     std::cout << *i << "<< \n";
//     // }
//     // std::cout << "////\n";
//     // A.erase(A.begin());
//     // A.resize(12, 10);
//     A.pop_back();
//     A.pop_back();
//     A.pop_back();
//     A.pop_back();
 
//     for(ft::vector<int>::iterator i = A.begin();i < A.end(); i++)
//     {
//         std::cout << *i << "<< \n";
//     }
//     ft::vector<int> T(A.begin(), A.end());

//     // system("leaks containers");
// }

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

// int main()
// {
//     ftft();
    
//     return (0);
// }

int main ()
{
  ft::vector<int> foo (3,100);   // three ints with a value of 100
  ft::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    std::cout << ' ' << foo[i];
  std::cout << '\n';

  std::cout << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    std::cout << ' ' << bar[i];
  std::cout << '\n';

  return 0;
}