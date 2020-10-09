// 15. IPv4 data type
//
// Write a class that represents an IPv4 address. Implement the functions
// required to be able to read and write such addresses from or to the console.
// The user should be able to input values in dotted form, such
// as 127.0.0.1 or 168.192.0.100. This is also the form in which IPv4 addresses
// should be formatted to an output stream

#include <array>
#include <cstdint>
#include <iostream>
#include "Net.hpp"

//------------------------------------------------------------------------------

int main()
{
  // std::cout << "Enter an IPv4 address (hit enter to confirm): ";
  ipv4 ip_int{192, 0, 0, 255}; // construct from 4 integers
  // ipv4 ip_str{"255.255.255.1"}; // construct from std::string
  // Net::ipv4 ip_cpy = ip_int;         // copy construction

  // std::cin >> my_ip;
  std::cout << "ip_int: " << ip_int << '\n';

  return 0;
}