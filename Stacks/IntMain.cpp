#include <cstdlib>
#include <iostream>

#include "IntStack.hpp"

using namespace std;

int main(int argc, char *argv[])
{
  IntStack myStack;

  for (int argIndex=1; argIndex<argc; argIndex++)
    {
      myStack.push ( atoi(argv[argIndex])  );
    }

  cout << "Top of stack is :" << myStack.top() << endl;

  cout << "The stack is:" << endl;
  while ( !myStack.isEmpty() )
    {
      int val = myStack.pop();
      cout << val << endl;
    }

  return 0;
}
