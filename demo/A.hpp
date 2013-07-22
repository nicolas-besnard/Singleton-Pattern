#ifndef					A_HPP_
# define				A_HPP_

# include				"Singleton.hpp"

# include			<iostream>

class					A : public Singleton<A>
{
  friend class Singleton<A>;

public:
  void				hello()
  {
    std::cout << "HELLO FROM A" << std::endl;
  }

protected:

private:
  A() {}
  ~A() {}

  A(const A &other);
  A					&operator=(const A &other);
};

#endif					/* !A_HPP_ */
