#ifndef					SINGLETONMANAGER_HPP_
# define				SINGLETONMANAGER_HPP_

# include				<string>
# include				<map>
# include				<typeinfo>
# include				<algorithm>

# include				"Singleton.hpp"


#include			<iostream>


class					SingletonManager
  : public Singleton<SingletonManager>
{
  friend class Singleton<SingletonManager>;

public:
  typedef std::map<std::string, GenericSingleton *>	SingletonMap;
  typedef SingletonMap::iterator			SingletonMapIT;
  typedef SingletonMap::const_iterator			SingletonMapConstIT;

public:
  template <typename T>
  static void				add()
  {
    SingletonManager			&manager = SingletonManager::getInstance();

    manager.doAdd<T>();
  }

  template <typename T>
  void					doAdd()
  {
    if (collection_.find(typeid(T).name()) == collection_.end())
      collection_[typeid(T).name()] = new T;
  }

  template <typename T>
  static T				&get()
  {
    SingletonManager			&manager = SingletonManager::getInstance();

    return manager.doGet<T>();
  }

  template <typename T>
  T					&doGet()
  {
    GenericSingleton			&tmp = *collection_[typeid(T).name()];
    return reinterpret_cast<T &>(tmp);
  }

  void					removeCollection()
  {
    SingletonMapIT			actualSingleton;
    SingletonMapIT			lastSingleton;

    for (; actualSingleton != lastSingleton; ++actualSingleton)
      delete (*actualSingleton).second;
  }

private:
  SingletonManager() {}
  ~SingletonManager() {}
  SingletonManager			&operator=(const SingletonManager &other);
  SingletonManager(const SingletonManager &other);

  SingletonMap				collection_;
};


#endif					/* !SINGLETONMANAGER_HPP_ */
