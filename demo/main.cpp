#include			"SingletonManager.hpp"
#include			"A.hpp"

int				main(void)
{
  SingletonManager::getInstance().add<A>();
  SingletonManager::getInstance().get<A>().hello();
  return (0);
}
