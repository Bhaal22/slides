#include <iostream>

struct A
{
  void f(int i)
  {
    std::cout << i << std::endl;
  }

  void f(int *p)
  {
    if (p != nullptr)
      std::cout << *p << std::endl;
    else
      std::cout << "nullptr" << std::endl;
  }
};

int main(int argc, char **argv)
{
  A a;

  a.f(0);
  //a.f(NULL);
  a.f(nullptr);
  return 0;
}
