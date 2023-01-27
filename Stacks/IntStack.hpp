#define _INT_STACK_HPP_
#define _INT_STACK_HPP_

#include <list>

class IntStack : private std::list<int>
{
public:
  IntStack() {}

  int top() const;
  int pop();
  void push(int newValue);
  bool isEmpty() const;
};
