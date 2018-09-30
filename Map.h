#pragma once
#include <algorithm>

template< class PredicateT >
struct Map
{
  constexpr Map(PredicateT predicate)
  :m_predicate(std::move(predicate))
  {
  }

  PredicateT m_predicate;
};


template< class ContainerT, class PredicateT >
constexpr ContainerT operator|(const ContainerT container, Map< PredicateT > map)
{
  ContainerT aux;
  std::transform(std::begin(container), std::end(container), std::back_inserter(aux), map.m_predicate);
  return aux;
}
