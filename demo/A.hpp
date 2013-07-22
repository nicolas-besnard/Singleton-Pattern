#ifndef					A_HPP_
# define				A_HPP_

# include				"Singleton.hpp"

# include			<iostream>

class					A : public Singleton<A>
{
  friend class Singleton<A>;

public:
  A() {}
  ~A() {}

  A(const A &other);
  A					&operator=(const A &other);

  void				hello()
  {
    std::cout << "HELLO" << std::endl;
  }

protected:

private:

};

#endif					/* !A_HPP_ */
