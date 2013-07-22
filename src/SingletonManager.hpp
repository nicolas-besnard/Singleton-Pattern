#ifndef					SINGLETONMANAGER_HPP_
# define				SINGLETONMANAGER_HPP_

# include				<string>
# include				<map>
# include				<typeinfo>

# include				"Singleton.hpp"

class					SingletonManager
  : public Singleton<SingletonManager>
{
  friend class Singleton<SingletonManager>;

  typedef std::map<std::string, GenericSingleton *>	SingletonMap;

public:
  template <typename T>
  void					add()
  {
    collection_[typeid(T).name()] = new T;
  }

  template <typename T>
  T					&get()
  {
    GenericSingleton			&tmp = *collection_[typeid(T).name()];
    return reinterpret_cast<T &>(tmp);
  }


private:
  SingletonManager() {}
  ~SingletonManager() {}
  SingletonManager			&operator=(const SingletonManager &other);
  SingletonManager(const SingletonManager &other);

  SingletonMap				collection_;
};

#endif					/* !SINGLETONMANAGER_HPP_ */
