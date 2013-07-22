#include			"SingletonManager.hpp"
#include			"A.hpp"
#include			"B.hpp"

int				main(void)
{
  SingletonManager::add<A>();
  SingletonManager::add<B>();
  SingletonManager::get<A>().hello();
  SingletonManager::get<B>().hello();
  return (0);
}
