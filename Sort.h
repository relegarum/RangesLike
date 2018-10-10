#pragma once
#include <algorithm>
#include <functional>

namespace like
{
  struct Sort
  {
  };

  template< class ContainerT >
  constexpr ContainerT operator|(const ContainerT container, const Sort&)
  {
    ContainerT aux = container;
    std::sort(std::begin(aux), std::end(aux));
    return aux;
  }

}
