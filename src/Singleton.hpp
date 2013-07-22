#ifndef				SINGLETON_HPP_
# define			SINGLETON_HPP_

# include			<cstdlib>

class				GenericSingleton
{
public:
  GenericSingleton() {}
  ~GenericSingleton() {}
  GenericSingleton		&operator=(const GenericSingleton &other);
  GenericSingleton(const GenericSingleton &other);
};

template <typename T>
class				Singleton : public GenericSingleton
{
public:
  static T			&getInstance()
  {
    if (!that_)
      that_ = new T;
    return *that_;
  }

  static void			destroy()
  {
    if (that_)
      {
	delete that_;
	that_ = NULL;
      }
  }
protected:
  Singleton() {}
  ~Singleton() {}

private:
  Singleton 			&operator=(const Singleton &other);
  Singleton(const Singleton &other);

  static T			*that_;
};

template <typename T>
T				*Singleton<T>::that_ = NULL;

#endif				/* !SINGLETON_HPP_ */
