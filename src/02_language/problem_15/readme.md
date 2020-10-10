# Problem 15 - IPv4 data type

## Description

Write a class that represents an IPv4 address. Implement the functions
required to be able to read and write such addresses from or to the console.
The user should be able to input values in dotted form, such
as 127.0.0.1 or 168.192.0.100. This is also the form in which IPv4 addresses
should be formatted to an output stream

## Todo

- [ ] add exception handler for bad input
- [ ] validate construction
- [x] overload `std::ostream`
- [x] overload `std::istream`
- [x] overload equality (==) operator
- [x] overload not equals (!=) operator

## Design

- internal data storage? std::array || std::vector??
  - int || unsigned char?
- How to validate an address?