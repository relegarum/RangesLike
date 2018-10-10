#pragma once
#include <algorithm>
#include <functional>

namespace like
{
  //template< class PredicateT >
  struct Sort
  {
/*    constexpr Sort(PredicateT predicate)*/
      //:m_predicate(std::move(predicate))
    //{
    //}

    /*PredicateT m_predicate;*/
  };


  template< class ContainerT >
  constexpr ContainerT operator|(const ContainerT container, const Sort&)
  {
    ContainerT aux = container;
    std::sort(std::begin(aux), std::end(aux));
    return aux;
  }

}
