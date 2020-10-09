#ifndef NET_H
#define NET_H

#include <array>
#include <string>
#include <iostream>

//------------------------------------------------------------------------------

class ipv4 {
private:
  std::array<unsigned char, 4> data;

public:
  ipv4(int a, int b, int c, int d);
  ipv4(const std::string a); // construct an address from a string

  // print a to os
  friend std::ostream& operator<<(std::ostream& os, const ipv4& a);
  // read an ipv4 from is into a
  friend std::istream& operator>>(std::istream& is, const ipv4& a);
};

//------------------------------------------------------------------------------

ipv4::ipv4(int a, int b, int c, int d)
{
  // check that arguments are:
  // non-negative
  // <=255
  data = {static_cast<unsigned char>(a), static_cast<unsigned char>(b),
          static_cast<unsigned char>(c), static_cast<unsigned char>(d)};
}

//------------------------------------------------------------------------------

ipv4::ipv4(const std::string a) // construct an address from a string
{
}

//------------------------------------------------------------------------------

bool operator==(const ipv4& a, const ipv4& b);
bool operator!=(const ipv4& a, const ipv4& b);

//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const ipv4& a)
{
  // TODO: use static_cast or find a better solution
  return os << a.data[0] << '.' << a.data[1] << '.' << a.data[2] << '.'
            << a.data[3];
}

//------------------------------------------------------------------------------

#endif // NET_H