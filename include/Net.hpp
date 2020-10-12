#ifndef NET_H
#define NET_H

#include <array>
#include <string>
#include <sstream>
#include <iostream>

//------------------------------------------------------------------------------

class ipv4 {
private:
  std::array<int, 4> data;

public:
  ipv4() : data{0, 0, 0, 0} {} // default constructor
  ipv4(int a, int b, int c, int d);
  ipv4(std::string ip); // construct an address from a string

  friend inline bool operator==(const ipv4& lhs, const ipv4& rhs);

  friend std::ostream& operator<<(std::ostream& os, const ipv4& ip);
  // read an ipv4 from is into a
  friend std::istream& operator>>(std::istream& is, ipv4& ip);

  ipv4 operator++() // pre-increment
  {
    return ++(*this);
  }

  ipv4 operator--() // post-decrement
  {
    return --(*this);
  }
};

//------------------------------------------------------------------------------

ipv4::ipv4(int a, int b, int c, int d)
{
  // check that arguments are:
  // non-negative, <=255

  data = {a, b, c, d};
}

//------------------------------------------------------------------------------

ipv4::ipv4(std::string ip) // construct an address from a string
{
  std::istringstream ss{ip};
  int a, b, c, d;
  char ch1, ch2, ch3;
  ss >> a >> ch1 >> b >> ch2 >> c >> ch3 >> d;

  if (!ss) {
    std::cerr << "Construction from string failed: " << ip << '\n';
  }

  if (ch1 != '.' || ch2 != '.' || ch3 != '.') // check for format error
  {
    ss.clear(std::ios_base::failbit);
    std::cerr << "Construction from string failed: " << ip << '\n';
  }

  data = {a, b, c, d};
}

//------------------------------------------------------------------------------

inline bool operator==(const ipv4& lhs, const ipv4& rhs)
{
  if (lhs.data.size() != rhs.data.size())
    return false;

  for (int i = 0; i != lhs.data.size(); ++i) {
    if (lhs.data[i] != rhs.data[i])
      return false;
  }

  return true;
}

inline bool operator!=(const ipv4& lhs, const ipv4& rhs) { return !(lhs == rhs); }

//------------------------------------------------------------------------------

std::ostream& operator<<(std::ostream& os, const ipv4& a) { return os << a.data[0] << '.' << a.data[1] << '.' << a.data[2] << '.' << a.data[3]; }

inline std::istream& operator>>(std::istream& is, ipv4& ip)
{
  int a, b, c, d;
  char ch1, ch2, ch3; // period symbols between each int
  is >> a >> ch1 >> b >> ch2 >> c >> ch3 >> d;
  if (!is)
    return is;

  if (ch1 != '.' || ch2 != '.' || ch3 != '.') // check for format error
  {
    is.clear(std::ios_base::failbit);
    return is;
  }

  ip = ipv4{a, b, c, d}; // update a
  return is;
}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------

#endif // NET_H