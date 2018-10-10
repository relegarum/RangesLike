#pragma once
#include <algorithm>

namespace like
{
  template< typename PredicateT >
  struct Filter
  {
    constexpr Filter(PredicateT predicate)
      : m_predicate(std::move(predicate))
    {
    }

    PredicateT m_predicate;
  };


  template< class ContainerT, class PredicateT >
  ContainerT operator|(const ContainerT& container, Filter< PredicateT > filter)
  {
    ContainerT aux;
    std::copy_if(std::begin(container), std::end(container), std::back_inserter(aux), filter.m_predicate);
    return aux;
  }
}
