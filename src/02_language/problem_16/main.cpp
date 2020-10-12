// 16. Enumerating IPv4 addresses in a range
//
// Write a program that allows the user to input two IPv4 addresses representing
// a range and list all the addresses in that range. Extend the structure
// defined for the previous problem to implement the requested functionality.

#include <iostream>
#include <algorithm>
#include "Net.hpp"
#include "Range.hpp"

//------------------------------------------------------------------------------

// Print to stdout all valid IPv4 addresses between a and b, on a newline.
void print_ip_range(const ipv4& a, const ipv4& b);

//------------------------------------------------------------------------------

int main()
{

  // example usage
  ipv4 start{100, 0, 1, 1};
  ipv4 end{100, 255, 1, 1};

  // print_ip_range(start, end);
  std::cout << ++start << '\n';
  std::cout << end << '\n';
  return 0;
}

//------------------------------------------------------------------------------

void print_ip_range(const Ipv4& a, const Ipv4& b) {}
