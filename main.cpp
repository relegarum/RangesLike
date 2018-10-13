#include <algorithm>
#include <vector>
#include <iostream>

#include "Filter.h"
#include "Map.h"
#include "Reduce.h"
#include "Sort.h"

template< class T >
std::ostream& operator<<(std::ostream& os, const std::vector<T>& container)
{
  for( const auto item : container )
  {
    os  << item << ' ';
  }

  return os;
}

int main()
{
  std::vector<int> sample = {1, 5, 7, 9, 2, 6, 3,  8, 4, 10};
  std::cout << sample << '\n';

  const auto sorted = sample | like::Sort();
  std::cout << sorted << '\n';

  const auto filtered = sorted | like::Filter([]( const int item ){ return ((item % 2) == 0); });
  std::cout << filtered << '\n';

  const auto powers = filtered | like::Map([]( const int item ){ return item * item; });
  std::cout << powers << '\n';

  const auto sum = powers | like::Reduce([]( const int left, const int right ){ return left + right; }, 0); 
  std::cout << sum << '\n';
  return 0;
}
