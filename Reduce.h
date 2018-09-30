#pragma once
#include <numeric>

template< class PredicateT >
struct Reduce
{
  constexpr Reduce(PredicateT predicate)
  : m_predicate(predicate)
  {
  }

  PredicateT m_predicate;
};


template< class ContainerT, class PredicateT >
typename ContainerT::value_type operator|(const ContainerT& container, Reduce< PredicateT > reduce)
{
  return std::accumulate(std::begin(container), std::end(container), typename ContainerT::value_type(), reduce.m_predicate);
}
