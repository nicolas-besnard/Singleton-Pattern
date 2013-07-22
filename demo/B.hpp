#ifndef					B_HH_
# define				B_HH_

# include				"Singleton.hpp"

# include			<iostream>

class					B : public Singleton<B>
{
  friend class Singleton<B>;

public:
  void				hello()
  {
    std::cout << "HELLO FROM B" << std::endl;
  }

protected:

private:
  B() {}
  ~B() {}

  B(const B &other);
  B					&operator=(const B &other);
};

#endif					/* !B_HH_ */
