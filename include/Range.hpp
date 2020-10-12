#ifndef RANGE_H
#define RANGE_H

#include <iterator>

template<long From, long To> class Range {
public:
  // member types inherited via std::iterator
  class iterator : public std::iterator<std::input_iterator_tag, // iterator category
                                        long,                    // value_type
                                        long,                    // difference_type
                                        const long*,             // pointer
                                        long                     // reference
                                        > {
    long num = From;

  public:
    explicit iterator(long nn = 0) : num{nn} {}

    iterator& operator++()
    {
      num = To >= From ? num + 1 : num - 1;
      return *this;
    }

    iterator operator++(int)
    {
      iterator return_val = *this;
      ++(*this);
      return return_val;
    }

    bool operator==(iterator other) const { return num == other.num; }
    bool operator!=(iterator other) const { return !(*this == other); }
    reference operator*() const { return num; }
  };

  iterator begin() { return iterator(From); }
  iterator end() { return iterator(To >= From ? To + 1 : To - 1); }
};

#endif // RANGE_H