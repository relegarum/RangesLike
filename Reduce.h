#pragma once
#include <numeric>
#include <type_traits>


namespace like
{
  template< class PredicateT, class StartT >
  struct Reduce
  {
    using value_type = StartT;
    constexpr Reduce(PredicateT predicate, StartT start = StartT())
      : m_predicate(std::move(predicate)),
      m_start(start)
    {
    }

    PredicateT m_predicate;
    StartT m_start;
  };


  template< class ContainerT, class PredicateT, class StartT = typename ContainerT::value_type >
  typename ContainerT::value_type operator|( const ContainerT& container,
                                             Reduce< PredicateT, StartT > reduce )
  {
    return std::accumulate(std::begin(container), std::end(container), reduce.m_start, reduce.m_predicate);
  }
}
