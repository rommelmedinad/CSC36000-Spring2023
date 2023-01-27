#include "IntStack.hpp"

using namespace std;

int
IntStack::top() const
{
  return list<int>::front();
}

int
IntStack::pop()
{
  int answer = top();
  list<int>::pop_front();
  return answer;
}

void
IntStack::push(int newValue)
{
  list<int>::push_front(newValue);
}

bool
IntStack::isEmpty() const
{
  return list<int>::empty(); 
}
