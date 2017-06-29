
#include <vector>
#include <iostream>

struct A
{
  int i;
  A(std::initializer_list<int> integers)
    : i(*integers.begin())
  {}

  template<typename T>
  T f(T t)
  { return t + 2; }

  virtual int virtual_f(int x)
  { return x; }
};

struct B: public A
{
  B(std::initializer_list<int> integers)
    : A(integers)
  { }

  virtual int virtual_f(double d) override
  { return 0; }
};

template<typename T, typename U>
auto f(T t, U u) -> decltype(t.f(u))
{
  return t.f(u);
}

int main(int argc, char **argv)
{
  A a({1,2,3});

  std::cout << a.i << std::endl;

  int j = 125;
  auto z = f(a, j);

  std::cout << z << std::endl;

  auto lambda = [](int x, int y) -> int { return x + y; };

  std::cout << lambda(2, 3) << std::endl;


  B b({0});

  std::cout << b.virtual_f((int)2) << std::endl;
  return 0;
}
