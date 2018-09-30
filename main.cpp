#include <algorithm>
#include <vector>
#include <iostream>

#include "Filter.h"
#include "Map.h"
#include "Reduce.h"

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
  std::vector<int> sample = {1, 2, 3, 4, 5, 6, 7,  8, 9, 10};
  std::cout << sample << '\n';

  auto filtered = sample | Filter([]( const int item ){ return ((item % 2) == 0); });
  std::cout << filtered << '\n';

  auto powers = filtered | Map([]( const int item ){ return item * item; });
  std::cout << powers << '\n';

  auto sum = powers | Reduce([]( const int left, const int right ){ return left + right; }, 0); 
  std::cout << sum << '\n';
  return 0;
}
