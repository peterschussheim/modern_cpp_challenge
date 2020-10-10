// 15. IPv4 data type
//
// Write a class that represents an IPv4 address. Implement the functions
// required to be able to read and write such addresses from or to the console.
// The user should be able to input values in dotted form, such
// as 127.0.0.1 or 168.192.0.100. This is also the form in which IPv4 addresses
// should be formatted to an output stream

#include <iostream>
#include "Net.hpp"

//------------------------------------------------------------------------------

int main()
{
  // read an ipv4 from cin
  std::cout << "Enter an IPv4 address (hit enter to confirm): ";
  ipv4 ip_user;
  std::cin >> ip_user;

  ipv4 ip_int{192, 0, 0, 255};  // construct from 4 integers
  ipv4 ip_str{"255.255.255.1"}; // construct from std::string

  // test operator==()
  ipv4 ip_equals{127, 1, 1, 255};
  ipv4 ip_equals_2{127, 1, 1, 255};
  bool equality_test = ip_equals == ip_equals_2;

  // test operator!=()
  bool unequal_test = ip_int != ip_equals;

  std::cout << "You entered: " << ip_user << '\n';
  std::cout << "Construct from 4 integers: " << ip_int << '\n';
  std::cout << "Construct from a formatted string: " << ip_str << '\n';
  std::cout << "operator==(): " << equality_test << '\n';
  std::cout << "operator!=(): " << unequal_test << '\n';

  return 0;
}

//------------------------------------------------------------------------------