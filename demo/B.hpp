#ifndef					B_HH_
# define				B_HH_

# include				"Singleton.hpp"

# include			<iostream>

class					B : public Singleton<B>
{
  friend class Singleton<B>;

public:
  B() {}
  ~B() {}

  B(const B &other);
  B					&operator=(const B &other);

  void				hello()
  {
    std::cout << "HELLO FROM B" << std::endl;
  }

protected:

private:

};

#endif					/* !B_HH_ */
